# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ubuntu/logger_project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ubuntu/logger_project/build

# Include any dependencies generated for this target.
include logger/CMakeFiles/logger.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include logger/CMakeFiles/logger.dir/compiler_depend.make

# Include the progress variables for this target.
include logger/CMakeFiles/logger.dir/progress.make

# Include the compile flags for this target's objects.
include logger/CMakeFiles/logger.dir/flags.make

logger/CMakeFiles/logger.dir/logger.cpp.o: logger/CMakeFiles/logger.dir/flags.make
logger/CMakeFiles/logger.dir/logger.cpp.o: /home/ubuntu/logger_project/logger/logger.cpp
logger/CMakeFiles/logger.dir/logger.cpp.o: logger/CMakeFiles/logger.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ubuntu/logger_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object logger/CMakeFiles/logger.dir/logger.cpp.o"
	cd /home/ubuntu/logger_project/build/logger && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT logger/CMakeFiles/logger.dir/logger.cpp.o -MF CMakeFiles/logger.dir/logger.cpp.o.d -o CMakeFiles/logger.dir/logger.cpp.o -c /home/ubuntu/logger_project/logger/logger.cpp

logger/CMakeFiles/logger.dir/logger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/logger.dir/logger.cpp.i"
	cd /home/ubuntu/logger_project/build/logger && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/logger_project/logger/logger.cpp > CMakeFiles/logger.dir/logger.cpp.i

logger/CMakeFiles/logger.dir/logger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/logger.dir/logger.cpp.s"
	cd /home/ubuntu/logger_project/build/logger && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/logger_project/logger/logger.cpp -o CMakeFiles/logger.dir/logger.cpp.s

logger/CMakeFiles/logger.dir/file_logger_output.cpp.o: logger/CMakeFiles/logger.dir/flags.make
logger/CMakeFiles/logger.dir/file_logger_output.cpp.o: /home/ubuntu/logger_project/logger/file_logger_output.cpp
logger/CMakeFiles/logger.dir/file_logger_output.cpp.o: logger/CMakeFiles/logger.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ubuntu/logger_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object logger/CMakeFiles/logger.dir/file_logger_output.cpp.o"
	cd /home/ubuntu/logger_project/build/logger && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT logger/CMakeFiles/logger.dir/file_logger_output.cpp.o -MF CMakeFiles/logger.dir/file_logger_output.cpp.o.d -o CMakeFiles/logger.dir/file_logger_output.cpp.o -c /home/ubuntu/logger_project/logger/file_logger_output.cpp

logger/CMakeFiles/logger.dir/file_logger_output.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/logger.dir/file_logger_output.cpp.i"
	cd /home/ubuntu/logger_project/build/logger && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/logger_project/logger/file_logger_output.cpp > CMakeFiles/logger.dir/file_logger_output.cpp.i

logger/CMakeFiles/logger.dir/file_logger_output.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/logger.dir/file_logger_output.cpp.s"
	cd /home/ubuntu/logger_project/build/logger && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/logger_project/logger/file_logger_output.cpp -o CMakeFiles/logger.dir/file_logger_output.cpp.s

logger/CMakeFiles/logger.dir/socket_logger_output.cpp.o: logger/CMakeFiles/logger.dir/flags.make
logger/CMakeFiles/logger.dir/socket_logger_output.cpp.o: /home/ubuntu/logger_project/logger/socket_logger_output.cpp
logger/CMakeFiles/logger.dir/socket_logger_output.cpp.o: logger/CMakeFiles/logger.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ubuntu/logger_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object logger/CMakeFiles/logger.dir/socket_logger_output.cpp.o"
	cd /home/ubuntu/logger_project/build/logger && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT logger/CMakeFiles/logger.dir/socket_logger_output.cpp.o -MF CMakeFiles/logger.dir/socket_logger_output.cpp.o.d -o CMakeFiles/logger.dir/socket_logger_output.cpp.o -c /home/ubuntu/logger_project/logger/socket_logger_output.cpp

logger/CMakeFiles/logger.dir/socket_logger_output.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/logger.dir/socket_logger_output.cpp.i"
	cd /home/ubuntu/logger_project/build/logger && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/logger_project/logger/socket_logger_output.cpp > CMakeFiles/logger.dir/socket_logger_output.cpp.i

logger/CMakeFiles/logger.dir/socket_logger_output.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/logger.dir/socket_logger_output.cpp.s"
	cd /home/ubuntu/logger_project/build/logger && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/logger_project/logger/socket_logger_output.cpp -o CMakeFiles/logger.dir/socket_logger_output.cpp.s

# Object files for target logger
logger_OBJECTS = \
"CMakeFiles/logger.dir/logger.cpp.o" \
"CMakeFiles/logger.dir/file_logger_output.cpp.o" \
"CMakeFiles/logger.dir/socket_logger_output.cpp.o"

# External object files for target logger
logger_EXTERNAL_OBJECTS =

logger/liblogger.a: logger/CMakeFiles/logger.dir/logger.cpp.o
logger/liblogger.a: logger/CMakeFiles/logger.dir/file_logger_output.cpp.o
logger/liblogger.a: logger/CMakeFiles/logger.dir/socket_logger_output.cpp.o
logger/liblogger.a: logger/CMakeFiles/logger.dir/build.make
logger/liblogger.a: logger/CMakeFiles/logger.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/ubuntu/logger_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library liblogger.a"
	cd /home/ubuntu/logger_project/build/logger && $(CMAKE_COMMAND) -P CMakeFiles/logger.dir/cmake_clean_target.cmake
	cd /home/ubuntu/logger_project/build/logger && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/logger.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
logger/CMakeFiles/logger.dir/build: logger/liblogger.a
.PHONY : logger/CMakeFiles/logger.dir/build

logger/CMakeFiles/logger.dir/clean:
	cd /home/ubuntu/logger_project/build/logger && $(CMAKE_COMMAND) -P CMakeFiles/logger.dir/cmake_clean.cmake
.PHONY : logger/CMakeFiles/logger.dir/clean

logger/CMakeFiles/logger.dir/depend:
	cd /home/ubuntu/logger_project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/logger_project /home/ubuntu/logger_project/logger /home/ubuntu/logger_project/build /home/ubuntu/logger_project/build/logger /home/ubuntu/logger_project/build/logger/CMakeFiles/logger.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : logger/CMakeFiles/logger.dir/depend

