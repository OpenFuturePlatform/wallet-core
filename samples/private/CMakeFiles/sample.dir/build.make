# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/elaman/wallet-core/samples/private

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/elaman/wallet-core/samples/private

# Include any dependencies generated for this target.
include CMakeFiles/sample.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/sample.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/sample.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sample.dir/flags.make

CMakeFiles/sample.dir/sample.cpp.o: CMakeFiles/sample.dir/flags.make
CMakeFiles/sample.dir/sample.cpp.o: sample.cpp
CMakeFiles/sample.dir/sample.cpp.o: CMakeFiles/sample.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/elaman/wallet-core/samples/private/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sample.dir/sample.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sample.dir/sample.cpp.o -MF CMakeFiles/sample.dir/sample.cpp.o.d -o CMakeFiles/sample.dir/sample.cpp.o -c /home/elaman/wallet-core/samples/private/sample.cpp

CMakeFiles/sample.dir/sample.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sample.dir/sample.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/elaman/wallet-core/samples/private/sample.cpp > CMakeFiles/sample.dir/sample.cpp.i

CMakeFiles/sample.dir/sample.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sample.dir/sample.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/elaman/wallet-core/samples/private/sample.cpp -o CMakeFiles/sample.dir/sample.cpp.s

# Object files for target sample
sample_OBJECTS = \
"CMakeFiles/sample.dir/sample.cpp.o"

# External object files for target sample
sample_EXTERNAL_OBJECTS =

sample: CMakeFiles/sample.dir/sample.cpp.o
sample: CMakeFiles/sample.dir/build.make
sample: CMakeFiles/sample.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/elaman/wallet-core/samples/private/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable sample"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sample.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sample.dir/build: sample
.PHONY : CMakeFiles/sample.dir/build

CMakeFiles/sample.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sample.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sample.dir/clean

CMakeFiles/sample.dir/depend:
	cd /home/elaman/wallet-core/samples/private && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/elaman/wallet-core/samples/private /home/elaman/wallet-core/samples/private /home/elaman/wallet-core/samples/private /home/elaman/wallet-core/samples/private /home/elaman/wallet-core/samples/private/CMakeFiles/sample.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sample.dir/depend

