cmake_minimum_required(VERSION 3.23)
project(GraphLab)

set(CMAKE_CXX_STANDARD 17)

## 获取OS信息
#if (CMAKE_HOST_WIN32)
#    set(WINDOWS 1)
#elseif(CMAKE_HOST_APPLE)
#    set(MACOS 1)
#elseif(CMAKE_HOST_UNIX)
#    set(LINUX 1)
#endif()

add_subdirectory(3rdparty)
add_subdirectory(source)