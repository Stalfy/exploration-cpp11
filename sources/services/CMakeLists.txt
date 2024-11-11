# #############################################################################
# Link the templates.
# #############################################################################
target_include_directories(${PROJECT_COMPILE_NAME}
    PRIVATE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/templates>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_DIR}/include/instances>
)

# #############################################################################
# Link the headers.
# #############################################################################
target_include_directories(${PROJECT_COMPILE_NAME}
    PRIVATE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/headers>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_DIR}/include/instances>
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_DIR}/include/instances>
)

# #############################################################################
# Link the sources.
# #############################################################################
file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/sources/*.cxx")
target_sources(${PROJECT_COMPILE_NAME} PRIVATE ${SOURCES})
