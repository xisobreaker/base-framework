project(example_framework)

include_directories(${project_include_dirs})

aux_source_directory(. DIR_SOURCES)
add_executable(${PROJECT_NAME} ${DIR_SOURCES})

target_link_libraries(${PROJECT_NAME} glog)
target_link_libraries(${PROJECT_NAME} Framework)

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
