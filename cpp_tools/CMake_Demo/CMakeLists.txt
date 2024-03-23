# 指定cmake最低版本
cmake_minimum_required(VERSION 3.15)

# 指定项目名称
project(test)

# 设置变量
# set(SRC add.cpp div.cpp mult.cpp main.cpp sub.cpp)

# 搜索文件  PROJECT_SOURCE_DIR :表示执行cmake后面跟随的目录
# aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC)
# 搜索文件2  CMAKE_CURRENT_SOURCE_DIR:表示cmake文件路径的源文件
file(GLOB SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

message("------------")
message(${SRC})
# 使用list删除指定文件  参1为可选项，REMOVE_ITEM 即删除，参2为要删除的内容的变量，参2指定删除内容
list(REMOVE_ITEM SRC ${PROJECT_SOURCE_DIR}/src/main.cpp)
message("------------")
message(${SRC})
message("------------")

# 指定头文件路径
include_directories(${PROJECT_SOURCE_DIR}/include)

# 指定C++标准  使用宏CMAKE_CXX_STANDARD
set(CMAKE_CXX_STANDARD 11)

# 日志 默认为重要
message("111xxxxxxxxxxxxxxxxxxxx")

# 制作库文件  SHARED :动态库，STATIC :静态库
# add_library(calc STATIC ${SRC})
# 指定库文件生成路径  使用宏LIBRARY_OUTPUT_PATH
# set(LIBRARY_OUTPUT_PATH /home/cong/Demo/lib2)

# 链接静态库
# link_libraries(calc)

# 指定库文件路径
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib2)

# 指定可执行文件路径  使用宏EXECUTABLE_OUTPUT_PATH
set(EXECUTABLE_OUTPUT_PATH /home/cong/Demo)

# 指定要生成的可执行文件名
add_executable(app ${PROJECT_SOURCE_DIR}/src/main.cpp ${SRC})

message(STATUS "222xxxxxxxxxxxxxxxxxxxx")  # STATUS 非重要，无影响

# 链接动态库  第一个参数是可执行文件名，之后是要链接的库
target_link_libraries(app calc)

# message(FATAL_ERROR "333xxxxxxxxxxxxxxxxxxxx")  # CMake错误，会中断
 
# 字符串拼接  
# 使用set拼接  把参1之后的串加入到参1变量中
set(tmp hello world)
set(tmp1 ${tmp} ${SRC})
message(${tmp})
message(${tmp1})
# 使用list拼接  参1为选项，APPEND 即追加，之后的参数与set拼接相同
list(APPEND tmp "xxx1" "sss2" ${SRC})
message(${tmp})

# 通过宏指定部分代码是否可用，以此完成调试
add_definitions(-DDEBUG)