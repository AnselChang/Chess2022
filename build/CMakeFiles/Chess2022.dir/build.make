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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.22.3/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.22.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/anselchang/Library/Mobile Documents/com~apple~CloudDocs/Personal Projects/Chess2022"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/anselchang/Library/Mobile Documents/com~apple~CloudDocs/Personal Projects/Chess2022/build"

# Include any dependencies generated for this target.
include CMakeFiles/Chess2022.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Chess2022.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Chess2022.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Chess2022.dir/flags.make

CMakeFiles/Chess2022.dir/src/main.cpp.o: CMakeFiles/Chess2022.dir/flags.make
CMakeFiles/Chess2022.dir/src/main.cpp.o: ../src/main.cpp
CMakeFiles/Chess2022.dir/src/main.cpp.o: CMakeFiles/Chess2022.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/anselchang/Library/Mobile Documents/com~apple~CloudDocs/Personal Projects/Chess2022/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Chess2022.dir/src/main.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Chess2022.dir/src/main.cpp.o -MF CMakeFiles/Chess2022.dir/src/main.cpp.o.d -o CMakeFiles/Chess2022.dir/src/main.cpp.o -c "/Users/anselchang/Library/Mobile Documents/com~apple~CloudDocs/Personal Projects/Chess2022/src/main.cpp"

CMakeFiles/Chess2022.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Chess2022.dir/src/main.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/anselchang/Library/Mobile Documents/com~apple~CloudDocs/Personal Projects/Chess2022/src/main.cpp" > CMakeFiles/Chess2022.dir/src/main.cpp.i

CMakeFiles/Chess2022.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Chess2022.dir/src/main.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/anselchang/Library/Mobile Documents/com~apple~CloudDocs/Personal Projects/Chess2022/src/main.cpp" -o CMakeFiles/Chess2022.dir/src/main.cpp.s

CMakeFiles/Chess2022.dir/src/DataStructures/Game.cpp.o: CMakeFiles/Chess2022.dir/flags.make
CMakeFiles/Chess2022.dir/src/DataStructures/Game.cpp.o: ../src/DataStructures/Game.cpp
CMakeFiles/Chess2022.dir/src/DataStructures/Game.cpp.o: CMakeFiles/Chess2022.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/anselchang/Library/Mobile Documents/com~apple~CloudDocs/Personal Projects/Chess2022/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Chess2022.dir/src/DataStructures/Game.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Chess2022.dir/src/DataStructures/Game.cpp.o -MF CMakeFiles/Chess2022.dir/src/DataStructures/Game.cpp.o.d -o CMakeFiles/Chess2022.dir/src/DataStructures/Game.cpp.o -c "/Users/anselchang/Library/Mobile Documents/com~apple~CloudDocs/Personal Projects/Chess2022/src/DataStructures/Game.cpp"

CMakeFiles/Chess2022.dir/src/DataStructures/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Chess2022.dir/src/DataStructures/Game.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/anselchang/Library/Mobile Documents/com~apple~CloudDocs/Personal Projects/Chess2022/src/DataStructures/Game.cpp" > CMakeFiles/Chess2022.dir/src/DataStructures/Game.cpp.i

CMakeFiles/Chess2022.dir/src/DataStructures/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Chess2022.dir/src/DataStructures/Game.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/anselchang/Library/Mobile Documents/com~apple~CloudDocs/Personal Projects/Chess2022/src/DataStructures/Game.cpp" -o CMakeFiles/Chess2022.dir/src/DataStructures/Game.cpp.s

# Object files for target Chess2022
Chess2022_OBJECTS = \
"CMakeFiles/Chess2022.dir/src/main.cpp.o" \
"CMakeFiles/Chess2022.dir/src/DataStructures/Game.cpp.o"

# External object files for target Chess2022
Chess2022_EXTERNAL_OBJECTS =

Chess2022: CMakeFiles/Chess2022.dir/src/main.cpp.o
Chess2022: CMakeFiles/Chess2022.dir/src/DataStructures/Game.cpp.o
Chess2022: CMakeFiles/Chess2022.dir/build.make
Chess2022: CMakeFiles/Chess2022.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/anselchang/Library/Mobile Documents/com~apple~CloudDocs/Personal Projects/Chess2022/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Chess2022"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Chess2022.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Chess2022.dir/build: Chess2022
.PHONY : CMakeFiles/Chess2022.dir/build

CMakeFiles/Chess2022.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Chess2022.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Chess2022.dir/clean

CMakeFiles/Chess2022.dir/depend:
	cd "/Users/anselchang/Library/Mobile Documents/com~apple~CloudDocs/Personal Projects/Chess2022/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/anselchang/Library/Mobile Documents/com~apple~CloudDocs/Personal Projects/Chess2022" "/Users/anselchang/Library/Mobile Documents/com~apple~CloudDocs/Personal Projects/Chess2022" "/Users/anselchang/Library/Mobile Documents/com~apple~CloudDocs/Personal Projects/Chess2022/build" "/Users/anselchang/Library/Mobile Documents/com~apple~CloudDocs/Personal Projects/Chess2022/build" "/Users/anselchang/Library/Mobile Documents/com~apple~CloudDocs/Personal Projects/Chess2022/build/CMakeFiles/Chess2022.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Chess2022.dir/depend

