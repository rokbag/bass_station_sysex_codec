set(MODULE_NAME bs2sysex)

set(SOURCES src/decoder.cpp)
set(HEADERS
    include/bs2sysex/decoder.hpp
    include/bs2sysex/param.hpp)

if(BUILD_SHARED)
    add_library(${MODULE_NAME} SHARED ${SOURCES} ${HEADERS})
    set_target_properties(${MODULE_NAME} PROPERTIES
        VERSION ${PROJECT_VERSION}
        SOVERSION ${PROJECT_VERSION_MAJOR})
else()
    add_library(${MODULE_NAME} STATIC ${SOURCES} ${HEADERS})
endif()

add_library(bs2sysex::bs2sysex ALIAS ${MODULE_NAME})

target_include_directories(${MODULE_NAME}
    INTERFACE include
    PRIVATE include/bs2sysex)

install(TARGETS ${MODULE_NAME}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})