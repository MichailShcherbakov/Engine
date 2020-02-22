cmake_minimum_required(VERSION 3.8)

project(Engine)

set(ENGINE_ROOT ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_PREFIX_PATH ${ENGINE_ROOT}/Libs/cmake)
set(CMAKE_BINARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/.bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})


add_subdirectory(${ENGINE_ROOT}/SourceFiles/Common)
add_subdirectory(${ENGINE_ROOT}/SourceFiles/Core)
add_subdirectory(${ENGINE_ROOT}/SourceFiles/GLFW)
add_subdirectory(${ENGINE_ROOT}/SourceFiles/RendererOpenGL)
add_subdirectory(${ENGINE_ROOT}/SourceFiles/Launcher)