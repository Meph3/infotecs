set(SOURCES
    logger.cpp
    file_logger_output.cpp
    socket_logger_output.cpp
)

add_library(logger ${SOURCES})
target_include_directories(logger PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
