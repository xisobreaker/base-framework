cmake_minimum_required(VERSION 3.10)

project(base_framework VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Chosse the type of build, Debug or Release" FORCE)
endif()

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/output/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/output/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/output)

# x86 系统架构
if(${CMAKE_SYSTEM_PROCESSOR} STREQUAL x86_64)
    message(STATUS "Build with x86_64")
endif()

# aarch 系统架构
if(${CMAKE_SYSTEM_PROCESSOR} STREQUAL aarch64)
    message(STATUS "Build with aarch64")
endif()

# 默认编译示例代码
if(NOT BUILD_EXAMPLES)
    set(BUILD_EXAMPLES ON)
endif()

find_package(GLog REQUIRED)
find_package(Protobuf REQUIRED)

set(project_include_dirs
    "${CMAKE_HOME_DIRECTORY}/include/framework"
    "${CMAKE_HOME_DIRECTORY}/include/framework/common"
    "${CMAKE_HOME_DIRECTORY}/include/framework/component"
    "${CMAKE_HOME_DIRECTORY}/include/framework/configure"
    "${CMAKE_HOME_DIRECTORY}/include/framework/logging")

# 添加子目录
add_subdirectory(src)

if(BUILD_EXAMPLES)
    add_subdirectory(example)
endif()

include(CTest)
if(BUILD_TESTING)
    enable_testing()
    add_subdirectory(test)
endif()