# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.16

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\IDEA\CLion 2020.1.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\IDEA\CLion 2020.1.3\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\garfield\study\data structure\dpll"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\garfield\study\data structure\dpll\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/dpll.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/dpll.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/dpll.dir/flags.make

CMakeFiles/dpll.dir/main.cpp.obj: CMakeFiles/dpll.dir/flags.make
CMakeFiles/dpll.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\garfield\study\data structure\dpll\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/dpll.dir/main.cpp.obj"
	C:\PROGRA~1\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\dpll.dir\main.cpp.obj -c "D:\garfield\study\data structure\dpll\main.cpp"

CMakeFiles/dpll.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dpll.dir/main.cpp.i"
	C:\PROGRA~1\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\garfield\study\data structure\dpll\main.cpp" > CMakeFiles\dpll.dir\main.cpp.i

CMakeFiles/dpll.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dpll.dir/main.cpp.s"
	C:\PROGRA~1\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\garfield\study\data structure\dpll\main.cpp" -o CMakeFiles\dpll.dir\main.cpp.s

# Object files for target dpll
dpll_OBJECTS = \
"CMakeFiles/dpll.dir/main.cpp.obj"

# External object files for target dpll
dpll_EXTERNAL_OBJECTS =

dpll.exe: CMakeFiles/dpll.dir/main.cpp.obj
dpll.exe: CMakeFiles/dpll.dir/build.make
dpll.exe: CMakeFiles/dpll.dir/linklibs.rsp
dpll.exe: CMakeFiles/dpll.dir/objects1.rsp
dpll.exe: CMakeFiles/dpll.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\garfield\study\data structure\dpll\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable dpll.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\dpll.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/dpll.dir/build: dpll.exe

.PHONY : CMakeFiles/dpll.dir/build

CMakeFiles/dpll.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\dpll.dir\cmake_clean.cmake
.PHONY : CMakeFiles/dpll.dir/clean

CMakeFiles/dpll.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\garfield\study\data structure\dpll" "D:\garfield\study\data structure\dpll" "D:\garfield\study\data structure\dpll\cmake-build-debug" "D:\garfield\study\data structure\dpll\cmake-build-debug" "D:\garfield\study\data structure\dpll\cmake-build-debug\CMakeFiles\dpll.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/dpll.dir/depend

