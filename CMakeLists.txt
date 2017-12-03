cmake_minimum_required(VERSION 2.8.11)

configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
    RESULT_VARIABLE result
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
    RESULT_VARIABLE result
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
                 ${CMAKE_BINARY_DIR}/googletest-build)

include_directories("${gtest_SOURCE_DIR}/include")

get_filename_component(ProjectId ${CMAKE_SOURCE_DIR} NAME)
project(${ProjectId})
add_definitions("-std=c++14")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall -Werror -Wextra -pedantic")

include_directories(${CMAKE_SOURCE_DIR}/src)

aux_source_directory(src/app SRC_LIST)
aux_source_directory(src/codec CLASSES_LIST)
add_executable(${PROJECT_NAME} ${SRC_LIST} ${CLASSES_LIST})
target_link_libraries( ${PROJECT_NAME} stdc++)

aux_source_directory(testing TEST_LIST)
add_executable(ut ${TEST_LIST} ${CLASSES_LIST})
target_link_libraries(ut stdc++ gtest_main gmock_main)
