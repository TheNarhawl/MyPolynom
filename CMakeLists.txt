cmake_minimum_required(VERSION 3.6 FATAL_ERROR)

project(parser_antlr)

set(CMAKE_CXX_STANDARD 17)
set(TARGET parser)

set(ANTLR_DIR "C:/ANTLR/antlr-4.13.2")
set(ANTLR_INCLUDE "${ANTLR_DIR}/include/antlr4-runtime")
set(ANTLR_LIB "${ANTLR_DIR}/lib/antlr4-runtime.lib")

file(GLOB TARGET_SRC "*.cpp")
file(GLOB TARGET_HD "*.h")

add_executable(${TARGET} ${TARGET_SRC} ${TARGET_HD})

target_include_directories(${TARGET} PUBLIC ${ANTLR_DIR} ${ANTLR_INCLUDE} ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(${TARGET} ${ANTLR_LIB})