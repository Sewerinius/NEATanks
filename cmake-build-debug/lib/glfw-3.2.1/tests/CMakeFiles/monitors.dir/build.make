# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2017.2.2\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2017.2.2\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Sewerin\Documents\GitHub\NEATanks

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Sewerin\Documents\GitHub\NEATanks\cmake-build-debug

# Include any dependencies generated for this target.
include lib/glfw-3.2.1/tests/CMakeFiles/monitors.dir/depend.make

# Include the progress variables for this target.
include lib/glfw-3.2.1/tests/CMakeFiles/monitors.dir/progress.make

# Include the compile flags for this target's objects.
include lib/glfw-3.2.1/tests/CMakeFiles/monitors.dir/flags.make

lib/glfw-3.2.1/tests/CMakeFiles/monitors.dir/monitors.c.obj: lib/glfw-3.2.1/tests/CMakeFiles/monitors.dir/flags.make
lib/glfw-3.2.1/tests/CMakeFiles/monitors.dir/monitors.c.obj: lib/glfw-3.2.1/tests/CMakeFiles/monitors.dir/includes_C.rsp
lib/glfw-3.2.1/tests/CMakeFiles/monitors.dir/monitors.c.obj: ../lib/glfw-3.2.1/tests/monitors.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Sewerin\Documents\GitHub\NEATanks\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object lib/glfw-3.2.1/tests/CMakeFiles/monitors.dir/monitors.c.obj"
	cd /d C:\Users\Sewerin\Documents\GitHub\NEATanks\cmake-build-debug\lib\glfw-3.2.1\tests && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\monitors.dir\monitors.c.obj   -c C:\Users\Sewerin\Documents\GitHub\NEATanks\lib\glfw-3.2.1\tests\monitors.c

lib/glfw-3.2.1/tests/CMakeFiles/monitors.dir/monitors.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/monitors.dir/monitors.c.i"
	cd /d C:\Users\Sewerin\Documents\GitHub\NEATanks\cmake-build-debug\lib\glfw-3.2.1\tests && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Sewerin\Documents\GitHub\NEATanks\lib\glfw-3.2.1\tests\monitors.c > CMakeFiles\monitors.dir\monitors.c.i

lib/glfw-3.2.1/tests/CMakeFiles/monitors.dir/monitors.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/monitors.dir/monitors.c.s"
	cd /d C:\Users\Sewerin\Documents\GitHub\NEATanks\cmake-build-debug\lib\glfw-3.2.1\tests && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Sewerin\Documents\GitHub\NEATanks\lib\glfw-3.2.1\tests\monitors.c -o CMakeFiles\monitors.dir\monitors.c.s

lib/glfw-3.2.1/tests/CMakeFiles/monitors.dir/monitors.c.obj.requires:

.PHONY : lib/glfw-3.2.1/tests/CMakeFiles/monitors.dir/monitors.c.obj.requires

lib/glfw-3.2.1/tests/CMakeFiles/monitors.dir/monitors.c.obj.provides: lib/glfw-3.2.1/tests/CMakeFiles/monitors.dir/monitors.c.obj.requires
	$(MAKE) -f lib\glfw-3.2.1\tests\CMakeFiles\monitors.dir\build.make lib/glfw-3.2.1/tests/CMakeFiles/monitors.dir/monitors.c.obj.provides.build
.PHONY : lib/glfw-3.2.1/tests/CMakeFiles/monitors.dir/monitors.c.obj.provides

lib/glfw-3.2.1/tests/CMakeFiles/monitors.dir/monitors.c.obj.provides.build: lib/glfw-3.2.1/tests/CMakeFiles/monitors.dir/monitors.c.obj


lib/glfw-3.2.1/tests/CMakeFiles/monitors.dir/__/deps/getopt.c.obj: lib/glfw-3.2.1/tests/CMakeFiles/monitors.dir/flags.make
lib/glfw-3.2.1/tests/CMakeFiles/monitors.dir/__/deps/getopt.c.obj: lib/glfw-3.2.1/tests/CMakeFiles/monitors.dir/includes_C.rsp
lib/glfw-3.2.1/tests/CMakeFiles/monitors.dir/__/deps/getopt.c.obj: ../lib/glfw-3.2.1/deps/getopt.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Sewerin\Documents\GitHub\NEATanks\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object lib/glfw-3.2.1/tests/CMakeFiles/monitors.dir/__/deps/getopt.c.obj"
	cd /d C:\Users\Sewerin\Documents\GitHub\NEATanks\cmake-build-debug\lib\glfw-3.2.1\tests && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\monitors.dir\__\deps\getopt.c.obj   -c C:\Users\Sewerin\Documents\GitHub\NEATanks\lib\glfw-3.2.1\deps\getopt.c

