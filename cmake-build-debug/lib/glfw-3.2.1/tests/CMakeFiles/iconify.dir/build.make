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
include lib/glfw-3.2.1/tests/CMakeFiles/iconify.dir/depend.make

# Include the progress variables for this target.
include lib/glfw-3.2.1/tests/CMakeFiles/iconify.dir/progress.make

# Include the compile flags for this target's objects.
include lib/glfw-3.2.1/tests/CMakeFiles/iconify.dir/flags.make

lib/glfw-3.2.1/tests/CMakeFiles/iconify.dir/iconify.c.obj: lib/glfw-3.2.1/tests/CMakeFiles/iconify.dir/flags.make
lib/glfw-3.2.1/tests/CMakeFiles/iconify.dir/iconify.c.obj: lib/glfw-3.2.1/tests/CMakeFiles/iconify.dir/includes_C.rsp
lib/glfw-3.2.1/tests/CMakeFiles/iconify.dir/iconify.c.obj: ../lib/glfw-3.2.1/tests/iconify.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Sewerin\Documents\GitHub\NEATanks\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object lib/glfw-3.2.1/tests/CMakeFiles/iconify.dir/iconify.c.obj"
	cd /d C:\Users\Sewerin\Documents\GitHub\NEATanks\cmake-build-debug\lib\glfw-3.2.1\tests && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\iconify.dir\iconify.c.obj   -c C:\Users\Sewerin\Documents\GitHub\NEATanks\lib\glfw-3.2.1\tests\iconify.c

lib/glfw-3.2.1/tests/CMakeFiles/iconify.dir/iconify.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/iconify.dir/iconify.c.i"
	cd /d C:\Users\Sewerin\Documents\GitHub\NEATanks\cmake-build-debug\lib\glfw-3.2.1\tests && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Sewerin\Documents\GitHub\NEATanks\lib\glfw-3.2.1\tests\iconify.c > CMakeFiles\iconify.dir\iconify.c.i

lib/glfw-3.2.1/tests/CMakeFiles/iconify.dir/iconify.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/iconify.dir/iconify.c.s"
	cd /d C:\Users\Sewerin\Documents\GitHub\NEATanks\cmake-build-debug\lib\glfw-3.2.1\tests && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Sewerin\Documents\GitHub\NEATanks\lib\glfw-3.2.1\tests\iconify.c -o CMakeFiles\iconify.dir\iconify.c.s

lib/glfw-3.2.1/tests/CMakeFiles/iconify.dir/iconify.c.obj.requires:

.PHONY : lib/glfw-3.2.1/tests/CMakeFiles/iconify.dir/iconify.c.obj.requires

lib/glfw-3.2.1/tests/CMakeFiles/iconify.dir/iconify.c.obj.provides: lib/glfw-3.2.1/tests/CMakeFiles/iconify.dir/iconify.c.obj.requires
	$(MAKE) -f lib\glfw-3.2.1\tests\CMakeFiles\iconify.dir\build.make lib/glfw-3.2.1/tests/CMakeFiles/iconify.dir/iconify.c.obj.provides.build
.PHONY : lib/glfw-3.2.1/tests/CMakeFiles/iconify.dir/iconify.c.obj.provides

lib/glfw-3.2.1/tests/CMakeFiles/iconify.dir/iconify.c.obj.provides.build: lib/glfw-3.2.1/tests/CMakeFiles/iconify.dir/iconify.c.obj


lib/glfw-3.2.1/tests/CMakeFiles/iconify.dir/__/deps/getopt.c.obj: lib/glfw-3.2.1/tests/CMakeFiles/iconify.dir/flags.make
lib/glfw-3.2.1/tests/CMakeFiles/iconify.dir/__/deps/getopt.c.obj: lib/glfw-3.2.1/tests/CMakeFiles/iconify.dir/includes_C.rsp
lib/glfw-3.2.1/tests/CMakeFiles/iconify.dir/__/deps/getopt.c.obj: ../lib/glfw-3.2.1/deps/getopt.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Sewerin\Documents\GitHub\NEATanks\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object lib/glfw-3.2.1/tests/CMakeFiles/iconify.dir/__/deps/getopt.c.obj"
	cd /d C:\Users\Sewerin\Documents\GitHub\NEATanks\cmake-build-debug\lib\glfw-3.2.1\tests && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\iconify.dir\__\deps\getopt.c.obj   -c C:\Users\Sewerin\Documents\GitHub\NEATanks\lib\glfw-3.2.1\deps\getopt.c

