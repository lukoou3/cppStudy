cmake_minimum_required(VERSION 3.22)
project(cppStudy)

set(CMAKE_CXX_STANDARD 14)

add_executable(base base.cpp)

add_executable(base_array base_array.cpp)
add_executable(base_string base_string.cpp)
add_executable(base_struct base_struct.cpp)
add_executable(base_enum base_enum.cpp)
add_executable(base_pointer base_pointer.cpp)
add_executable(base_loop base_loop.cpp)
add_executable(base_control_flow base_control_flow.cpp)
add_executable(base_function base_function.cpp)
add_executable(base_function_high base_function_high.cpp)

add_executable(usestok00 cls/usestok00.cpp cls/stock00.cpp)
add_executable(usestok01 cls/usestok01.cpp cls/stock01.cpp)
add_executable(usestok10 cls/usestok10.cpp cls/stock10.cpp)
add_executable(usestok20 cls/usestok20.cpp cls/stock20.cpp)
add_executable(usetime0 cls2/usetime0.cpp cls2/mytime0.cpp)
add_executable(usetime1 cls2/usetime1.cpp cls2/mytime1.cpp)
add_executable(usetime2 cls2/usetime2.cpp cls2/mytime2.cpp)