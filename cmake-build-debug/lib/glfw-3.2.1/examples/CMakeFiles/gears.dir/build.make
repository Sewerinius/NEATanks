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
include lib/glfw-3.2.1/examples/CMakeFiles/gears.dir/depend.make

# Include the progress variables for this target.
include lib/glfw-3.2.1/examples/CMakeFiles/gears.dir/progress.make

# Include the compile flags for this target's objects.
include lib/glfw-3.2.1/examples/CMakeFiles/gears.dir/flags.make

lib/glfw-3.2.1/examples/CMakeFiles/gears.dir/gears.c.obj: lib/glfw-3.2.1/examples/CMakeFiles/gears.dir/flags.make
lib/glfw-3.2.1/examples/CMakeFiles/gears.dir/gears.c.obj: lib/glfw-3.2.1/examples/CMakeFiles/gears.dir/includes_C.rsp
lib/glfw-3.2.1/examples/CMakeFiles/gears.dir/gears.c.obj: ../lib/glfw-3.2.1/examples/gears.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Sewerin\Documents\GitHub\NEATanks\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object lib/glfw-3.2.1/examples/CMakeFiles/gears.dir/gears.c.obj"
	cd /d C:\Users\Sewerin\Documents\GitHub\NEATanks\cmake-build-debug\lib\glfw-3.2.1\examples && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\gears.dir\gears.c.obj   -c C:\Users\Sewerin\Documents\GitHub\NEATanks\lib\glfw-3.2.1\examples\gears.c

lib/glfw-3.2.1/examples/CMakeFiles/gears.dir/gears.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gears.dir/gears.c.i"
	cd /d C:\Users\Sewerin\Documents\GitHub\NEATanks\cmake-build-debug\lib\glfw-3.2.1\examples && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Sewerin\Documents\GitHub\NEATanks\lib\glfw-3.2.1\examples\gears.c > CMakeFiles\gears.dir\gears.c.i

lib/glfw-3.2.1/examples/CMakeFiles/gears.dir/gears.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gears.dir/gears.c.s"
	cd /d C:\Users\Sewerin\Documents\GitHub\NEATanks\cmake-build-debug\lib\glfw-3.2.1\examples && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Sewerin\Documents\GitHub\NEATanks\lib\glfw-3.2.1\examples\gears.c -o CMakeFiles\gears.dir\gears.c.s

lib/glfw-3.2.1/examples/CMakeFiles/gears.dir/gears.c.obj.requires:

.PHONY : lib/glfw-3.2.1/examples/CMakeFiles/gears.dir/gears.c.obj.requires

lib/glfw-3.2.1/examples/CMakeFiles/gears.dir/gears.c.obj.provides: lib/glfw-3.2.1/examples/CMakeFiles/gears.dir/gears.c.obj.requires
	$(MAKE) -f lib\glfw-3.2.1\examples\CMakeFiles\gears.dir\build.make lib/glfw-3.2.1/examples/CMakeFiles/gears.dir/gears.c.obj.provides.build
.PHONY : lib/glfw-3.2.1/examples/CMakeFiles/gears.dir/gears.c.obj.provides

lib/glfw-3.2.1/examples/CMakeFiles/gears.dir/gears.c.obj.provides.build: lib/glfw-3.2.1/examples/CMakeFiles/gears.dir/gears.c.obj


lib/glfw-3.2.1/examples/CMakeFiles/gears.dir/glfw.rc.obj: lib/glfw-3.2.1/examples/CMakeFiles/gears.dir/flags.make
lib/glfw-3.2.1/examples/CMakeFiles/gears.dir/glfw.rc.obj: ../lib/glfw-3.2.1/examples/glfw.rc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Sewerin\Documents\GitHub\NEATanks\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building RC object lib/glfw-3.2.1/examples/CMakeFiles/gears.dir/glfw.rc.obj"
	cd /d C:\Users\Sewerin\Documents\GitHub\NEATanks\cmake-build-debug\lib\glfw-3.2.1\examples && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\windres.exe -O coff $(RC_DEFINES) $(RC_INCLUDES) $(RC_FLAGS) C:\Users\Sewerin\Documents\GitHub\NEATanks\lib\glfw-3.2.1\examples\glfw.rc CMakeFiles\gears.dir\glfw.rc.obj

