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
CMAKE_SOURCE_DIR = /home/haimin/CLionProjects/MooFest

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/haimin/CLionProjects/MooFest/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/MooFest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MooFest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MooFest.dir/flags.make

CMakeFiles/MooFest.dir/main.cpp.o: CMakeFiles/MooFest.dir/flags.make
CMakeFiles/MooFest.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/haimin/CLionProjects/MooFest/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MooFest.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MooFest.dir/main.cpp.o -c /home/haimin/CLionProjects/MooFest/main.cpp

CMakeFiles/MooFest.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MooFest.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/haimin/CLionProjects/MooFest/main.cpp > CMakeFiles/MooFest.dir/main.cpp.i

CMakeFiles/MooFest.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MooFest.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/haimin/CLionProjects/MooFest/main.cpp -o CMakeFiles/MooFest.dir/main.cpp.s

CMakeFiles/MooFest.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/MooFest.dir/main.cpp.o.requires

CMakeFiles/MooFest.dir/main.cpp.o.provides: CMakeFiles/MooFest.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/MooFest.dir/build.make CMakeFiles/MooFest.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/MooFest.dir/main.cpp.o.provides

CMakeFiles/MooFest.dir/main.cpp.o.provides.build: CMakeFiles/MooFest.dir/main.cpp.o


# Object files for target MooFest
MooFest_OBJECTS = \
"CMakeFiles/MooFest.dir/main.cpp.o"

# External object files for target MooFest
MooFest_EXTERNAL_OBJECTS =

MooFest: CMakeFiles/MooFest.dir/main.cpp.o
MooFest: CMakeFiles/MooFest.dir/build.make
MooFest: CMakeFiles/MooFest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/haimin/CLionProjects/MooFest/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable MooFest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MooFest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MooFest.dir/build: MooFest

.PHONY : CMakeFiles/MooFest.dir/build

CMakeFiles/MooFest.dir/requires: CMakeFiles/MooFest.dir/main.cpp.o.requires

.PHONY : CMakeFiles/MooFest.dir/requires

CMakeFiles/MooFest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MooFest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MooFest.dir/clean

CMakeFiles/MooFest.dir/depend:
	cd /home/haimin/CLionProjects/MooFest/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/haimin/CLionProjects/MooFest /home/haimin/CLionProjects/MooFest /home/haimin/CLionProjects/MooFest/cmake-build-debug /home/haimin/CLionProjects/MooFest/cmake-build-debug /home/haimin/CLionProjects/MooFest/cmake-build-debug/CMakeFiles/MooFest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MooFest.dir/depend

