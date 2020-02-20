cmake_minimum_required(VERSION 3.8)

project(Launcher)

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${ENGINE_ROOT}/SourceFiles/Common
)