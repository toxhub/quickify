cmake_minimum_required(VERSION 2.8)

project(QUICKIFY)

set (QUICKIFY_VERSION_MAJOR 0)
set (QUICKIFY_VERSION_MINOR 1)

SET(ROOT_DIR ${CMAKE_SOURCE_DIR})

aux_source_directory(./src DIR_SCRS)
add_definitions(-std=c++11)

SET(DEPS_NGHTTP3_SRC ${ROOT_DIR}/deps/nghttp3/build/lib)
INCLUDE_DIRECTORIES(${DEPS_NGHTTP3_SRC}/includes/)
add_library(nghttp3 STATIC IMPORTED)
set_target_properties(nghttp3 PROPERTIES IMPORTED_LOCATION ${DEPS_NGHTTP3_SRC}/.libs/libnghttp3.a)

SET(DEPS_LIBUV_SRC ${ROOT_DIR}/deps/libuv/build)
INCLUDE_DIRECTORIES(${DEPS_LIBUV_SRC}/include)
add_library(libuv STATIC IMPORTED)
set_target_properties(libuv PROPERTIES IMPORTED_LOCATION ${DEPS_LIBUV_SRC}/.libs/libuv.a)

add_executable(quickify ${DIR_SCRS})

target_link_libraries(quickify libuv)
target_link_libraries(quickify nghttp3)
