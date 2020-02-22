cmake_minimum_required(VERSION 3.8)

project(Engine.Common)

set(ENGINE_SOURCE
    ${CMAKE_CURRENT_SOURCE_DIR}/Engine/Engine.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Engine/Engine.inl
    ${CMAKE_CURRENT_SOURCE_DIR}/Engine/GlobalVariable.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Engine/ICoreModule.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Engine/IEngineModule.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Engine/Memory.h
)

set(PLATFORMS_SOURCE
    ${CMAKE_CURRENT_SOURCE_DIR}/Platforms/Linux.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Platforms/Win32.h
)

set(EVENT_SYSTEM 
    ${CMAKE_CURRENT_SOURCE_DIR}/EventSystem/IEvent.h
    ${CMAKE_CURRENT_SOURCE_DIR}/EventSystem/Event.h
    ${CMAKE_CURRENT_SOURCE_DIR}/EventSystem/IHandler.h
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES 
    ${ENGINE_SOURCE}
    ${PLATFORMS_SOURCE}
    ${EVENT_SYSTEM}
)

add_library(${PROJECT_NAME} SHARED
    ${ENGINE_SOURCE}
    ${PLATFORMS_SOURCE}
    ${EVENT_SYSTEM}
)

set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)