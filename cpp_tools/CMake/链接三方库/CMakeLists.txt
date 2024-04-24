cmake_minimum_required(VERSION 3.11)
project(Demo)

set(CMAKE_CXX_STANDARD 17)

# 在线引入第三方库 -------------------
# 启用FetchContent模块
include(FetchContent)
#声明一个依赖
FetchContent_Declare(
    libhv
    GIT_REPOSITORY https://gitee.com/libhv/libhv.git  # 拉取存储库
    GIT_TAG v1.3.2  # 存储库的发行版
)
# 拉取并添加依赖
FetchContent_MakeAvailable(libhv)
# ---------------------------------

# 添加你的执行文件
add_executable(app main.cpp)

# 链接 workflow hv 的库到你的执行文件
target_link_libraries(app workflow hv)  # workflow已配置在本地环境，故可直接链接

# 指定可执行文件输出路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})
