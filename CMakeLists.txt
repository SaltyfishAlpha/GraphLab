cmake_minimum_required(VERSION 3.23)
project(GraphLab)

set(CMAKE_CXX_STANDARD 17)

set(LAB_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(LAB_ASSET_DIR "/asset")
set(CMAKE_INSTALL_PREFIX "${LAB_ROOT_DIR}/bin")
set(BINARY_ROOT_DIR "${CMAKE_INSTALL_PREFIX}/")

## 获取OS信息
#if (CMAKE_HOST_WIN32)
#    set(WINDOWS 1)
#elseif(CMAKE_HOST_APPLE)
#    set(MACOS 1)
#elseif(CMAKE_HOST_UNIX)
#    set(LINUX 1)
#endif()

add_subdirectory(3rdparty)

add_subdirectory(source/editor)
add_subdirectory(source/runtime)

add_dependencies(GraphLabEditor GraphLabRuntime)

