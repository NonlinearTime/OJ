# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_SOURCE_DIR = /home/haimin/CLionProjects/Flip_Game

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/haimin/CLionProjects/Flip_Game/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Flip_Game.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Flip_Game.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Flip_Game.dir/flags.make

CMakeFiles/Flip_Game.dir/main.cpp.o: CMakeFiles/Flip_Game.dir/flags.make
CMakeFiles/Flip_Game.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/haimin/CLionProjects/Flip_Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Flip_Game.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Flip_Game.dir/main.cpp.o -c /home/haimin/CLionProjects/Flip_Game/main.cpp

CMakeFiles/Flip_Game.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Flip_Game.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/haimin/CLionProjects/Flip_Game/main.cpp > CMakeFiles/Flip_Game.dir/main.cpp.i

CMakeFiles/Flip_Game.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Flip_Game.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/haimin/CLionProjects/Flip_Game/main.cpp -o CMakeFiles/Flip_Game.dir/main.cpp.s

CMakeFiles/Flip_Game.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Flip_Game.dir/main.cpp.o.requires

CMakeFiles/Flip_Game.dir/main.cpp.o.provides: CMakeFiles/Flip_Game.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Flip_Game.dir/build.make CMakeFiles/Flip_Game.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Flip_Game.dir/main.cpp.o.provides

CMakeFiles/Flip_Game.dir/main.cpp.o.provides.build: CMakeFiles/Flip_Game.dir/main.cpp.o


# Object files for target Flip_Game
Flip_Game_OBJECTS = \
"CMakeFiles/Flip_Game.dir/main.cpp.o"

# External object files for target Flip_Game
Flip_Game_EXTERNAL_OBJECTS =

Flip_Game: CMakeFiles/Flip_Game.dir/main.cpp.o
Flip_Game: CMakeFiles/Flip_Game.dir/build.make
Flip_Game: CMakeFiles/Flip_Game.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/haimin/CLionProjects/Flip_Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Flip_Game"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Flip_Game.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Flip_Game.dir/build: Flip_Game

.PHONY : CMakeFiles/Flip_Game.dir/build

CMakeFiles/Flip_Game.dir/requires: CMakeFiles/Flip_Game.dir/main.cpp.o.requires

.PHONY : CMakeFiles/Flip_Game.dir/requires

CMakeFiles/Flip_Game.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Flip_Game.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Flip_Game.dir/clean

CMakeFiles/Flip_Game.dir/depend:
	cd /home/haimin/CLionProjects/Flip_Game/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/haimin/CLionProjects/Flip_Game /home/haimin/CLionProjects/Flip_Game /home/haimin/CLionProjects/Flip_Game/cmake-build-debug /home/haimin/CLionProjects/Flip_Game/cmake-build-debug /home/haimin/CLionProjects/Flip_Game/cmake-build-debug/CMakeFiles/Flip_Game.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Flip_Game.dir/depend

