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
CMAKE_SOURCE_DIR = "/mnt/c/Users/shubh/OneDrive/Documents/CSCE 221 FR/CSCE-221H-S23-Lab"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/c/Users/shubh/OneDrive/Documents/CSCE 221 FR/CSCE-221H-S23-Lab/test"

# Include any dependencies generated for this target.
include test/CMakeFiles/test_vector.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/CMakeFiles/test_vector.dir/compiler_depend.make

# Include the progress variables for this target.
include test/CMakeFiles/test_vector.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/test_vector.dir/flags.make

test/CMakeFiles/test_vector.dir/test_vector.cpp.o: test/CMakeFiles/test_vector.dir/flags.make
test/CMakeFiles/test_vector.dir/test_vector.cpp.o: test_vector.cpp
test/CMakeFiles/test_vector.dir/test_vector.cpp.o: test/CMakeFiles/test_vector.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/shubh/OneDrive/Documents/CSCE 221 FR/CSCE-221H-S23-Lab/test/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/test_vector.dir/test_vector.cpp.o"
	cd "/mnt/c/Users/shubh/OneDrive/Documents/CSCE 221 FR/CSCE-221H-S23-Lab/test/test" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/test_vector.dir/test_vector.cpp.o -MF CMakeFiles/test_vector.dir/test_vector.cpp.o.d -o CMakeFiles/test_vector.dir/test_vector.cpp.o -c "/mnt/c/Users/shubh/OneDrive/Documents/CSCE 221 FR/CSCE-221H-S23-Lab/test/test_vector.cpp"

test/CMakeFiles/test_vector.dir/test_vector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_vector.dir/test_vector.cpp.i"
	cd "/mnt/c/Users/shubh/OneDrive/Documents/CSCE 221 FR/CSCE-221H-S23-Lab/test/test" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/Users/shubh/OneDrive/Documents/CSCE 221 FR/CSCE-221H-S23-Lab/test/test_vector.cpp" > CMakeFiles/test_vector.dir/test_vector.cpp.i

test/CMakeFiles/test_vector.dir/test_vector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_vector.dir/test_vector.cpp.s"
	cd "/mnt/c/Users/shubh/OneDrive/Documents/CSCE 221 FR/CSCE-221H-S23-Lab/test/test" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/Users/shubh/OneDrive/Documents/CSCE 221 FR/CSCE-221H-S23-Lab/test/test_vector.cpp" -o CMakeFiles/test_vector.dir/test_vector.cpp.s

# Object files for target test_vector
test_vector_OBJECTS = \
"CMakeFiles/test_vector.dir/test_vector.cpp.o"

# External object files for target test_vector
test_vector_EXTERNAL_OBJECTS =

test/test_vector: test/CMakeFiles/test_vector.dir/test_vector.cpp.o
test/test_vector: test/CMakeFiles/test_vector.dir/build.make
test/test_vector: test/CMakeFiles/test_vector.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/mnt/c/Users/shubh/OneDrive/Documents/CSCE 221 FR/CSCE-221H-S23-Lab/test/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_vector"
	cd "/mnt/c/Users/shubh/OneDrive/Documents/CSCE 221 FR/CSCE-221H-S23-Lab/test/test" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_vector.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/test_vector.dir/build: test/test_vector
.PHONY : test/CMakeFiles/test_vector.dir/build

test/CMakeFiles/test_vector.dir/clean:
	cd "/mnt/c/Users/shubh/OneDrive/Documents/CSCE 221 FR/CSCE-221H-S23-Lab/test/test" && $(CMAKE_COMMAND) -P CMakeFiles/test_vector.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/test_vector.dir/clean

test/CMakeFiles/test_vector.dir/depend:
	cd "/mnt/c/Users/shubh/OneDrive/Documents/CSCE 221 FR/CSCE-221H-S23-Lab/test" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/c/Users/shubh/OneDrive/Documents/CSCE 221 FR/CSCE-221H-S23-Lab" "/mnt/c/Users/shubh/OneDrive/Documents/CSCE 221 FR/CSCE-221H-S23-Lab/test" "/mnt/c/Users/shubh/OneDrive/Documents/CSCE 221 FR/CSCE-221H-S23-Lab/test" "/mnt/c/Users/shubh/OneDrive/Documents/CSCE 221 FR/CSCE-221H-S23-Lab/test/test" "/mnt/c/Users/shubh/OneDrive/Documents/CSCE 221 FR/CSCE-221H-S23-Lab/test/test/CMakeFiles/test_vector.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : test/CMakeFiles/test_vector.dir/depend