lib/glfw-3.2.1/tests/CMakeFiles/monitors.dir/__/deps/getopt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/monitors.dir/__/deps/getopt.c.i"
	cd /d C:\Users\Sewerin\Documents\GitHub\NEATanks\cmake-build-debug\lib\glfw-3.2.1\tests && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Sewerin\Documents\GitHub\NEATanks\lib\glfw-3.2.1\deps\getopt.c > CMakeFiles\monitors.dir\__\deps\getopt.c.i

lib/glfw-3.2.1/tests/CMakeFiles/monitors.dir/__/deps/getopt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/monitors.dir/__/deps/getopt.c.s"
	cd /d C:\Users\Sewerin\Documents\GitHub\NEATanks\cmake-build-debug\lib\glfw-3.2.1\tests && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Sewerin\Documents\GitHub\NEATanks\lib\glfw-3.2.1\deps\getopt.c -o CMakeFiles\monitors.dir\__\deps\getopt.c.s

lib/glfw-3.2.1/tests/CMakeFiles/monitors.dir/__/deps/getopt.c.obj.requires:

.PHONY : lib/glfw-3.2.1/tests/CMakeFiles/monitors.dir/__/deps/getopt.c.obj.requires

lib/glfw-3.2.1/tests/CMakeFiles/monitors.dir/__/deps/getopt.c.obj.provides: lib/glfw-3.2.1/tests/CMakeFiles/monitors.dir/__/deps/getopt.c.obj.requires
	$(MAKE) -f lib\glfw-3.2.1\tests\CMakeFiles\monitors.dir\build.make lib/glfw-3.2.1/tests/CMakeFiles/monitors.dir/__/deps/getopt.c.obj.provides.build
.PHONY : lib/glfw-3.2.1/tests/CMakeFiles/monitors.dir/__/deps/getopt.c.obj.provides

lib/glfw-3.2.1/tests/CMakeFiles/monitors.dir/__/deps/getopt.c.obj.provides.build: lib/glfw-3.2.1/tests/CMakeFiles/monitors.dir/__/deps/getopt.c.obj


lib/glfw-3.2.1/tests/CMakeFiles/monitors.dir/__/deps/glad.c.obj: lib/glfw-3.2.1/tests/CMakeFiles/monitors.dir/flags.make
lib/glfw-3.2.1/tests/CMakeFiles/monitors.dir/__/deps/glad.c.obj: lib/glfw-3.2.1/tests/CMakeFiles/monitors.dir/includes_C.rsp
lib/glfw-3.2.1/tests/CMakeFiles/monitors.dir/__/deps/glad.c.obj: ../lib/glfw-3.2.1/deps/glad.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Sewerin\Documents\GitHub\NEATanks\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object lib/glfw-3.2.1/tests/CMakeFiles/monitors.dir/__/deps/glad.c.obj"
	cd /d C:\Users\Sewerin\Documents\GitHub\NEATanks\cmake-build-debug\lib\glfw-3.2.1\tests && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\monitors.dir\__\deps\glad.c.obj   -c C:\Users\Sewerin\Documents\GitHub\NEATanks\lib\glfw-3.2.1\deps\glad.c

lib/glfw-3.2.1/tests/CMakeFiles/monitors.dir/__/deps/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/monitors.dir/__/deps/glad.c.i"
	cd /d C:\Users\Sewerin\Documents\GitHub\NEATanks\cmake-build-debug\lib\glfw-3.2.1\tests && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Sewerin\Documents\GitHub\NEATanks\lib\glfw-3.2.1\deps\glad.c > CMakeFiles\monitors.dir\__\deps\glad.c.i

lib/glfw-3.2.1/tests/CMakeFiles/monitors.dir/__/deps/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/monitors.dir/__/deps/glad.c.s"
	cd /d C:\Users\Sewerin\Documents\GitHub\NEATanks\cmake-build-debug\lib\glfw-3.2.1\tests && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Sewerin\Documents\GitHub\NEATanks\lib\glfw-3.2.1\deps\glad.c -o CMakeFiles\monitors.dir\__\deps\glad.c.s

lib/glfw-3.2.1/tests/CMakeFiles/monitors.dir/__/deps/glad.c.obj.requires:

.PHONY : lib/glfw-3.2.1/tests/CMakeFiles/monitors.dir/__/deps/glad.c.obj.requires

