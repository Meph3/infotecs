cmake_minimum_required(VERSION 3.10)
project(logger_project)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_SHARED_LIBS "Build shared library" OFF)

add_subdirectory(logger)
add_subdirectory(app)
add_executable(logger_tests tests/test_logger.cpp)
target_link_libraries(logger_tests PRIVATE logger)
add_subdirectory(monitor)
