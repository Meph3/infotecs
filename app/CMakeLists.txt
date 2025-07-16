add_executable(logger_app main.cpp)
target_link_libraries(logger_app logger)

target_include_directories(logger PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
set_target_properties(logger PROPERTIES
    POSITION_INDEPENDENT_CODE ON
)