lib/glfw-3.2.1/examples/CMakeFiles/gears.dir/glfw.rc.obj.requires:

.PHONY : lib/glfw-3.2.1/examples/CMakeFiles/gears.dir/glfw.rc.obj.requires

lib/glfw-3.2.1/examples/CMakeFiles/gears.dir/glfw.rc.obj.provides: lib/glfw-3.2.1/examples/CMakeFiles/gears.dir/glfw.rc.obj.requires
	$(MAKE) -f lib\glfw-3.2.1\examples\CMakeFiles\gears.dir\build.make lib/glfw-3.2.1/examples/CMakeFiles/gears.dir/glfw.rc.obj.provides.build
.PHONY : lib/glfw-3.2.1/examples/CMakeFiles/gears.dir/glfw.rc.obj.provides

lib/glfw-3.2.1/examples/CMakeFiles/gears.dir/glfw.rc.obj.provides.build: lib/glfw-3.2.1/examples/CMakeFiles/gears.dir/glfw.rc.obj


lib/glfw-3.2.1/examples/CMakeFiles/gears.dir/__/deps/glad.c.obj: lib/glfw-3.2.1/examples/CMakeFiles/gears.dir/flags.make
lib/glfw-3.2.1/examples/CMakeFiles/gears.dir/__/deps/glad.c.obj: lib/glfw-3.2.1/examples/CMakeFiles/gears.dir/includes_C.rsp
lib/glfw-3.2.1/examples/CMakeFiles/gears.dir/__/deps/glad.c.obj: ../lib/glfw-3.2.1/deps/glad.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Sewerin\Documents\GitHub\NEATanks\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object lib/glfw-3.2.1/examples/CMakeFiles/gears.dir/__/deps/glad.c.obj"
	cd /d C:\Users\Sewerin\Documents\GitHub\NEATanks\cmake-build-debug\lib\glfw-3.2.1\examples && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\gears.dir\__\deps\glad.c.obj   -c C:\Users\Sewerin\Documents\GitHub\NEATanks\lib\glfw-3.2.1\deps\glad.c

lib/glfw-3.2.1/examples/CMakeFiles/gears.dir/__/deps/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gears.dir/__/deps/glad.c.i"
	cd /d C:\Users\Sewerin\Documents\GitHub\NEATanks\cmake-build-debug\lib\glfw-3.2.1\examples && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Sewerin\Documents\GitHub\NEATanks\lib\glfw-3.2.1\deps\glad.c > CMakeFiles\gears.dir\__\deps\glad.c.i

lib/glfw-3.2.1/examples/CMakeFiles/gears.dir/__/deps/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gears.dir/__/deps/glad.c.s"
	cd /d C:\Users\Sewerin\Documents\GitHub\NEATanks\cmake-build-debug\lib\glfw-3.2.1\examples && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Sewerin\Documents\GitHub\NEATanks\lib\glfw-3.2.1\deps\glad.c -o CMakeFiles\gears.dir\__\deps\glad.c.s

lib/glfw-3.2.1/examples/CMakeFiles/gears.dir/__/deps/glad.c.obj.requires:

.PHONY : lib/glfw-3.2.1/examples/CMakeFiles/gears.dir/__/deps/glad.c.obj.requires

lib/glfw-3.2.1/examples/CMakeFiles/gears.dir/__/deps/glad.c.obj.provides: lib/glfw-3.2.1/examples/CMakeFiles/gears.dir/__/deps/glad.c.obj.requires
	$(MAKE) -f lib\glfw-3.2.1\examples\CMakeFiles\gears.dir\build.make lib/glfw-3.2.1/examples/CMakeFiles/gears.dir/__/deps/glad.c.obj.provides.build
.PHONY : lib/glfw-3.2.1/examples/CMakeFiles/gears.dir/__/deps/glad.c.obj.provides

