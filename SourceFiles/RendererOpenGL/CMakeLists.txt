cmake_minimum_required(VERSION 3.8)

project(Engine.RendererOpenGL)

set(MODULE_SOURCE 
    ${CMAKE_CURRENT_SOURCE_DIR}/Module/RendererOpenGLModule.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Module/RendererOpenGLModule.cpp
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES 
	${MODULE_SOURCE}
)

add_library(${PROJECT_NAME} SHARED
    ${MODULE_SOURCE}
)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${ENGINE_ROOT}/SourceFiles/Common
)

if (MSVC)

    target_include_directories(${PROJECT_NAME} PRIVATE 
	    ${ENGINE_ROOT}/SourceFiles/SDK/glew/Win32/Include
    )

    if ("${CMAKE_GENERATOR_PLATFORM}" STREQUAL "x64")

        message("[MESSAGE]: MSVC Platform x64")

        target_link_directories(${PROJECT_NAME} PRIVATE 
            ${ENGINE_ROOT}/SourceFiles/SDK/glew/Win32/Lib
        )

    elseif ("${CMAKE_GENERATOR_PLATFORM}" STREQUAL "x32")

        message("[MESSAGE]: MSVC Platform x32")

        target_link_directories(${PROJECT_NAME} PRIVATE 
            ${ENGINE_ROOT}/SourceFiles/SDK/glew/Win32/Lib32
        )

    endif()

    target_link_libraries(${PROJECT_NAME} PRIVATE glfw3.lib)

else()

    target_include_directories(${PROJECT_NAME} PRIVATE 
        ${ENGINE_ROOT}/SourceFiles/SDK/glfw/Linux/Include
    )

    if (CMAKE_SIZEOF_VOID_P EQUAL 8)

        if (UNIX)
            message("[MESSAGE]: Unix Platform x64")
        elseif (MINGW)
            message("[MESSAGE]: MinGW Platform x64")
        endif()

        target_link_directories(${PROJECT_NAME} PRIVATE 
            ${ENGINE_ROOT}/SourceFiles/SDK/glfw/Linux/Lib
        )

    elseif (CMAKE_SIZEOF_VOID_P EQUAL 4)

        if (UNIX)
            message("[MESSAGE]: Unix Platform x32")
        elseif (MINGW)
            message("[MESSAGE]: MinGW Platform x32")
        endif()

        target_link_directories(${PROJECT_NAME} PRIVATE 
            ${ENGINE_ROOT}/SourceFiles/SDK/glfw/Linux/Lib32
        )

    endif()

    target_link_libraries(${PROJECT_NAME} PRIVATE libglfw3.a)

endif()

target_precompile_headers(${PROJECT_NAME} PRIVATE
    StdAfx.h
)
