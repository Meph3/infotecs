cmake_minimum_required(VERSION 3.10)
project(logger_project LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Пользовательская опция: Собирать как shared библиотеку?
option(BUILD_LOGGER_AS_SHARED "Build logger library as shared (ON) or static (OFF)" OFF)

# Устанавливаем флаг для CMake
if (BUILD_LOGGER_AS_SHARED)
    set(BUILD_SHARED_LIBS ON)
else()
    set(BUILD_SHARED_LIBS OFF)
endif()

# Добавляем подкаталоги
add_subdirectory(logger)
add_subdirectory(app)
