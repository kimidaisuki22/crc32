cmake_minimum_required(VERSION 3.0.0)
project(crc32 VERSION 0.1.0)

include(CTest)
enable_testing()

add_library(crc32 crc32.cpp crc32_helper.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

add_executable(main main.cpp)
target_link_libraries(main crc32)
