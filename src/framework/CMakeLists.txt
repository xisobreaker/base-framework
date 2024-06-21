project(Framework VERSION 0.0.1)

include_directories(${project_include_dirs})

aux_source_directory(. DIR_SOURCES)

add_library(${PROJECT_NAME} SHARED ${DIR_SOURCES})
set_property(TARGET ${PROJECT_NAME} PROPERTY VERSION ${PROJECT_VERSION})
