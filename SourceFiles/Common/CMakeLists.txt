cmake_minimum_required(VERSION 3.8)

project(Engine.Common)

set(ENGINE_SOURCE
    ${CMAKE_CURRENT_SOURCE_DIR}/Engine/Engine.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Engine/ICoreModule.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Engine/IEngineModule.h
)

set(PLATFORMS_SOURCE
    ${CMAKE_CURRENT_SOURCE_DIR}/Platforms/Linux.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Platforms/Win32.h
)

add_library(${PROJECT_NAME} SHARED
    ${ENGINE_SOURCE}
)

set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)