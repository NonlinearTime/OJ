# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /home/haines/clion-2018.2.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/haines/clion-2018.2.3/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/haines/Documents/ACM/CCF/201312-04

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/haines/Documents/ACM/CCF/201312-04/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/201312_04.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/201312_04.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/201312_04.dir/flags.make

CMakeFiles/201312_04.dir/main.cpp.o: CMakeFiles/201312_04.dir/flags.make
CMakeFiles/201312_04.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/haines/Documents/ACM/CCF/201312-04/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/201312_04.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/201312_04.dir/main.cpp.o -c /home/haines/Documents/ACM/CCF/201312-04/main.cpp

CMakeFiles/201312_04.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/201312_04.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/haines/Documents/ACM/CCF/201312-04/main.cpp > CMakeFiles/201312_04.dir/main.cpp.i

CMakeFiles/201312_04.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/201312_04.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/haines/Documents/ACM/CCF/201312-04/main.cpp -o CMakeFiles/201312_04.dir/main.cpp.s

# Object files for target 201312_04
201312_04_OBJECTS = \
"CMakeFiles/201312_04.dir/main.cpp.o"

# External object files for target 201312_04
201312_04_EXTERNAL_OBJECTS =

201312_04: CMakeFiles/201312_04.dir/main.cpp.o
201312_04: CMakeFiles/201312_04.dir/build.make
201312_04: CMakeFiles/201312_04.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/haines/Documents/ACM/CCF/201312-04/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 201312_04"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/201312_04.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/201312_04.dir/build: 201312_04

.PHONY : CMakeFiles/201312_04.dir/build

CMakeFiles/201312_04.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/201312_04.dir/cmake_clean.cmake
.PHONY : CMakeFiles/201312_04.dir/clean

CMakeFiles/201312_04.dir/depend:
	cd /home/haines/Documents/ACM/CCF/201312-04/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/haines/Documents/ACM/CCF/201312-04 /home/haines/Documents/ACM/CCF/201312-04 /home/haines/Documents/ACM/CCF/201312-04/cmake-build-debug /home/haines/Documents/ACM/CCF/201312-04/cmake-build-debug /home/haines/Documents/ACM/CCF/201312-04/cmake-build-debug/CMakeFiles/201312_04.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/201312_04.dir/depend
