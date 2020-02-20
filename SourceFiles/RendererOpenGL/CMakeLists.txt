cmake_minimum_required(VERSION 3.8)

project(Engine.RendererOpenGL)

set(MODULE_SOURCE 
    ${CMAKE_CURRENT_SOURCE_DIR}/Module/RendererOpenGLModule.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Module/RendererOpenGLModule.cpp
)

add_library(${PROJECT_NAME} SHARED
    ${MODULE_SOURCE}
)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${ENGINE_ROOT}/SourceFiles/Common
)