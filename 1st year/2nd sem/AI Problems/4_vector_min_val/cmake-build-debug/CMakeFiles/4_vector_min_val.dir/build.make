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
CMAKE_SOURCE_DIR = "D:\AI Problems\4_vector_min_val"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\AI Problems\4_vector_min_val\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles\4_vector_min_val.dir\depend.make
# Include the progress variables for this target.
include CMakeFiles\4_vector_min_val.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\4_vector_min_val.dir\flags.make

CMakeFiles\4_vector_min_val.dir\main.c.obj: CMakeFiles\4_vector_min_val.dir\flags.make
CMakeFiles\4_vector_min_val.dir\main.c.obj: ..\main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\AI Problems\4_vector_min_val\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/4_vector_min_val.dir/main.c.obj"
	C:\PROGRA~2\MIB055~1\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\4_vector_min_val.dir\main.c.obj /FdCMakeFiles\4_vector_min_val.dir\ /FS -c "D:\AI Problems\4_vector_min_val\main.c"
<<

CMakeFiles\4_vector_min_val.dir\main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/4_vector_min_val.dir/main.c.i"
	C:\PROGRA~2\MIB055~1\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe > CMakeFiles\4_vector_min_val.dir\main.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\AI Problems\4_vector_min_val\main.c"
<<

CMakeFiles\4_vector_min_val.dir\main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/4_vector_min_val.dir/main.c.s"
	C:\PROGRA~2\MIB055~1\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\4_vector_min_val.dir\main.c.s /c "D:\AI Problems\4_vector_min_val\main.c"
<<

# Object files for target 4_vector_min_val
4_vector_min_val_OBJECTS = \
"CMakeFiles\4_vector_min_val.dir\main.c.obj"

# External object files for target 4_vector_min_val
4_vector_min_val_EXTERNAL_OBJECTS =

4_vector_min_val.exe: CMakeFiles\4_vector_min_val.dir\main.c.obj
4_vector_min_val.exe: CMakeFiles\4_vector_min_val.dir\build.make
4_vector_min_val.exe: CMakeFiles\4_vector_min_val.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\AI Problems\4_vector_min_val\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable 4_vector_min_val.exe"
	"C:\Program Files\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\4_vector_min_val.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\mt.exe --manifests -- C:\PROGRA~2\MIB055~1\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\4_vector_min_val.dir\objects1.rsp @<<
 /out:4_vector_min_val.exe /implib:4_vector_min_val.lib /pdb:"D:\AI Problems\4_vector_min_val\cmake-build-debug\4_vector_min_val.pdb" /version:0.0 /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\4_vector_min_val.dir\build: 4_vector_min_val.exe
.PHONY : CMakeFiles\4_vector_min_val.dir\build

CMakeFiles\4_vector_min_val.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\4_vector_min_val.dir\cmake_clean.cmake
.PHONY : CMakeFiles\4_vector_min_val.dir\clean

CMakeFiles\4_vector_min_val.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" "D:\AI Problems\4_vector_min_val" "D:\AI Problems\4_vector_min_val" "D:\AI Problems\4_vector_min_val\cmake-build-debug" "D:\AI Problems\4_vector_min_val\cmake-build-debug" "D:\AI Problems\4_vector_min_val\cmake-build-debug\CMakeFiles\4_vector_min_val.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles\4_vector_min_val.dir\depend
