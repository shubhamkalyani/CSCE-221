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
include src/CMakeFiles/lab03.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/lab03.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/lab03.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/lab03.dir/flags.make

src/CMakeFiles/lab03.dir/lab03.cpp.o: src/CMakeFiles/lab03.dir/flags.make
src/CMakeFiles/lab03.dir/lab03.cpp.o: ../src/lab03.cpp
src/CMakeFiles/lab03.dir/lab03.cpp.o: src/CMakeFiles/lab03.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/shubh/OneDrive/Documents/CSCE 221 FR/CSCE-221H-S23-Lab/test/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/lab03.dir/lab03.cpp.o"
	cd "/mnt/c/Users/shubh/OneDrive/Documents/CSCE 221 FR/CSCE-221H-S23-Lab/test/src" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/lab03.dir/lab03.cpp.o -MF CMakeFiles/lab03.dir/lab03.cpp.o.d -o CMakeFiles/lab03.dir/lab03.cpp.o -c "/mnt/c/Users/shubh/OneDrive/Documents/CSCE 221 FR/CSCE-221H-S23-Lab/src/lab03.cpp"

src/CMakeFiles/lab03.dir/lab03.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab03.dir/lab03.cpp.i"
	cd "/mnt/c/Users/shubh/OneDrive/Documents/CSCE 221 FR/CSCE-221H-S23-Lab/test/src" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/Users/shubh/OneDrive/Documents/CSCE 221 FR/CSCE-221H-S23-Lab/src/lab03.cpp" > CMakeFiles/lab03.dir/lab03.cpp.i

src/CMakeFiles/lab03.dir/lab03.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab03.dir/lab03.cpp.s"
	cd "/mnt/c/Users/shubh/OneDrive/Documents/CSCE 221 FR/CSCE-221H-S23-Lab/test/src" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/Users/shubh/OneDrive/Documents/CSCE 221 FR/CSCE-221H-S23-Lab/src/lab03.cpp" -o CMakeFiles/lab03.dir/lab03.cpp.s

# Object files for target lab03
lab03_OBJECTS = \
"CMakeFiles/lab03.dir/lab03.cpp.o"

# External object files for target lab03
lab03_EXTERNAL_OBJECTS =

src/lab03: src/CMakeFiles/lab03.dir/lab03.cpp.o
src/lab03: src/CMakeFiles/lab03.dir/build.make
src/lab03: src/CMakeFiles/lab03.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/mnt/c/Users/shubh/OneDrive/Documents/CSCE 221 FR/CSCE-221H-S23-Lab/test/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable lab03"
	cd "/mnt/c/Users/shubh/OneDrive/Documents/CSCE 221 FR/CSCE-221H-S23-Lab/test/src" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab03.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/lab03.dir/build: src/lab03
.PHONY : src/CMakeFiles/lab03.dir/build

src/CMakeFiles/lab03.dir/clean:
	cd "/mnt/c/Users/shubh/OneDrive/Documents/CSCE 221 FR/CSCE-221H-S23-Lab/test/src" && $(CMAKE_COMMAND) -P CMakeFiles/lab03.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/lab03.dir/clean

src/CMakeFiles/lab03.dir/depend:
	cd "/mnt/c/Users/shubh/OneDrive/Documents/CSCE 221 FR/CSCE-221H-S23-Lab/test" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/c/Users/shubh/OneDrive/Documents/CSCE 221 FR/CSCE-221H-S23-Lab" "/mnt/c/Users/shubh/OneDrive/Documents/CSCE 221 FR/CSCE-221H-S23-Lab/src" "/mnt/c/Users/shubh/OneDrive/Documents/CSCE 221 FR/CSCE-221H-S23-Lab/test" "/mnt/c/Users/shubh/OneDrive/Documents/CSCE 221 FR/CSCE-221H-S23-Lab/test/src" "/mnt/c/Users/shubh/OneDrive/Documents/CSCE 221 FR/CSCE-221H-S23-Lab/test/src/CMakeFiles/lab03.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : src/CMakeFiles/lab03.dir/depend

