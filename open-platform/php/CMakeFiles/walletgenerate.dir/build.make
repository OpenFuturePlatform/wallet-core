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
CMAKE_SOURCE_DIR = /home/elaman/wallet-core/open-platform/php

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/elaman/wallet-core/open-platform/php

# Include any dependencies generated for this target.
include CMakeFiles/walletgenerate.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/walletgenerate.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/walletgenerate.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/walletgenerate.dir/flags.make

CMakeFiles/walletgenerate.dir/walletgenerate.cpp.o: CMakeFiles/walletgenerate.dir/flags.make
CMakeFiles/walletgenerate.dir/walletgenerate.cpp.o: walletgenerate.cpp
CMakeFiles/walletgenerate.dir/walletgenerate.cpp.o: CMakeFiles/walletgenerate.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/elaman/wallet-core/open-platform/php/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/walletgenerate.dir/walletgenerate.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/walletgenerate.dir/walletgenerate.cpp.o -MF CMakeFiles/walletgenerate.dir/walletgenerate.cpp.o.d -o CMakeFiles/walletgenerate.dir/walletgenerate.cpp.o -c /home/elaman/wallet-core/open-platform/php/walletgenerate.cpp

CMakeFiles/walletgenerate.dir/walletgenerate.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/walletgenerate.dir/walletgenerate.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/elaman/wallet-core/open-platform/php/walletgenerate.cpp > CMakeFiles/walletgenerate.dir/walletgenerate.cpp.i

CMakeFiles/walletgenerate.dir/walletgenerate.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/walletgenerate.dir/walletgenerate.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/elaman/wallet-core/open-platform/php/walletgenerate.cpp -o CMakeFiles/walletgenerate.dir/walletgenerate.cpp.s

# Object files for target walletgenerate
walletgenerate_OBJECTS = \
"CMakeFiles/walletgenerate.dir/walletgenerate.cpp.o"

# External object files for target walletgenerate
walletgenerate_EXTERNAL_OBJECTS =

walletgenerate: CMakeFiles/walletgenerate.dir/walletgenerate.cpp.o
walletgenerate: CMakeFiles/walletgenerate.dir/build.make
walletgenerate: CMakeFiles/walletgenerate.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/elaman/wallet-core/open-platform/php/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable walletgenerate"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/walletgenerate.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/walletgenerate.dir/build: walletgenerate
.PHONY : CMakeFiles/walletgenerate.dir/build

CMakeFiles/walletgenerate.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/walletgenerate.dir/cmake_clean.cmake
.PHONY : CMakeFiles/walletgenerate.dir/clean

CMakeFiles/walletgenerate.dir/depend:
	cd /home/elaman/wallet-core/open-platform/php && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/elaman/wallet-core/open-platform/php /home/elaman/wallet-core/open-platform/php /home/elaman/wallet-core/open-platform/php /home/elaman/wallet-core/open-platform/php /home/elaman/wallet-core/open-platform/php/CMakeFiles/walletgenerate.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/walletgenerate.dir/depend

