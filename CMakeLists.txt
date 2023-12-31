cmake_minimum_required(VERSION 3.22)
project(cppStudy)

set(CMAKE_CXX_STANDARD 14)

# 设置openssl的安装位置
set(opensslDir "D:/apps/OpenSSLc-Win64")
# 设置头文件位置和动态库位置
set(INC_DIR ${opensslDir}/include)
set(LINK_DIR ${opensslDir}/bin)

# 使头文件可访问
include_directories(${INC_DIR})
# 指定动态库路径
link_directories(${LINK_DIR})
# 添加需要链接的库
link_libraries(libssl-1_1-x64.dll libcrypto-1_1-x64.dll)

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
add_executable(usetime3 cls2/usetime3.cpp cls2/mytime3.cpp)
add_executable(strngbad_run_vegnews cls3/strngbad_run_vegnews.cpp cls3/strngbad.cpp)
add_executable(sayings1 cls3/sayings1.cpp cls3/string1.cpp)
add_executable(sayings2 cls3/sayings2.cpp cls3/string1.cpp)
add_executable(bank cls4/bank.cpp cls4/queue.cpp)
add_executable(str stl/str.cpp)
add_executable(vector stl/vector.cpp)
add_executable(map stl/map.cpp)
add_executable(unordered_map stl/unordered_map.cpp)
add_executable(ostream io/ostream.cpp)
add_executable(file io/file.cpp)
add_executable(lambda0 lambda/lambda0.cpp)
add_executable(lambda1 lambda/lambda1.cpp)
add_executable(lambda2 lambda/lambda2.cpp)
add_executable(MurHash3Test hash/MurHash3Test.cpp hash/MurmurHash3.h)
add_executable(nlohmann_json json/nlohmann_json.cpp json/nlohmann/json.hpp)
add_executable(bash64test base64/bash64test.cpp base64/base64.cpp)
add_executable(regex_test regex/regex_test.cpp)
add_executable(openssl_md5 openssl/openssl_md5.cpp)
add_executable(openssl_sha openssl/openssl_sha.cpp)
add_executable(openssl_aes openssl/openssl_aes.cpp base64/base64.cpp)
add_executable(openssl_rsa openssl/openssl_rsa.cpp)

# 将可执行文件链接到库
#target_link_libraries(openssl_rsa ssl)