cmake_minimum_required(VERSION 3.10)
project(LoggerProject)

option(BUILD_SHARED_LIBS "Build shared libraries instead of static" ON)

add_subdirectory(logger)
add_subdirectory(app)
