# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/robotmaster/argos3-installation/habanero/AutoMoDe-habanero

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/robotmaster/argos3-installation/habanero/AutoMoDe-habanero/build

# Include any dependencies generated for this target.
include src/CMakeFiles/automode_main.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/automode_main.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/automode_main.dir/flags.make

src/CMakeFiles/automode_main.dir/automode_main_autogen/mocs_compilation.cpp.o: src/CMakeFiles/automode_main.dir/flags.make
src/CMakeFiles/automode_main.dir/automode_main_autogen/mocs_compilation.cpp.o: src/automode_main_autogen/mocs_compilation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/robotmaster/argos3-installation/habanero/AutoMoDe-habanero/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/automode_main.dir/automode_main_autogen/mocs_compilation.cpp.o"
	cd /home/robotmaster/argos3-installation/habanero/AutoMoDe-habanero/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/automode_main.dir/automode_main_autogen/mocs_compilation.cpp.o -c /home/robotmaster/argos3-installation/habanero/AutoMoDe-habanero/build/src/automode_main_autogen/mocs_compilation.cpp

src/CMakeFiles/automode_main.dir/automode_main_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/automode_main.dir/automode_main_autogen/mocs_compilation.cpp.i"
	cd /home/robotmaster/argos3-installation/habanero/AutoMoDe-habanero/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/robotmaster/argos3-installation/habanero/AutoMoDe-habanero/build/src/automode_main_autogen/mocs_compilation.cpp > CMakeFiles/automode_main.dir/automode_main_autogen/mocs_compilation.cpp.i

src/CMakeFiles/automode_main.dir/automode_main_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/automode_main.dir/automode_main_autogen/mocs_compilation.cpp.s"
	cd /home/robotmaster/argos3-installation/habanero/AutoMoDe-habanero/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/robotmaster/argos3-installation/habanero/AutoMoDe-habanero/build/src/automode_main_autogen/mocs_compilation.cpp -o CMakeFiles/automode_main.dir/automode_main_autogen/mocs_compilation.cpp.s

src/CMakeFiles/automode_main.dir/AutoMoDeMain.cpp.o: src/CMakeFiles/automode_main.dir/flags.make
src/CMakeFiles/automode_main.dir/AutoMoDeMain.cpp.o: ../src/AutoMoDeMain.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/robotmaster/argos3-installation/habanero/AutoMoDe-habanero/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/automode_main.dir/AutoMoDeMain.cpp.o"
	cd /home/robotmaster/argos3-installation/habanero/AutoMoDe-habanero/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/automode_main.dir/AutoMoDeMain.cpp.o -c /home/robotmaster/argos3-installation/habanero/AutoMoDe-habanero/src/AutoMoDeMain.cpp

src/CMakeFiles/automode_main.dir/AutoMoDeMain.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/automode_main.dir/AutoMoDeMain.cpp.i"
	cd /home/robotmaster/argos3-installation/habanero/AutoMoDe-habanero/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/robotmaster/argos3-installation/habanero/AutoMoDe-habanero/src/AutoMoDeMain.cpp > CMakeFiles/automode_main.dir/AutoMoDeMain.cpp.i

src/CMakeFiles/automode_main.dir/AutoMoDeMain.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/automode_main.dir/AutoMoDeMain.cpp.s"
	cd /home/robotmaster/argos3-installation/habanero/AutoMoDe-habanero/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/robotmaster/argos3-installation/habanero/AutoMoDe-habanero/src/AutoMoDeMain.cpp -o CMakeFiles/automode_main.dir/AutoMoDeMain.cpp.s

# Object files for target automode_main
automode_main_OBJECTS = \
"CMakeFiles/automode_main.dir/automode_main_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/automode_main.dir/AutoMoDeMain.cpp.o"

# External object files for target automode_main
automode_main_EXTERNAL_OBJECTS =

../bin/automode_main: src/CMakeFiles/automode_main.dir/automode_main_autogen/mocs_compilation.cpp.o
../bin/automode_main: src/CMakeFiles/automode_main.dir/AutoMoDeMain.cpp.o
../bin/automode_main: src/CMakeFiles/automode_main.dir/build.make
../bin/automode_main: src/libautomode.so
../bin/automode_main: src/CMakeFiles/automode_main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/robotmaster/argos3-installation/habanero/AutoMoDe-habanero/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ../../bin/automode_main"
	cd /home/robotmaster/argos3-installation/habanero/AutoMoDe-habanero/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/automode_main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/automode_main.dir/build: ../bin/automode_main

.PHONY : src/CMakeFiles/automode_main.dir/build

src/CMakeFiles/automode_main.dir/clean:
	cd /home/robotmaster/argos3-installation/habanero/AutoMoDe-habanero/build/src && $(CMAKE_COMMAND) -P CMakeFiles/automode_main.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/automode_main.dir/clean

src/CMakeFiles/automode_main.dir/depend:
	cd /home/robotmaster/argos3-installation/habanero/AutoMoDe-habanero/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/robotmaster/argos3-installation/habanero/AutoMoDe-habanero /home/robotmaster/argos3-installation/habanero/AutoMoDe-habanero/src /home/robotmaster/argos3-installation/habanero/AutoMoDe-habanero/build /home/robotmaster/argos3-installation/habanero/AutoMoDe-habanero/build/src /home/robotmaster/argos3-installation/habanero/AutoMoDe-habanero/build/src/CMakeFiles/automode_main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/automode_main.dir/depend

