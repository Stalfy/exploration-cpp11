# Link the executable.
add_executable(${PROJECT_COMPILE_NAME} main.cxx)

# Add the subdirectories.
add_subdirectory(services)
add_subdirectory(dependency_injection)
add_subdirectory(hosting)

# Define the compilation flag indicating that the projet is being built for windows.
set_target_properties(${PROJECT_COMPILE_NAME} PROPERTIES DEBUG_POSTFIX "d")
target_compile_definitions(${PROJECT_COMPILE_NAME} PRIVATE "WINEXPORT_")
