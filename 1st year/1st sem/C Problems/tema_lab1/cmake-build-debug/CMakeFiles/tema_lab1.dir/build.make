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
CMAKE_SOURCE_DIR = C:\Users\asus\CLionProjects\tema_lab1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\asus\CLionProjects\tema_lab1\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\tema_lab1.dir\depend.make
# Include the progress variables for this target.
include CMakeFiles\tema_lab1.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\tema_lab1.dir\flags.make

CMakeFiles\tema_lab1.dir\main.c.obj: CMakeFiles\tema_lab1.dir\flags.make
CMakeFiles\tema_lab1.dir\main.c.obj: ..\main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\asus\CLionProjects\tema_lab1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/tema_lab1.dir/main.c.obj"
	C:\PROGRA~2\MIB055~1\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\tema_lab1.dir\main.c.obj /FdCMakeFiles\tema_lab1.dir\ /FS -c C:\Users\asus\CLionProjects\tema_lab1\main.c
<<

CMakeFiles\tema_lab1.dir\main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tema_lab1.dir/main.c.i"
	C:\PROGRA~2\MIB055~1\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe > CMakeFiles\tema_lab1.dir\main.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\asus\CLionProjects\tema_lab1\main.c
<<

CMakeFiles\tema_lab1.dir\main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tema_lab1.dir/main.c.s"
	C:\PROGRA~2\MIB055~1\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\tema_lab1.dir\main.c.s /c C:\Users\asus\CLionProjects\tema_lab1\main.c
<<

# Object files for target tema_lab1
tema_lab1_OBJECTS = \
"CMakeFiles\tema_lab1.dir\main.c.obj"

# External object files for target tema_lab1
tema_lab1_EXTERNAL_OBJECTS =

tema_lab1.exe: CMakeFiles\tema_lab1.dir\main.c.obj
tema_lab1.exe: CMakeFiles\tema_lab1.dir\build.make
tema_lab1.exe: CMakeFiles\tema_lab1.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\asus\CLionProjects\tema_lab1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable tema_lab1.exe"
	"C:\Program Files\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\tema_lab1.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\mt.exe --manifests -- C:\PROGRA~2\MIB055~1\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\tema_lab1.dir\objects1.rsp @<<
 /out:tema_lab1.exe /implib:tema_lab1.lib /pdb:C:\Users\asus\CLionProjects\tema_lab1\cmake-build-debug\tema_lab1.pdb /version:0.0 /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\tema_lab1.dir\build: tema_lab1.exe
.PHONY : CMakeFiles\tema_lab1.dir\build

CMakeFiles\tema_lab1.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\tema_lab1.dir\cmake_clean.cmake
.PHONY : CMakeFiles\tema_lab1.dir\clean

CMakeFiles\tema_lab1.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\asus\CLionProjects\tema_lab1 C:\Users\asus\CLionProjects\tema_lab1 C:\Users\asus\CLionProjects\tema_lab1\cmake-build-debug C:\Users\asus\CLionProjects\tema_lab1\cmake-build-debug C:\Users\asus\CLionProjects\tema_lab1\cmake-build-debug\CMakeFiles\tema_lab1.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\tema_lab1.dir\depend

