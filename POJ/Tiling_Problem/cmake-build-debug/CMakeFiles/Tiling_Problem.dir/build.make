# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /home/haimin/clion-2017.2.2/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/haimin/clion-2017.2.2/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/haimin/CLionProjects/Tiling_Problem

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/haimin/CLionProjects/Tiling_Problem/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Tiling_Problem.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Tiling_Problem.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Tiling_Problem.dir/flags.make

CMakeFiles/Tiling_Problem.dir/main.cpp.o: CMakeFiles/Tiling_Problem.dir/flags.make
CMakeFiles/Tiling_Problem.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/haimin/CLionProjects/Tiling_Problem/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Tiling_Problem.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tiling_Problem.dir/main.cpp.o -c /home/haimin/CLionProjects/Tiling_Problem/main.cpp

CMakeFiles/Tiling_Problem.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tiling_Problem.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/haimin/CLionProjects/Tiling_Problem/main.cpp > CMakeFiles/Tiling_Problem.dir/main.cpp.i

CMakeFiles/Tiling_Problem.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tiling_Problem.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/haimin/CLionProjects/Tiling_Problem/main.cpp -o CMakeFiles/Tiling_Problem.dir/main.cpp.s

CMakeFiles/Tiling_Problem.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Tiling_Problem.dir/main.cpp.o.requires

CMakeFiles/Tiling_Problem.dir/main.cpp.o.provides: CMakeFiles/Tiling_Problem.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Tiling_Problem.dir/build.make CMakeFiles/Tiling_Problem.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Tiling_Problem.dir/main.cpp.o.provides

CMakeFiles/Tiling_Problem.dir/main.cpp.o.provides.build: CMakeFiles/Tiling_Problem.dir/main.cpp.o


# Object files for target Tiling_Problem
Tiling_Problem_OBJECTS = \
"CMakeFiles/Tiling_Problem.dir/main.cpp.o"

# External object files for target Tiling_Problem
Tiling_Problem_EXTERNAL_OBJECTS =

Tiling_Problem: CMakeFiles/Tiling_Problem.dir/main.cpp.o
Tiling_Problem: CMakeFiles/Tiling_Problem.dir/build.make
Tiling_Problem: CMakeFiles/Tiling_Problem.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/haimin/CLionProjects/Tiling_Problem/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Tiling_Problem"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Tiling_Problem.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Tiling_Problem.dir/build: Tiling_Problem

.PHONY : CMakeFiles/Tiling_Problem.dir/build

CMakeFiles/Tiling_Problem.dir/requires: CMakeFiles/Tiling_Problem.dir/main.cpp.o.requires

.PHONY : CMakeFiles/Tiling_Problem.dir/requires

CMakeFiles/Tiling_Problem.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Tiling_Problem.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Tiling_Problem.dir/clean

CMakeFiles/Tiling_Problem.dir/depend:
	cd /home/haimin/CLionProjects/Tiling_Problem/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/haimin/CLionProjects/Tiling_Problem /home/haimin/CLionProjects/Tiling_Problem /home/haimin/CLionProjects/Tiling_Problem/cmake-build-debug /home/haimin/CLionProjects/Tiling_Problem/cmake-build-debug /home/haimin/CLionProjects/Tiling_Problem/cmake-build-debug/CMakeFiles/Tiling_Problem.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Tiling_Problem.dir/depend

