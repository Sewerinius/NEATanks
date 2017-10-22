cmake_minimum_required(VERSION 3.4)
project(NEATanks)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp src/classes/Classes.cpp src/classes/Classes.h src/NEATanks.h src/classes/SettingsData.h src/loader.cpp src/display.cpp src/renderers/Renderer.cpp src/shaders/ShaderProgram.cpp src/shaders/ShaderProgram.h lib/glad/src/glad.c src/shaders/StaticShader.cpp src/shaders/StaticShader.h src/classes/ModelData.h src/gl.h src/renderers/Renderer.h src/linmath.h src/shaders/BackgroundShader.cpp src/shaders/BackgroundShader.h)
add_executable(NEATanks ${SOURCE_FILES})

add_subdirectory(lib/glfw-3.2.1)
include_directories(lib/glfw-3.2.1/include)
target_link_libraries(NEATanks glfw ${GLFW_LIBRARIES})

add_subdirectory(lib/glm-0.9.7.6)
include_directories(lib/glm-0.9.7.6)
target_link_libraries(NEATanks glm)

include_directories(lib/glad/include)