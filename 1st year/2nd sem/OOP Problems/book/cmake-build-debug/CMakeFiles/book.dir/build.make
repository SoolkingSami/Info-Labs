# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\Info Labs\1st year\2nd sem\OOP Problems\book"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\Info Labs\1st year\2nd sem\OOP Problems\book\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/book.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/book.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/book.dir/flags.make

CMakeFiles/book.dir/main.cpp.obj: CMakeFiles/book.dir/flags.make
CMakeFiles/book.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Info Labs\1st year\2nd sem\OOP Problems\book\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/book.dir/main.cpp.obj"
	C:\ProgramData\chocolatey\lib\mingw\tools\install\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\book.dir\main.cpp.obj -c "D:\Info Labs\1st year\2nd sem\OOP Problems\book\main.cpp"

CMakeFiles/book.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/book.dir/main.cpp.i"
	C:\ProgramData\chocolatey\lib\mingw\tools\install\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Info Labs\1st year\2nd sem\OOP Problems\book\main.cpp" > CMakeFiles\book.dir\main.cpp.i

CMakeFiles/book.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/book.dir/main.cpp.s"
	C:\ProgramData\chocolatey\lib\mingw\tools\install\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Info Labs\1st year\2nd sem\OOP Problems\book\main.cpp" -o CMakeFiles\book.dir\main.cpp.s

# Object files for target book
book_OBJECTS = \
"CMakeFiles/book.dir/main.cpp.obj"

# External object files for target book
book_EXTERNAL_OBJECTS =

book.exe: CMakeFiles/book.dir/main.cpp.obj
book.exe: CMakeFiles/book.dir/build.make
book.exe: CMakeFiles/book.dir/linklibs.rsp
book.exe: CMakeFiles/book.dir/objects1.rsp
book.exe: CMakeFiles/book.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\Info Labs\1st year\2nd sem\OOP Problems\book\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable book.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\book.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/book.dir/build: book.exe
.PHONY : CMakeFiles/book.dir/build

CMakeFiles/book.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\book.dir\cmake_clean.cmake
.PHONY : CMakeFiles/book.dir/clean

CMakeFiles/book.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\Info Labs\1st year\2nd sem\OOP Problems\book" "D:\Info Labs\1st year\2nd sem\OOP Problems\book" "D:\Info Labs\1st year\2nd sem\OOP Problems\book\cmake-build-debug" "D:\Info Labs\1st year\2nd sem\OOP Problems\book\cmake-build-debug" "D:\Info Labs\1st year\2nd sem\OOP Problems\book\cmake-build-debug\CMakeFiles\book.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/book.dir/depend
