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
CMAKE_SOURCE_DIR = /home/haimin/CLionProjects/Count_Color

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/haimin/CLionProjects/Count_Color/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Count_Color.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Count_Color.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Count_Color.dir/flags.make

CMakeFiles/Count_Color.dir/main.cpp.o: CMakeFiles/Count_Color.dir/flags.make
CMakeFiles/Count_Color.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/haimin/CLionProjects/Count_Color/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Count_Color.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Count_Color.dir/main.cpp.o -c /home/haimin/CLionProjects/Count_Color/main.cpp

CMakeFiles/Count_Color.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Count_Color.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/haimin/CLionProjects/Count_Color/main.cpp > CMakeFiles/Count_Color.dir/main.cpp.i

CMakeFiles/Count_Color.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Count_Color.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/haimin/CLionProjects/Count_Color/main.cpp -o CMakeFiles/Count_Color.dir/main.cpp.s

CMakeFiles/Count_Color.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Count_Color.dir/main.cpp.o.requires

CMakeFiles/Count_Color.dir/main.cpp.o.provides: CMakeFiles/Count_Color.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Count_Color.dir/build.make CMakeFiles/Count_Color.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Count_Color.dir/main.cpp.o.provides

CMakeFiles/Count_Color.dir/main.cpp.o.provides.build: CMakeFiles/Count_Color.dir/main.cpp.o


# Object files for target Count_Color
Count_Color_OBJECTS = \
"CMakeFiles/Count_Color.dir/main.cpp.o"

# External object files for target Count_Color
Count_Color_EXTERNAL_OBJECTS =

Count_Color: CMakeFiles/Count_Color.dir/main.cpp.o
Count_Color: CMakeFiles/Count_Color.dir/build.make
Count_Color: CMakeFiles/Count_Color.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/haimin/CLionProjects/Count_Color/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Count_Color"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Count_Color.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Count_Color.dir/build: Count_Color

.PHONY : CMakeFiles/Count_Color.dir/build

CMakeFiles/Count_Color.dir/requires: CMakeFiles/Count_Color.dir/main.cpp.o.requires

.PHONY : CMakeFiles/Count_Color.dir/requires

CMakeFiles/Count_Color.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Count_Color.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Count_Color.dir/clean

CMakeFiles/Count_Color.dir/depend:
	cd /home/haimin/CLionProjects/Count_Color/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/haimin/CLionProjects/Count_Color /home/haimin/CLionProjects/Count_Color /home/haimin/CLionProjects/Count_Color/cmake-build-debug /home/haimin/CLionProjects/Count_Color/cmake-build-debug /home/haimin/CLionProjects/Count_Color/cmake-build-debug/CMakeFiles/Count_Color.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Count_Color.dir/depend