lib/glfw-3.2.1/tests/CMakeFiles/monitors.dir/__/deps/glad.c.obj.provides: lib/glfw-3.2.1/tests/CMakeFiles/monitors.dir/__/deps/glad.c.obj.requires
	$(MAKE) -f lib\glfw-3.2.1\tests\CMakeFiles\monitors.dir\build.make lib/glfw-3.2.1/tests/CMakeFiles/monitors.dir/__/deps/glad.c.obj.provides.build
.PHONY : lib/glfw-3.2.1/tests/CMakeFiles/monitors.dir/__/deps/glad.c.obj.provides

lib/glfw-3.2.1/tests/CMakeFiles/monitors.dir/__/deps/glad.c.obj.provides.build: lib/glfw-3.2.1/tests/CMakeFiles/monitors.dir/__/deps/glad.c.obj


# Object files for target monitors
monitors_OBJECTS = \
"CMakeFiles/monitors.dir/monitors.c.obj" \
"CMakeFiles/monitors.dir/__/deps/getopt.c.obj" \
"CMakeFiles/monitors.dir/__/deps/glad.c.obj"

# External object files for target monitors
monitors_EXTERNAL_OBJECTS =

lib/glfw-3.2.1/tests/monitors.exe: lib/glfw-3.2.1/tests/CMakeFiles/monitors.dir/monitors.c.obj
lib/glfw-3.2.1/tests/monitors.exe: lib/glfw-3.2.1/tests/CMakeFiles/monitors.dir/__/deps/getopt.c.obj
lib/glfw-3.2.1/tests/monitors.exe: lib/glfw-3.2.1/tests/CMakeFiles/monitors.dir/__/deps/glad.c.obj
lib/glfw-3.2.1/tests/monitors.exe: lib/glfw-3.2.1/tests/CMakeFiles/monitors.dir/build.make
lib/glfw-3.2.1/tests/monitors.exe: lib/glfw-3.2.1/src/libglfw3.a
lib/glfw-3.2.1/tests/monitors.exe: lib/glfw-3.2.1/tests/CMakeFiles/monitors.dir/linklibs.rsp
lib/glfw-3.2.1/tests/monitors.exe: lib/glfw-3.2.1/tests/CMakeFiles/monitors.dir/objects1.rsp
lib/glfw-3.2.1/tests/monitors.exe: lib/glfw-3.2.1/tests/CMakeFiles/monitors.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Sewerin\Documents\GitHub\NEATanks\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable monitors.exe"
	cd /d C:\Users\Sewerin\Documents\GitHub\NEATanks\cmake-build-debug\lib\glfw-3.2.1\tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\monitors.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/glfw-3.2.1/tests/CMakeFiles/monitors.dir/build: lib/glfw-3.2.1/tests/monitors.exe

.PHONY : lib/glfw-3.2.1/tests/CMakeFiles/monitors.dir/build

lib/glfw-3.2.1/tests/CMakeFiles/monitors.dir/requires: lib/glfw-3.2.1/tests/CMakeFiles/monitors.dir/monitors.c.obj.requires
lib/glfw-3.2.1/tests/CMakeFiles/monitors.dir/requires: lib/glfw-3.2.1/tests/CMakeFiles/monitors.dir/__/deps/getopt.c.obj.requires
lib/glfw-3.2.1/tests/CMakeFiles/monitors.dir/requires: lib/glfw-3.2.1/tests/CMakeFiles/monitors.dir/__/deps/glad.c.obj.requires

.PHONY : lib/glfw-3.2.1/tests/CMakeFiles/monitors.dir/requires

lib/glfw-3.2.1/tests/CMakeFiles/monitors.dir/clean:
	cd /d C:\Users\Sewerin\Documents\GitHub\NEATanks\cmake-build-debug\lib\glfw-3.2.1\tests && $(CMAKE_COMMAND) -P CMakeFiles\monitors.dir\cmake_clean.cmake
.PHONY : lib/glfw-3.2.1/tests/CMakeFiles/monitors.dir/clean

lib/glfw-3.2.1/tests/CMakeFiles/monitors.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Sewerin\Documents\GitHub\NEATanks C:\Users\Sewerin\Documents\GitHub\NEATanks\lib\glfw-3.2.1\tests C:\Users\Sewerin\Documents\GitHub\NEATanks\cmake-build-debug C:\Users\Sewerin\Documents\GitHub\NEATanks\cmake-build-debug\lib\glfw-3.2.1\tests C:\Users\Sewerin\Documents\GitHub\NEATanks\cmake-build-debug\lib\glfw-3.2.1\tests\CMakeFiles\monitors.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : lib/glfw-3.2.1/tests/CMakeFiles/monitors.dir/depend

