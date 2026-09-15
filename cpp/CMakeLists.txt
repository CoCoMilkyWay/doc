cmake_minimum_required(VERSION 3.20)
project(docpipe CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()
# 断言是本项目唯一的错误处理手段, Release 也必须保留
string(REPLACE "-DNDEBUG" "" CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}")
string(REPLACE "-DNDEBUG" "" CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO}")

find_package(Threads REQUIRED)

# PDF 解析依赖 libpoppler-cpp, 缺了直接在配置期失败
find_package(PkgConfig REQUIRED)
pkg_check_modules(POPPLER_CPP IMPORTED_TARGET poppler-cpp)
if(NOT POPPLER_CPP_FOUND)
  message(FATAL_ERROR "缺少 libpoppler-cpp, 请安装: sudo apt install libpoppler-cpp-dev")
endif()

add_library(docpipe_core STATIC
  src/common/util.cpp
  src/common/fs.cpp
  src/common/proc.cpp
  src/common/sha256.cpp
  src/common/pdftext.cpp
  src/common/json.cpp
  src/stages/registry.cpp
  src/stages/scan/scan.cpp
  src/stages/scan/walk.cpp
  src/stages/scan/naming.cpp
  src/stages/scan/structure.cpp
  src/stages/scan/content.cpp
  src/stages/scan/report.cpp
  src/stages/convert/convert.cpp
  src/stages/convert/env.cpp
  src/stages/convert/stat.cpp
  src/stages/convert/check.cpp
  src/stages/tag/tag.cpp
  src/stages/tag/parse.cpp
  src/stages/tag/rules.cpp
  src/stages/tag/cross.cpp
  src/stages/tag/report.cpp
)
target_include_directories(docpipe_core PUBLIC include)
target_link_libraries(docpipe_core PUBLIC Threads::Threads PkgConfig::POPPLER_CPP)
target_compile_options(docpipe_core PUBLIC -Wall -Wextra)

add_executable(docpipe src/main.cpp)
target_link_libraries(docpipe PRIVATE docpipe_core)
