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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/Bro4all/CLionProjects/cmpe126s18_labs

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Bro4all/CLionProjects/cmpe126s18_labs/cmake-build-debug

# Include any dependencies generated for this target.
include test/gtest-1.7.0/CMakeFiles/gtest_main.dir/depend.make

# Include the progress variables for this target.
include test/gtest-1.7.0/CMakeFiles/gtest_main.dir/progress.make

# Include the compile flags for this target's objects.
include test/gtest-1.7.0/CMakeFiles/gtest_main.dir/flags.make

test/gtest-1.7.0/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o: test/gtest-1.7.0/CMakeFiles/gtest_main.dir/flags.make
test/gtest-1.7.0/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o: ../test/gtest-1.7.0/src/gtest_main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Bro4all/CLionProjects/cmpe126s18_labs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/gtest-1.7.0/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o"
	cd /Users/Bro4all/CLionProjects/cmpe126s18_labs/cmake-build-debug/test/gtest-1.7.0 && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gtest_main.dir/src/gtest_main.cc.o -c /Users/Bro4all/CLionProjects/cmpe126s18_labs/test/gtest-1.7.0/src/gtest_main.cc

test/gtest-1.7.0/CMakeFiles/gtest_main.dir/src/gtest_main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest_main.dir/src/gtest_main.cc.i"
	cd /Users/Bro4all/CLionProjects/cmpe126s18_labs/cmake-build-debug/test/gtest-1.7.0 && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Bro4all/CLionProjects/cmpe126s18_labs/test/gtest-1.7.0/src/gtest_main.cc > CMakeFiles/gtest_main.dir/src/gtest_main.cc.i

test/gtest-1.7.0/CMakeFiles/gtest_main.dir/src/gtest_main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest_main.dir/src/gtest_main.cc.s"
	cd /Users/Bro4all/CLionProjects/cmpe126s18_labs/cmake-build-debug/test/gtest-1.7.0 && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Bro4all/CLionProjects/cmpe126s18_labs/test/gtest-1.7.0/src/gtest_main.cc -o CMakeFiles/gtest_main.dir/src/gtest_main.cc.s

test/gtest-1.7.0/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.requires:

.PHONY : test/gtest-1.7.0/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.requires

test/gtest-1.7.0/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.provides: test/gtest-1.7.0/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.requires
	$(MAKE) -f test/gtest-1.7.0/CMakeFiles/gtest_main.dir/build.make test/gtest-1.7.0/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.provides.build
.PHONY : test/gtest-1.7.0/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.provides

test/gtest-1.7.0/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.provides.build: test/gtest-1.7.0/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o


# Object files for target gtest_main
gtest_main_OBJECTS = \
"CMakeFiles/gtest_main.dir/src/gtest_main.cc.o"

# External object files for target gtest_main
gtest_main_EXTERNAL_OBJECTS =

test/gtest-1.7.0/libgtest_main.a: test/gtest-1.7.0/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o
test/gtest-1.7.0/libgtest_main.a: test/gtest-1.7.0/CMakeFiles/gtest_main.dir/build.make
test/gtest-1.7.0/libgtest_main.a: test/gtest-1.7.0/CMakeFiles/gtest_main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/Bro4all/CLionProjects/cmpe126s18_labs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libgtest_main.a"
	cd /Users/Bro4all/CLionProjects/cmpe126s18_labs/cmake-build-debug/test/gtest-1.7.0 && $(CMAKE_COMMAND) -P CMakeFiles/gtest_main.dir/cmake_clean_target.cmake
	cd /Users/Bro4all/CLionProjects/cmpe126s18_labs/cmake-build-debug/test/gtest-1.7.0 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gtest_main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/gtest-1.7.0/CMakeFiles/gtest_main.dir/build: test/gtest-1.7.0/libgtest_main.a

.PHONY : test/gtest-1.7.0/CMakeFiles/gtest_main.dir/build

test/gtest-1.7.0/CMakeFiles/gtest_main.dir/requires: test/gtest-1.7.0/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.requires

.PHONY : test/gtest-1.7.0/CMakeFiles/gtest_main.dir/requires

test/gtest-1.7.0/CMakeFiles/gtest_main.dir/clean:
	cd /Users/Bro4all/CLionProjects/cmpe126s18_labs/cmake-build-debug/test/gtest-1.7.0 && $(CMAKE_COMMAND) -P CMakeFiles/gtest_main.dir/cmake_clean.cmake
.PHONY : test/gtest-1.7.0/CMakeFiles/gtest_main.dir/clean

test/gtest-1.7.0/CMakeFiles/gtest_main.dir/depend:
	cd /Users/Bro4all/CLionProjects/cmpe126s18_labs/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Bro4all/CLionProjects/cmpe126s18_labs /Users/Bro4all/CLionProjects/cmpe126s18_labs/test/gtest-1.7.0 /Users/Bro4all/CLionProjects/cmpe126s18_labs/cmake-build-debug /Users/Bro4all/CLionProjects/cmpe126s18_labs/cmake-build-debug/test/gtest-1.7.0 /Users/Bro4all/CLionProjects/cmpe126s18_labs/cmake-build-debug/test/gtest-1.7.0/CMakeFiles/gtest_main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/gtest-1.7.0/CMakeFiles/gtest_main.dir/depend

