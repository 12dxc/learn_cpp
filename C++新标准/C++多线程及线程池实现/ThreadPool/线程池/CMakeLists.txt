## --> windows下指定gun编译器指令: cmake -G "MinGW Makefiles" ..
# 指定cmake最低版本
cmake_minimum_required(VERSION 3.15)

# 追加加编译器指令参数
add_compile_options(-fexec-charset=GBK)
# 指定项目名称
project(ThreadPool)

# 指定C++标准
set(CMAKE_CXX_STANDARD 17)

# 搜索源文件
aux_source_directory(${PROJECT_SOURCE_DIR} SRC)

# 为工程引入一个可执行文件
add_executable(ThreadPool ${SRC})

# 输出可执行的文件路径
SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR})