lib/glfw-3.2.1/tests/CMakeFiles/iconify.dir/__/deps/getopt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/iconify.dir/__/deps/getopt.c.i"
	cd /d C:\Users\Sewerin\Documents\GitHub\NEATanks\cmake-build-debug\lib\glfw-3.2.1\tests && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Sewerin\Documents\GitHub\NEATanks\lib\glfw-3.2.1\deps\getopt.c > CMakeFiles\iconify.dir\__\deps\getopt.c.i

lib/glfw-3.2.1/tests/CMakeFiles/iconify.dir/__/deps/getopt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/iconify.dir/__/deps/getopt.c.s"
	cd /d C:\Users\Sewerin\Documents\GitHub\NEATanks\cmake-build-debug\lib\glfw-3.2.1\tests && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Sewerin\Documents\GitHub\NEATanks\lib\glfw-3.2.1\deps\getopt.c -o CMakeFiles\iconify.dir\__\deps\getopt.c.s

lib/glfw-3.2.1/tests/CMakeFiles/iconify.dir/__/deps/getopt.c.obj.requires:

.PHONY : lib/glfw-3.2.1/tests/CMakeFiles/iconify.dir/__/deps/getopt.c.obj.requires

lib/glfw-3.2.1/tests/CMakeFiles/iconify.dir/__/deps/getopt.c.obj.provides: lib/glfw-3.2.1/tests/CMakeFiles/iconify.dir/__/deps/getopt.c.obj.requires
	$(MAKE) -f lib\glfw-3.2.1\tests\CMakeFiles\iconify.dir\build.make lib/glfw-3.2.1/tests/CMakeFiles/iconify.dir/__/deps/getopt.c.obj.provides.build
.PHONY : lib/glfw-3.2.1/tests/CMakeFiles/iconify.dir/__/deps/getopt.c.obj.provides

lib/glfw-3.2.1/tests/CMakeFiles/iconify.dir/__/deps/getopt.c.obj.provides.build: lib/glfw-3.2.1/tests/CMakeFiles/iconify.dir/__/deps/getopt.c.obj


lib/glfw-3.2.1/tests/CMakeFiles/iconify.dir/__/deps/glad.c.obj: lib/glfw-3.2.1/tests/CMakeFiles/iconify.dir/flags.make
lib/glfw-3.2.1/tests/CMakeFiles/iconify.dir/__/deps/glad.c.obj: lib/glfw-3.2.1/tests/CMakeFiles/iconify.dir/includes_C.rsp
lib/glfw-3.2.1/tests/CMakeFiles/iconify.dir/__/deps/glad.c.obj: ../lib/glfw-3.2.1/deps/glad.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Sewerin\Documents\GitHub\NEATanks\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object lib/glfw-3.2.1/tests/CMakeFiles/iconify.dir/__/deps/glad.c.obj"
	cd /d C:\Users\Sewerin\Documents\GitHub\NEATanks\cmake-build-debug\lib\glfw-3.2.1\tests && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\iconify.dir\__\deps\glad.c.obj   -c C:\Users\Sewerin\Documents\GitHub\NEATanks\lib\glfw-3.2.1\deps\glad.c

lib/glfw-3.2.1/tests/CMakeFiles/iconify.dir/__/deps/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/iconify.dir/__/deps/glad.c.i"
	cd /d C:\Users\Sewerin\Documents\GitHub\NEATanks\cmake-build-debug\lib\glfw-3.2.1\tests && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Sewerin\Documents\GitHub\NEATanks\lib\glfw-3.2.1\deps\glad.c > CMakeFiles\iconify.dir\__\deps\glad.c.i

lib/glfw-3.2.1/tests/CMakeFiles/iconify.dir/__/deps/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/iconify.dir/__/deps/glad.c.s"
	cd /d C:\Users\Sewerin\Documents\GitHub\NEATanks\cmake-build-debug\lib\glfw-3.2.1\tests && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Sewerin\Documents\GitHub\NEATanks\lib\glfw-3.2.1\deps\glad.c -o CMakeFiles\iconify.dir\__\deps\glad.c.s

lib/glfw-3.2.1/tests/CMakeFiles/iconify.dir/__/deps/glad.c.obj.requires:

.PHONY : lib/glfw-3.2.1/tests/CMakeFiles/iconify.dir/__/deps/glad.c.obj.requires

