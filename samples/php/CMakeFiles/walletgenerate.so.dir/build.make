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
CMAKE_SOURCE_DIR = /home/elaman/wallet-core/samples/php

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/elaman/wallet-core/samples/php

# Include any dependencies generated for this target.
include CMakeFiles/walletgenerate.so.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/walletgenerate.so.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/walletgenerate.so.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/walletgenerate.so.dir/flags.make

CMakeFiles/walletgenerate.so.dir/walletgenerate.cpp.o: CMakeFiles/walletgenerate.so.dir/flags.make
CMakeFiles/walletgenerate.so.dir/walletgenerate.cpp.o: walletgenerate.cpp
CMakeFiles/walletgenerate.so.dir/walletgenerate.cpp.o: CMakeFiles/walletgenerate.so.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/elaman/wallet-core/samples/php/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/walletgenerate.so.dir/walletgenerate.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/walletgenerate.so.dir/walletgenerate.cpp.o -MF CMakeFiles/walletgenerate.so.dir/walletgenerate.cpp.o.d -o CMakeFiles/walletgenerate.so.dir/walletgenerate.cpp.o -c /home/elaman/wallet-core/samples/php/walletgenerate.cpp

CMakeFiles/walletgenerate.so.dir/walletgenerate.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/walletgenerate.so.dir/walletgenerate.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/elaman/wallet-core/samples/php/walletgenerate.cpp > CMakeFiles/walletgenerate.so.dir/walletgenerate.cpp.i

CMakeFiles/walletgenerate.so.dir/walletgenerate.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/walletgenerate.so.dir/walletgenerate.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/elaman/wallet-core/samples/php/walletgenerate.cpp -o CMakeFiles/walletgenerate.so.dir/walletgenerate.cpp.s

# Object files for target walletgenerate.so
walletgenerate_so_OBJECTS = \
"CMakeFiles/walletgenerate.so.dir/walletgenerate.cpp.o"

# External object files for target walletgenerate.so
walletgenerate_so_EXTERNAL_OBJECTS =

walletgenerate.so: CMakeFiles/walletgenerate.so.dir/walletgenerate.cpp.o
walletgenerate.so: CMakeFiles/walletgenerate.so.dir/build.make
walletgenerate.so: CMakeFiles/walletgenerate.so.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/elaman/wallet-core/samples/php/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable walletgenerate.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/walletgenerate.so.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/walletgenerate.so.dir/build: walletgenerate.so
.PHONY : CMakeFiles/walletgenerate.so.dir/build

CMakeFiles/walletgenerate.so.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/walletgenerate.so.dir/cmake_clean.cmake
.PHONY : CMakeFiles/walletgenerate.so.dir/clean

CMakeFiles/walletgenerate.so.dir/depend:
	cd /home/elaman/wallet-core/samples/php && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/elaman/wallet-core/samples/php /home/elaman/wallet-core/samples/php /home/elaman/wallet-core/samples/php /home/elaman/wallet-core/samples/php /home/elaman/wallet-core/samples/php/CMakeFiles/walletgenerate.so.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/walletgenerate.so.dir/depend

