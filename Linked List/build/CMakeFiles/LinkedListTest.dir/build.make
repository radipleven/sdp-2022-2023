# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/radostin/sdp/Linked List"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/radostin/sdp/Linked List/build"

# Include any dependencies generated for this target.
include CMakeFiles/LinkedListTest.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/LinkedListTest.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/LinkedListTest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LinkedListTest.dir/flags.make

CMakeFiles/LinkedListTest.dir/test_LinkedList.cpp.o: CMakeFiles/LinkedListTest.dir/flags.make
CMakeFiles/LinkedListTest.dir/test_LinkedList.cpp.o: ../test_LinkedList.cpp
CMakeFiles/LinkedListTest.dir/test_LinkedList.cpp.o: CMakeFiles/LinkedListTest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/radostin/sdp/Linked List/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/LinkedListTest.dir/test_LinkedList.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/LinkedListTest.dir/test_LinkedList.cpp.o -MF CMakeFiles/LinkedListTest.dir/test_LinkedList.cpp.o.d -o CMakeFiles/LinkedListTest.dir/test_LinkedList.cpp.o -c "/home/radostin/sdp/Linked List/test_LinkedList.cpp"

CMakeFiles/LinkedListTest.dir/test_LinkedList.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LinkedListTest.dir/test_LinkedList.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/radostin/sdp/Linked List/test_LinkedList.cpp" > CMakeFiles/LinkedListTest.dir/test_LinkedList.cpp.i

CMakeFiles/LinkedListTest.dir/test_LinkedList.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LinkedListTest.dir/test_LinkedList.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/radostin/sdp/Linked List/test_LinkedList.cpp" -o CMakeFiles/LinkedListTest.dir/test_LinkedList.cpp.s

# Object files for target LinkedListTest
LinkedListTest_OBJECTS = \
"CMakeFiles/LinkedListTest.dir/test_LinkedList.cpp.o"

# External object files for target LinkedListTest
LinkedListTest_EXTERNAL_OBJECTS =

LinkedListTest: CMakeFiles/LinkedListTest.dir/test_LinkedList.cpp.o
LinkedListTest: CMakeFiles/LinkedListTest.dir/build.make
LinkedListTest: lib/libgtest.a
LinkedListTest: lib/libgtest_main.a
LinkedListTest: lib/libgtest.a
LinkedListTest: CMakeFiles/LinkedListTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/radostin/sdp/Linked List/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable LinkedListTest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LinkedListTest.dir/link.txt --verbose=$(VERBOSE)
	/usr/bin/cmake -D TEST_TARGET=LinkedListTest -D "TEST_EXECUTABLE=/home/radostin/sdp/Linked List/build/LinkedListTest" -D TEST_EXECUTOR= -D "TEST_WORKING_DIR=/home/radostin/sdp/Linked List/build" -D TEST_EXTRA_ARGS= -D TEST_PROPERTIES= -D TEST_PREFIX= -D TEST_SUFFIX= -D TEST_FILTER= -D NO_PRETTY_TYPES=FALSE -D NO_PRETTY_VALUES=FALSE -D TEST_LIST=LinkedListTest_TESTS -D "CTEST_FILE=/home/radostin/sdp/Linked List/build/LinkedListTest[1]_tests.cmake" -D TEST_DISCOVERY_TIMEOUT=5 -D TEST_XML_OUTPUT_DIR= -P /usr/share/cmake-3.22/Modules/GoogleTestAddTests.cmake

# Rule to build all files generated by this target.
CMakeFiles/LinkedListTest.dir/build: LinkedListTest
.PHONY : CMakeFiles/LinkedListTest.dir/build

CMakeFiles/LinkedListTest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/LinkedListTest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/LinkedListTest.dir/clean

CMakeFiles/LinkedListTest.dir/depend:
	cd "/home/radostin/sdp/Linked List/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/radostin/sdp/Linked List" "/home/radostin/sdp/Linked List" "/home/radostin/sdp/Linked List/build" "/home/radostin/sdp/Linked List/build" "/home/radostin/sdp/Linked List/build/CMakeFiles/LinkedListTest.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/LinkedListTest.dir/depend

