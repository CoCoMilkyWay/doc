#!/usr/bin/env bash
set -euo pipefail

# 全部路径相对脚本所在目录,文件夹可任意移动
DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$DIR"

DISK=disk.qcow2
CODE=OVMF_CODE_4M.fd
VARS=OVMF_VARS_4M.fd
SHARED=shared
VFS_SOCK=.virtiofs.sock
MEM=8G
XRES=1920
YRES=1080

shopt -s nullglob
# 附加光驱(可选): virtio 驱动盘、WinFSP 安装盘
DRIVER_ISO=""; for f in virtio-win*.iso; do DRIVER_ISO="$f"; break; done
WINFSP_ISO=""; for f in winfsp*.iso;     do WINFSP_ISO="$f"; break; done

# 主 ISO: 目录里除附加光驱外唯一的 .iso
isos=()
for f in *.iso; do
  [[ "$f" == "$DRIVER_ISO" || "$f" == "$WINFSP_ISO" ]] && continue
  isos+=("$f")
done
(( ${#isos[@]} == 1 )) || { echo "需要恰好 1 个 Windows 安装 ISO,当前 ${#isos[@]} 个: ${isos[*]-无}"; exit 1; }
ISO="${isos[0]}"

pkgs=()
command -v qemu-system-x86_64 >/dev/null || pkgs+=(qemu-system-x86)
command -v qemu-img >/dev/null           || pkgs+=(qemu-utils)
dpkg -s qemu-system-gui >/dev/null 2>&1  || pkgs+=(qemu-system-gui)  # -display gtk
dpkg -s qemu-system-modules-spice >/dev/null 2>&1 || pkgs+=(qemu-system-modules-spice)  # -display spice-app
command -v remote-viewer >/dev/null      || pkgs+=(virt-viewer)      # spice 客户端
command -v pipewire >/dev/null           || pkgs+=(pipewire)         # -audiodev pipewire
command -v newuidmap >/dev/null          || pkgs+=(uidmap)           # virtiofsd 沙箱

# virtio-fs 后端,不在 PATH 里
VIRTIOFSD=""
for p in /usr/libexec/virtiofsd /usr/lib/qemu/virtiofsd virtiofsd; do
  if command -v "$p" >/dev/null 2>&1; then VIRTIOFSD="$p"; break; fi
done
[ -n "$VIRTIOFSD" ] || pkgs+=(virtiofsd)

(( ${#pkgs[@]} == 0 )) || {
  echo "缺少依赖包: ${pkgs[*]}"
  echo "安装: sudo apt install ${pkgs[*]}"
  exit 1
}

[ -e /dev/kvm ] || {
  echo "无 /dev/kvm,需要加载 kvm 模块: sudo modprobe kvm_intel  # 或 kvm_amd"
  exit 1
}
[ -r /dev/kvm ] && [ -w /dev/kvm ] || {
  echo "无 /dev/kvm 权限,加入 kvm 组后重新登录:"
  echo "  sudo usermod -aG kvm \"\$USER\""
  exit 1
}
[ -f "$CODE" ] && [ -f "$VARS" ] || {
  echo "缺少 OVMF 固件: $CODE / $VARS"
  echo "可从包 ovmf 复制,或放到脚本目录:"
  echo "  sudo apt install ovmf"
  echo "  cp /usr/share/OVMF/OVMF_CODE_4M.fd $CODE"
  echo "  cp /usr/share/OVMF/OVMF_VARS_4M.fd $VARS"
  exit 1
}

mkdir -p "$SHARED"

# 共享文件夹后端;客机内 root 映射到当前用户,文件归属才正确
rm -f "$VFS_SOCK"
"$VIRTIOFSD" --socket-path="$VFS_SOCK" --shared-dir "$SHARED" --cache=auto \
  --uid-map ":0:$(id -u):1:" --gid-map ":0:$(id -g):1:" &
VFS_PID=$!
trap 'kill "$VFS_PID" 2>/dev/null; rm -f "$VFS_SOCK"' EXIT

for _ in $(seq 50); do
  [ -S "$VFS_SOCK" ] && break
  sleep 0.1
done
[ -S "$VFS_SOCK" ] || { echo "virtiofsd 启动失败"; exit 1; }

# 首次运行自动创建 80G 稀疏磁盘(实际按需占用)
[ -f "$DISK" ] || qemu-img create -f qcow2 "$DISK" 80G

# 磁盘还是空的(实际占用 <64M)则光盘优先,直接进安装程序;
# 装完系统后磁盘有数据,自动变为硬盘优先
if [ "$(du -m "$DISK" | cut -f1)" -lt 64 ]; then
  HDD_BOOT=2; CD_BOOT=1
else
  HDD_BOOT=1; CD_BOOT=2
fi

# 附加光驱: bootindex 排在硬盘和安装盘之后
CD_ARGS=()
if [ -n "$DRIVER_ISO" ]; then
  CD_ARGS+=(
    -drive id=viocd,file="$DRIVER_ISO",format=raw,media=cdrom,if=none,readonly=on
    -device ide-cd,drive=viocd,bus=ahci.2,bootindex=3
  )
else
  echo "提示: 缺 virtio-win*.iso,Windows 分辨率会锁死。下载后放到脚本目录:"
  echo "  https://fedorapeople.org/groups/virt/virtio-win/direct-downloads/stable-virtio/virtio-win.iso"
fi
if [ -n "$WINFSP_ISO" ]; then
  CD_ARGS+=(
    -drive id=winfspcd,file="$WINFSP_ISO",format=raw,media=cdrom,if=none,readonly=on
    -device ide-cd,drive=winfspcd,bus=ahci.3,bootindex=4
  )
else
  echo "提示: 缺 winfsp*.iso,Windows 里 VirtioFS 服务起不来,共享文件夹不可见。"
fi

# GDK_SCALE=1: 防桌面 HiDPI 缩放,保证 1:1 像素
export GDK_SCALE=1 GDK_DPI_SCALE=1
qemu-system-x86_64 \
  -name "Win10-VM" \
  -machine q35,accel=kvm,memory-backend=mem \
  -uuid 8888895c-14df-434b-9fbb-7c786d455e63 \
  -smbios "type=1,manufacturer=Chuyin,product=Win10VM,serial=BCCCEA3FA0B3" \
  -cpu host \
  -smp 4 \
  -m "$MEM" \
  -object memory-backend-memfd,id=mem,size="$MEM",share=on \
  -drive if=pflash,format=raw,readonly=on,file="$CODE" \
  -drive if=pflash,format=raw,file="$VARS" \
  -device ich9-ahci,id=ahci \
  -drive id=hdd,file="$DISK",format=qcow2,if=none \
  -device ide-hd,drive=hdd,bus=ahci.0,bootindex=$HDD_BOOT \
  -drive id=cd,file="$ISO",format=raw,media=cdrom,if=none,readonly=on \
  -device ide-cd,drive=cd,bus=ahci.1,bootindex=$CD_BOOT \
  "${CD_ARGS[@]}" \
  -nic user,model=e1000 \
  -chardev socket,id=char0,path="$VFS_SOCK" \
  -device vhost-user-fs-pci,queue-size=1024,chardev=char0,tag=myfs \
  -device qemu-xhci \
  -device usb-tablet \
  -device virtio-vga,xres="$XRES",yres="$YRES" \
  -display gtk,gl=off,zoom-to-fit=off \
  -audiodev pipewire,id=snd \
  -device ich9-intel-hda \
  -device hda-duplex,audiodev=snd \
  -rtc base=localtime
