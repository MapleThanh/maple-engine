cmake_minimum_required(VERSION 3.10)

# Project name and version
project(MapleGameEngine VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set policy to avoid the OpenGL warning
if(POLICY CMP0072)
  cmake_policy(SET CMP0072 NEW)
endif()

# Add the executable
add_executable(${PROJECT_NAME} src/main.cpp)

# Set the output directory for the executable
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)

# Find OpenGL package
find_package(OpenGL REQUIRED)

# Find GLEW package
find_package(GLEW REQUIRED)

# Find GLFW package
find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE ${OPENGL_INCLUDE_DIR} ${GLEW_INCLUDE_DIRS} ${GLFW_INCLUDE_DIRS})

# Link libraries
target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES} ${GLFW_LIBRARIES} ${GLFW_STATIC_LIBRARIES})
