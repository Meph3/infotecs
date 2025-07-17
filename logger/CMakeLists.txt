# logger/CMakeLists.txt
add_library(logger
    logger.cpp
    file_logger_output.cpp
    socket_logger_output.cpp
)

target_include_directories(logger PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_features(logger PUBLIC cxx_std_17)
