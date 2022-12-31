cmake_minimum_required(VERSION 3.12)
set(MODULE_NAME bs2_sysec_codec)

project(${MODULE_NAME} VERSION 1.0.0 DESCRIPTION "Bass Station II SysEx decoding library")

set(CMAKE_CXX_STANDARD 17)

include(cmake/config.cmake)

add_subdirectory(src)
add_subdirectory(testing)
