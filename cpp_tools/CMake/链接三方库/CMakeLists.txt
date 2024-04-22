cmake_minimum_required(VERSION 3.11)
project(Demo)

set(CMAKE_CXX_STANDARD 17)

# 在线下载配置和依赖
# 使用FetchContent来下载和管理第三方库  
include(FetchContent)
FetchContent_Declare(
  libhv
  GIT_REPOSITORY https://gitee.com/libhv/libhv.git
  GIT_TAG        v1.0.0
)
FetchContent_MakeAvailable(libhv)   # 创建链接库

# 添加你的执行文件
add_executable(app main.cpp)

# 链接 workflow hv 的库到你的执行文件
target_link_libraries(app workflow hv)  # workflow已配置在本地环境，故可直接链接

# 指定可执行文件输出路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})
