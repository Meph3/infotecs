add_library(logger
    logger.cpp
)

target_include_directories(logger PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
set_target_properties(logger PROPERTIES
    POSITION_INDEPENDENT_CODE ON
)
