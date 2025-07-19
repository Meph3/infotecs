add_executable(logger_monitor
    main.cpp
    socket_listener.cpp
    stats_collector.cpp
)

target_include_directories(logger_monitor PRIVATE ${PROJECT_SOURCE_DIR}/logger)
target_link_libraries(logger_monitor PRIVATE logger)
