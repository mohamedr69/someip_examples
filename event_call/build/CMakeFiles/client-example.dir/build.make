# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mohamed/Desktop/someIP/someip_examples/event_call

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mohamed/Desktop/someIP/someip_examples/event_call/build

# Include any dependencies generated for this target.
include CMakeFiles/client-example.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/client-example.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/client-example.dir/flags.make

CMakeFiles/client-example.dir/src/client.cpp.o: CMakeFiles/client-example.dir/flags.make
CMakeFiles/client-example.dir/src/client.cpp.o: ../src/client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mohamed/Desktop/someIP/someip_examples/event_call/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/client-example.dir/src/client.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/client-example.dir/src/client.cpp.o -c /home/mohamed/Desktop/someIP/someip_examples/event_call/src/client.cpp

CMakeFiles/client-example.dir/src/client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client-example.dir/src/client.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mohamed/Desktop/someIP/someip_examples/event_call/src/client.cpp > CMakeFiles/client-example.dir/src/client.cpp.i

CMakeFiles/client-example.dir/src/client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client-example.dir/src/client.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mohamed/Desktop/someIP/someip_examples/event_call/src/client.cpp -o CMakeFiles/client-example.dir/src/client.cpp.s

# Object files for target client-example
client__example_OBJECTS = \
"CMakeFiles/client-example.dir/src/client.cpp.o"

# External object files for target client-example
client__example_EXTERNAL_OBJECTS =

client-example: CMakeFiles/client-example.dir/src/client.cpp.o
client-example: CMakeFiles/client-example.dir/build.make
client-example: /home/mohamed/Desktop/someIP/vsomeip/build/libvsomeip3.so.3.4.10
client-example: /usr/lib/x86_64-linux-gnu/libboost_system.so.1.71.0
client-example: /usr/lib/x86_64-linux-gnu/libboost_thread.so.1.71.0
client-example: /usr/lib/x86_64-linux-gnu/libboost_log.so.1.71.0
client-example: /usr/lib/x86_64-linux-gnu/libboost_thread.so.1.71.0
client-example: /usr/lib/x86_64-linux-gnu/libboost_atomic.so.1.71.0
client-example: /usr/lib/x86_64-linux-gnu/libboost_chrono.so.1.71.0
client-example: /usr/lib/x86_64-linux-gnu/libboost_date_time.so.1.71.0
client-example: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so.1.71.0
client-example: /usr/lib/x86_64-linux-gnu/libboost_regex.so.1.71.0
client-example: CMakeFiles/client-example.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mohamed/Desktop/someIP/someip_examples/event_call/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable client-example"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/client-example.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/client-example.dir/build: client-example

.PHONY : CMakeFiles/client-example.dir/build

CMakeFiles/client-example.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/client-example.dir/cmake_clean.cmake
.PHONY : CMakeFiles/client-example.dir/clean

CMakeFiles/client-example.dir/depend:
	cd /home/mohamed/Desktop/someIP/someip_examples/event_call/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mohamed/Desktop/someIP/someip_examples/event_call /home/mohamed/Desktop/someIP/someip_examples/event_call /home/mohamed/Desktop/someIP/someip_examples/event_call/build /home/mohamed/Desktop/someIP/someip_examples/event_call/build /home/mohamed/Desktop/someIP/someip_examples/event_call/build/CMakeFiles/client-example.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/client-example.dir/depend

