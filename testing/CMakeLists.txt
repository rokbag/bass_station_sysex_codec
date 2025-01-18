set(MODULE_NAME bs2sysex_ut)

add_subdirectory(gtest)

add_executable(${MODULE_NAME} ut_decoder.cpp)

target_link_libraries(${MODULE_NAME}
    PRIVATE
    gtest_main
    main::bs2sysex
)

add_test(NAME ${MODULE_NAME} COMMAND ${MODULE_NAME})
