set(MODULE_NAME bs2sysex)

set(SOURCES src/decoder.cpp)
set(HEADERS
    include/bs2sysex/decoder.hpp
    include/bs2sysex/param.hpp)

add_library(${MODULE_NAME} SHARED ${SOURCES} ${HEADERS})
add_library(bs2sysex::bs2sysex ALIAS bs2sysex)

if(BUILD_TESTS)
    add_library(bs2sysex_static STATIC ${SOURCES} ${HEADERS})
    target_include_directories(bs2sysex_static INTERFACE include PRIVATE include/bs2sysex)
endif()

target_include_directories(${MODULE_NAME} INTERFACE include PRIVATE include/bs2sysex)

set_target_properties(${MODULE_NAME} PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(${MODULE_NAME} PROPERTIES SOVERSION ${PROJECT_VERSION_MAJOR})

install(TARGETS ${MODULE_NAME}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