lib/glfw-3.2.1/tests/CMakeFiles/iconify.dir/__/deps/glad.c.obj.provides: lib/glfw-3.2.1/tests/CMakeFiles/iconify.dir/__/deps/glad.c.obj.requires
	$(MAKE) -f lib\glfw-3.2.1\tests\CMakeFiles\iconify.dir\build.make lib/glfw-3.2.1/tests/CMakeFiles/iconify.dir/__/deps/glad.c.obj.provides.build
.PHONY : lib/glfw-3.2.1/tests/CMakeFiles/iconify.dir/__/deps/glad.c.obj.provides

lib/glfw-3.2.1/tests/CMakeFiles/iconify.dir/__/deps/glad.c.obj.provides.build: lib/glfw-3.2.1/tests/CMakeFiles/iconify.dir/__/deps/glad.c.obj


# Object files for target iconify
iconify_OBJECTS = \
"CMakeFiles/iconify.dir/iconify.c.obj" \
"CMakeFiles/iconify.dir/__/deps/getopt.c.obj" \
"CMakeFiles/iconify.dir/__/deps/glad.c.obj"

# External object files for target iconify
iconify_EXTERNAL_OBJECTS =

lib/glfw-3.2.1/tests/iconify.exe: lib/glfw-3.2.1/tests/CMakeFiles/iconify.dir/iconify.c.obj
lib/glfw-3.2.1/tests/iconify.exe: lib/glfw-3.2.1/tests/CMakeFiles/iconify.dir/__/deps/getopt.c.obj
lib/glfw-3.2.1/tests/iconify.exe: lib/glfw-3.2.1/tests/CMakeFiles/iconify.dir/__/deps/glad.c.obj
lib/glfw-3.2.1/tests/iconify.exe: lib/glfw-3.2.1/tests/CMakeFiles/iconify.dir/build.make
lib/glfw-3.2.1/tests/iconify.exe: lib/glfw-3.2.1/src/libglfw3.a
lib/glfw-3.2.1/tests/iconify.exe: lib/glfw-3.2.1/tests/CMakeFiles/iconify.dir/linklibs.rsp
lib/glfw-3.2.1/tests/iconify.exe: lib/glfw-3.2.1/tests/CMakeFiles/iconify.dir/objects1.rsp
lib/glfw-3.2.1/tests/iconify.exe: lib/glfw-3.2.1/tests/CMakeFiles/iconify.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Sewerin\Documents\GitHub\NEATanks\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable iconify.exe"
	cd /d C:\Users\Sewerin\Documents\GitHub\NEATanks\cmake-build-debug\lib\glfw-3.2.1\tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\iconify.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/glfw-3.2.1/tests/CMakeFiles/iconify.dir/build: lib/glfw-3.2.1/tests/iconify.exe

.PHONY : lib/glfw-3.2.1/tests/CMakeFiles/iconify.dir/build

lib/glfw-3.2.1/tests/CMakeFiles/iconify.dir/requires: lib/glfw-3.2.1/tests/CMakeFiles/iconify.dir/iconify.c.obj.requires
lib/glfw-3.2.1/tests/CMakeFiles/iconify.dir/requires: lib/glfw-3.2.1/tests/CMakeFiles/iconify.dir/__/deps/getopt.c.obj.requires
lib/glfw-3.2.1/tests/CMakeFiles/iconify.dir/requires: lib/glfw-3.2.1/tests/CMakeFiles/iconify.dir/__/deps/glad.c.obj.requires

.PHONY : lib/glfw-3.2.1/tests/CMakeFiles/iconify.dir/requires

lib/glfw-3.2.1/tests/CMakeFiles/iconify.dir/clean:
	cd /d C:\Users\Sewerin\Documents\GitHub\NEATanks\cmake-build-debug\lib\glfw-3.2.1\tests && $(CMAKE_COMMAND) -P CMakeFiles\iconify.dir\cmake_clean.cmake
.PHONY : lib/glfw-3.2.1/tests/CMakeFiles/iconify.dir/clean

lib/glfw-3.2.1/tests/CMakeFiles/iconify.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Sewerin\Documents\GitHub\NEATanks C:\Users\Sewerin\Documents\GitHub\NEATanks\lib\glfw-3.2.1\tests C:\Users\Sewerin\Documents\GitHub\NEATanks\cmake-build-debug C:\Users\Sewerin\Documents\GitHub\NEATanks\cmake-build-debug\lib\glfw-3.2.1\tests C:\Users\Sewerin\Documents\GitHub\NEATanks\cmake-build-debug\lib\glfw-3.2.1\tests\CMakeFiles\iconify.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : lib/glfw-3.2.1/tests/CMakeFiles/iconify.dir/depend

