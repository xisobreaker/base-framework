project(xiso_framework VERSION 0.0.1)

include_directories(${project_include_dirs})

file(GLOB_RECURSE PROTO_FILES
    "${CMAKE_CURRENT_LIST_DIR}/proto/*.proto"
)

foreach(FIL ${PROTO_FILES})
    get_filename_component(FIL_WE ${FIL} NAME_WE)
    execute_process(
        COMMAND ${PROTOBUF_PROTOC_EXECUTABLE}
        -I ${CMAKE_CURRENT_LIST_DIR}/proto
        --cpp_out=${CMAKE_CURRENT_LIST_DIR}/proto
        "${FIL_WE}.proto"
    )
endforeach()

file(GLOB_RECURSE PROTO_SRCS "proto/*.pb.cc")

aux_source_directory(./configure DIR_SOURCES)
aux_source_directory(./logging DIR_SOURCES)
aux_source_directory(. DIR_SOURCES)

add_library(${PROJECT_NAME} SHARED ${DIR_SOURCES} ${PROTO_SRCS})
target_link_libraries(${PROJECT_NAME} PRIVATE protobuf)
target_link_libraries(${PROJECT_NAME} PRIVATE glog)

set_property(TARGET ${PROJECT_NAME} PROPERTY VERSION ${PROJECT_VERSION})
