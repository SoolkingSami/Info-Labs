# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\AI Problems\18_cut_vectors"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\AI Problems\18_cut_vectors\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles\18_cut_vectors.dir\depend.make
# Include the progress variables for this target.
include CMakeFiles\18_cut_vectors.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\18_cut_vectors.dir\flags.make

CMakeFiles\18_cut_vectors.dir\main.cpp.obj: CMakeFiles\18_cut_vectors.dir\flags.make
CMakeFiles\18_cut_vectors.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\AI Problems\18_cut_vectors\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/18_cut_vectors.dir/main.cpp.obj"
	C:\PROGRA~2\MIB055~1\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\18_cut_vectors.dir\main.cpp.obj /FdCMakeFiles\18_cut_vectors.dir\ /FS -c "D:\AI Problems\18_cut_vectors\main.cpp"
<<

CMakeFiles\18_cut_vectors.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/18_cut_vectors.dir/main.cpp.i"
	C:\PROGRA~2\MIB055~1\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe > CMakeFiles\18_cut_vectors.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\AI Problems\18_cut_vectors\main.cpp"
<<

CMakeFiles\18_cut_vectors.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/18_cut_vectors.dir/main.cpp.s"
	C:\PROGRA~2\MIB055~1\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\18_cut_vectors.dir\main.cpp.s /c "D:\AI Problems\18_cut_vectors\main.cpp"
<<

# Object files for target 18_cut_vectors
18_cut_vectors_OBJECTS = \
"CMakeFiles\18_cut_vectors.dir\main.cpp.obj"

# External object files for target 18_cut_vectors
18_cut_vectors_EXTERNAL_OBJECTS =

18_cut_vectors.exe: CMakeFiles\18_cut_vectors.dir\main.cpp.obj
18_cut_vectors.exe: CMakeFiles\18_cut_vectors.dir\build.make
18_cut_vectors.exe: CMakeFiles\18_cut_vectors.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\AI Problems\18_cut_vectors\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 18_cut_vectors.exe"
	"C:\Program Files\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\18_cut_vectors.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\mt.exe --manifests -- C:\PROGRA~2\MIB055~1\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\18_cut_vectors.dir\objects1.rsp @<<
 /out:18_cut_vectors.exe /implib:18_cut_vectors.lib /pdb:"D:\AI Problems\18_cut_vectors\cmake-build-debug\18_cut_vectors.pdb" /version:0.0 /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\18_cut_vectors.dir\build: 18_cut_vectors.exe
.PHONY : CMakeFiles\18_cut_vectors.dir\build

CMakeFiles\18_cut_vectors.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\18_cut_vectors.dir\cmake_clean.cmake
.PHONY : CMakeFiles\18_cut_vectors.dir\clean

CMakeFiles\18_cut_vectors.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" "D:\AI Problems\18_cut_vectors" "D:\AI Problems\18_cut_vectors" "D:\AI Problems\18_cut_vectors\cmake-build-debug" "D:\AI Problems\18_cut_vectors\cmake-build-debug" "D:\AI Problems\18_cut_vectors\cmake-build-debug\CMakeFiles\18_cut_vectors.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles\18_cut_vectors.dir\depend

