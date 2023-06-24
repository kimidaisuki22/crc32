cmake_minimum_required(VERSION 3.0.0)
project(crc32 VERSION 0.1.1)

include(CTest)
enable_testing()

add_library(crc32 src/crc32.cpp src/crc32_helper.cpp)
target_include_directories(crc32 PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})



if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    option(install_crc32 "Install crc32" ON)
    add_executable(main src/main.cpp)
    target_link_libraries(main crc32)
else()
    option(install_crc32 "Install crc32" OFF)
endif()

if(install_crc32)
include(CPack)
include(GNUInstallDirs)
    install(TARGETS crc32
        EXPORT crc32
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    )
    install(EXPORT crc32
        FILE crc32Config.cmake
        NAMESPACE crc32::
        DESTINATION share/crc32
    )
    install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
endif()
