#!/usr/bin/env bash
set -euo pipefail

# 全部路径相对脚本所在目录,文件夹可任意移动
DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

ISO="$DIR/Win10_22H2_English_x64v1.iso"
DISK="$DIR/disk.qcow2"
CODE="$DIR/OVMF_CODE_4M.fd"
VARS="$DIR/OVMF_VARS_4M.fd"

command -v qemu-system-x86_64 >/dev/null || { echo "缺少 qemu-system-x86_64"; exit 1; }
[ -x /usr/sbin/smbd ]                    || { echo "缺少 smbd(共享文件夹需要): sudo apt install samba"; exit 1; }
[ -r /dev/kvm ] && [ -w /dev/kvm ]       || { echo "无 /dev/kvm 权限"; exit 1; }
[ -f "$ISO" ]                            || { echo "缺少 ISO: $ISO"; exit 1; }
[ -f "$CODE" ] && [ -f "$VARS" ]         || { echo "缺少 OVMF 固件文件"; exit 1; }

# 首次运行自动创建 80G 稀疏磁盘(实际按需占用)
[ -f "$DISK" ] || qemu-img create -f qcow2 "$DISK" 80G

# 磁盘还是空的(实际占用 <64M)则光盘优先,直接进安装程序;
# 装完系统后磁盘有数据,自动变为硬盘优先
if [ "$(du -m "$DISK" | cut -f1)" -lt 64 ]; then
  HDD_BOOT=2; CD_BOOT=1
else
  HDD_BOOT=1; CD_BOOT=2
fi
exec qemu-system-x86_64 \
  -name "Win10-22H2" \
  -machine q35,accel=kvm \
  -uuid 8888895c-14df-434b-9fbb-7c786d455e63 \
  -smbios "type=1,manufacturer=Chuyin,product=Win10VM,serial=BCCCEA3FA0B3" \
  -cpu host \
  -smp 4 \
  -m 8G \
  -drive if=pflash,format=raw,readonly=on,file="$CODE" \
  -drive if=pflash,format=raw,file="$VARS" \
  -device ich9-ahci,id=ahci \
  -drive id=hdd,file="$DISK",format=qcow2,if=none \
  -device ide-hd,drive=hdd,bus=ahci.0,bootindex=$HDD_BOOT \
  -drive id=cd,file="$ISO",format=raw,media=cdrom,if=none,readonly=on \
  -device ide-cd,drive=cd,bus=ahci.1,bootindex=$CD_BOOT \
  -nic user,model=e1000,smb="$DIR/shared" \
  -device qemu-xhci \
  -device usb-tablet \
  -device virtio-vga,xres=1920,yres=1080 \
  -display gtk \
  -audiodev pipewire,id=snd \
  -device ich9-intel-hda \
  -device hda-duplex,audiodev=snd \
  -rtc base=localtime
