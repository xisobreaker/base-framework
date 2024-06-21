cmake_minimum_required(VERSION 3.10)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Chosse the type of build, Debug or Release" FORCE)
endif()

if(NOT BUILD_EXAMPLES)
    set(BUILD_EXAMPLES ON)
endif()

project(base_framework VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GLog REQUIRED)
find_package(Boost REQUIRED)

set(project_include_dirs
    "${CMAKE_HOME_DIRECTORY}/include/framework")

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