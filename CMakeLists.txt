cmake_minimum_required(VERSION 3.15)
project(GameEngineOpenGL VERSION 1.0.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Export compile commands for better IDE support
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Find required packages
find_package(glfw3 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(OpenGL REQUIRED)

# Create executable
add_executable(${PROJECT_NAME} main.cpp)

# Link libraries
target_link_libraries(${PROJECT_NAME} PRIVATE
    glfw
    glad::glad
    glm::glm
    OpenGL::GL
    ${CMAKE_DL_LIBS}
)

# Add pthread on Linux
if(UNIX AND NOT APPLE)
    target_link_libraries(${PROJECT_NAME} PRIVATE pthread)
endif()

# Set output directory
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

# Platform-specific settings
if(WIN32)
    # Copy GLFW DLL to output directory on Windows
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:glfw>
        $<TARGET_FILE_DIR:${PROJECT_NAME}>
    )
endif()

# Print build information
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "C++ Compiler: ${CMAKE_CXX_COMPILER}")
message(STATUS "CMake toolchain file: ${CMAKE_TOOLCHAIN_FILE}")
