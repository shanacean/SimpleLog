cmake_minimum_required(VERSION 3.0.0)
project(dlog VERSION 0.1.0)

add_compile_options(-std=c++17 -g)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-builtin-macro-redefined -D'__FILE__=\"$(subst $(realpath ${CMAKE_SOURCE_DIR})/,,$(abspath $<))\"'")
include_directories(.)
aux_source_directory(${CMAKE_SOURCE_DIR}/src DLOG)

add_executable(test_file test/test_filelog.cpp ${DLOG})
add_executable(test_out test/test_outlog.cpp ${DLOG})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

target_link_libraries(test_file pthread)
target_link_libraries(test_out pthread)