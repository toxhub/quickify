cmake_minimum_required(VERSION 2.8)

project(QUICKIFY)

set (QUICKIFY_VERSION_MAJOR 0)
set (QUICKIFY_VERSION_MINOR 1)

SET(ROOT_DIR ${CMAKE_SOURCE_DIR})
SET(DEPS_QUICHE_SRC ${ROOT_DIR}/deps/quiche/build)

INCLUDE_DIRECTORIES(${ROOT_DIR}/deps/quiche/build/include)
add_library(libquiche STATIC IMPORTED)
set_target_properties(libquiche PROPERTIES IMPORTED_LOCATION ${DEPS_QUICHE_SRC}/target/release/libquiche.a)

add_executable(quickify quickify.cc)
target_link_libraries(quickify libquiche)
