# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /home/haines/clion-2018.1.1/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/haines/clion-2018.1.1/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/haines/Documents/ACM/NiuKe/btree

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/haines/Documents/ACM/NiuKe/btree/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/btree.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/btree.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/btree.dir/flags.make

CMakeFiles/btree.dir/main.cpp.o: CMakeFiles/btree.dir/flags.make
CMakeFiles/btree.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/haines/Documents/ACM/NiuKe/btree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/btree.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/btree.dir/main.cpp.o -c /home/haines/Documents/ACM/NiuKe/btree/main.cpp

CMakeFiles/btree.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/btree.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/haines/Documents/ACM/NiuKe/btree/main.cpp > CMakeFiles/btree.dir/main.cpp.i

CMakeFiles/btree.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/btree.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/haines/Documents/ACM/NiuKe/btree/main.cpp -o CMakeFiles/btree.dir/main.cpp.s

CMakeFiles/btree.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/btree.dir/main.cpp.o.requires

CMakeFiles/btree.dir/main.cpp.o.provides: CMakeFiles/btree.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/btree.dir/build.make CMakeFiles/btree.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/btree.dir/main.cpp.o.provides

CMakeFiles/btree.dir/main.cpp.o.provides.build: CMakeFiles/btree.dir/main.cpp.o


# Object files for target btree
btree_OBJECTS = \
"CMakeFiles/btree.dir/main.cpp.o"

# External object files for target btree
btree_EXTERNAL_OBJECTS =

btree: CMakeFiles/btree.dir/main.cpp.o
btree: CMakeFiles/btree.dir/build.make
btree: CMakeFiles/btree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/haines/Documents/ACM/NiuKe/btree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable btree"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/btree.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/btree.dir/build: btree

.PHONY : CMakeFiles/btree.dir/build

CMakeFiles/btree.dir/requires: CMakeFiles/btree.dir/main.cpp.o.requires

.PHONY : CMakeFiles/btree.dir/requires

CMakeFiles/btree.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/btree.dir/cmake_clean.cmake
.PHONY : CMakeFiles/btree.dir/clean

CMakeFiles/btree.dir/depend:
	cd /home/haines/Documents/ACM/NiuKe/btree/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/haines/Documents/ACM/NiuKe/btree /home/haines/Documents/ACM/NiuKe/btree /home/haines/Documents/ACM/NiuKe/btree/cmake-build-debug /home/haines/Documents/ACM/NiuKe/btree/cmake-build-debug /home/haines/Documents/ACM/NiuKe/btree/cmake-build-debug/CMakeFiles/btree.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/btree.dir/depend
