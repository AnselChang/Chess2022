cmake_minimum_required(VERSION 3.0.0)
project(Chess2022 VERSION 0.1.0)

include(CTest)
enable_testing()

set (CMAKE_CXX_STANDARD 14)

include_directories(include)
file(GLOB SRC_FILES "src/*.cpp")
add_executable(Chess2022 src/main.cpp src/DataStructures/Game.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
