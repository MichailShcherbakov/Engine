cmake_minimum_required(VERSION 3.8)

project(Engine.Core)

set(MODULE_SOURCE 
    ${CMAKE_CURRENT_SOURCE_DIR}/Module/CoreModule.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Module/CoreModule.cpp
)

set(STDAFX_SOURCE 
    ${CMAKE_CURRENT_SOURCE_DIR}/StdAfx.h
    ${CMAKE_CURRENT_SOURCE_DIR}/StdAfx.cpp
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES 
    ${MODULE_SOURCE}
    ${STDAFX_SOURCE}
)

add_library(${PROJECT_NAME} SHARED
    ${MODULE_SOURCE}
    ${STDAFX_SOURCE}
)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${ENGINE_ROOT}/SourceFiles/Common
)

target_precompile_headers(${PROJECT_NAME} PRIVATE
    StdAfx.h
)