lib/glfw-3.2.1/examples/CMakeFiles/gears.dir/__/deps/glad.c.obj.provides.build: lib/glfw-3.2.1/examples/CMakeFiles/gears.dir/__/deps/glad.c.obj


# Object files for target gears
gears_OBJECTS = \
"CMakeFiles/gears.dir/gears.c.obj" \
"CMakeFiles/gears.dir/glfw.rc.obj" \
"CMakeFiles/gears.dir/__/deps/glad.c.obj"

# External object files for target gears
gears_EXTERNAL_OBJECTS =

lib/glfw-3.2.1/examples/gears.exe: lib/glfw-3.2.1/examples/CMakeFiles/gears.dir/gears.c.obj
lib/glfw-3.2.1/examples/gears.exe: lib/glfw-3.2.1/examples/CMakeFiles/gears.dir/glfw.rc.obj
lib/glfw-3.2.1/examples/gears.exe: lib/glfw-3.2.1/examples/CMakeFiles/gears.dir/__/deps/glad.c.obj
lib/glfw-3.2.1/examples/gears.exe: lib/glfw-3.2.1/examples/CMakeFiles/gears.dir/build.make
lib/glfw-3.2.1/examples/gears.exe: lib/glfw-3.2.1/src/libglfw3.a
lib/glfw-3.2.1/examples/gears.exe: lib/glfw-3.2.1/examples/CMakeFiles/gears.dir/linklibs.rsp
lib/glfw-3.2.1/examples/gears.exe: lib/glfw-3.2.1/examples/CMakeFiles/gears.dir/objects1.rsp
lib/glfw-3.2.1/examples/gears.exe: lib/glfw-3.2.1/examples/CMakeFiles/gears.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Sewerin\Documents\GitHub\NEATanks\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable gears.exe"
	cd /d C:\Users\Sewerin\Documents\GitHub\NEATanks\cmake-build-debug\lib\glfw-3.2.1\examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\gears.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/glfw-3.2.1/examples/CMakeFiles/gears.dir/build: lib/glfw-3.2.1/examples/gears.exe

.PHONY : lib/glfw-3.2.1/examples/CMakeFiles/gears.dir/build

lib/glfw-3.2.1/examples/CMakeFiles/gears.dir/requires: lib/glfw-3.2.1/examples/CMakeFiles/gears.dir/gears.c.obj.requires
lib/glfw-3.2.1/examples/CMakeFiles/gears.dir/requires: lib/glfw-3.2.1/examples/CMakeFiles/gears.dir/glfw.rc.obj.requires
lib/glfw-3.2.1/examples/CMakeFiles/gears.dir/requires: lib/glfw-3.2.1/examples/CMakeFiles/gears.dir/__/deps/glad.c.obj.requires

.PHONY : lib/glfw-3.2.1/examples/CMakeFiles/gears.dir/requires

lib/glfw-3.2.1/examples/CMakeFiles/gears.dir/clean:
	cd /d C:\Users\Sewerin\Documents\GitHub\NEATanks\cmake-build-debug\lib\glfw-3.2.1\examples && $(CMAKE_COMMAND) -P CMakeFiles\gears.dir\cmake_clean.cmake
.PHONY : lib/glfw-3.2.1/examples/CMakeFiles/gears.dir/clean

lib/glfw-3.2.1/examples/CMakeFiles/gears.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Sewerin\Documents\GitHub\NEATanks C:\Users\Sewerin\Documents\GitHub\NEATanks\lib\glfw-3.2.1\examples C:\Users\Sewerin\Documents\GitHub\NEATanks\cmake-build-debug C:\Users\Sewerin\Documents\GitHub\NEATanks\cmake-build-debug\lib\glfw-3.2.1\examples C:\Users\Sewerin\Documents\GitHub\NEATanks\cmake-build-debug\lib\glfw-3.2.1\examples\CMakeFiles\gears.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : lib/glfw-3.2.1/examples/CMakeFiles/gears.dir/depend

