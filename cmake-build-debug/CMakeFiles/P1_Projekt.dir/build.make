# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2022.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2022.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\danie\OneDrive\Uni\1. semester\IMPR\P1-Projekt"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\danie\OneDrive\Uni\1. semester\IMPR\P1-Projekt\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/P1_Projekt.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/P1_Projekt.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/P1_Projekt.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/P1_Projekt.dir/flags.make

CMakeFiles/P1_Projekt.dir/main.c.obj: CMakeFiles/P1_Projekt.dir/flags.make
CMakeFiles/P1_Projekt.dir/main.c.obj: ../main.c
CMakeFiles/P1_Projekt.dir/main.c.obj: CMakeFiles/P1_Projekt.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\danie\OneDrive\Uni\1. semester\IMPR\P1-Projekt\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/P1_Projekt.dir/main.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/P1_Projekt.dir/main.c.obj -MF CMakeFiles\P1_Projekt.dir\main.c.obj.d -o CMakeFiles\P1_Projekt.dir\main.c.obj -c "C:\Users\danie\OneDrive\Uni\1. semester\IMPR\P1-Projekt\main.c"

CMakeFiles/P1_Projekt.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/P1_Projekt.dir/main.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\danie\OneDrive\Uni\1. semester\IMPR\P1-Projekt\main.c" > CMakeFiles\P1_Projekt.dir\main.c.i

CMakeFiles/P1_Projekt.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/P1_Projekt.dir/main.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\danie\OneDrive\Uni\1. semester\IMPR\P1-Projekt\main.c" -o CMakeFiles\P1_Projekt.dir\main.c.s

CMakeFiles/P1_Projekt.dir/CalculateCheapestOption.c.obj: CMakeFiles/P1_Projekt.dir/flags.make
CMakeFiles/P1_Projekt.dir/CalculateCheapestOption.c.obj: ../CalculateCheapestOption.c
CMakeFiles/P1_Projekt.dir/CalculateCheapestOption.c.obj: CMakeFiles/P1_Projekt.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\danie\OneDrive\Uni\1. semester\IMPR\P1-Projekt\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/P1_Projekt.dir/CalculateCheapestOption.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/P1_Projekt.dir/CalculateCheapestOption.c.obj -MF CMakeFiles\P1_Projekt.dir\CalculateCheapestOption.c.obj.d -o CMakeFiles\P1_Projekt.dir\CalculateCheapestOption.c.obj -c "C:\Users\danie\OneDrive\Uni\1. semester\IMPR\P1-Projekt\CalculateCheapestOption.c"

CMakeFiles/P1_Projekt.dir/CalculateCheapestOption.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/P1_Projekt.dir/CalculateCheapestOption.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\danie\OneDrive\Uni\1. semester\IMPR\P1-Projekt\CalculateCheapestOption.c" > CMakeFiles\P1_Projekt.dir\CalculateCheapestOption.c.i

CMakeFiles/P1_Projekt.dir/CalculateCheapestOption.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/P1_Projekt.dir/CalculateCheapestOption.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\danie\OneDrive\Uni\1. semester\IMPR\P1-Projekt\CalculateCheapestOption.c" -o CMakeFiles\P1_Projekt.dir\CalculateCheapestOption.c.s

CMakeFiles/P1_Projekt.dir/database_gen.c.obj: CMakeFiles/P1_Projekt.dir/flags.make
CMakeFiles/P1_Projekt.dir/database_gen.c.obj: ../database_gen.c
CMakeFiles/P1_Projekt.dir/database_gen.c.obj: CMakeFiles/P1_Projekt.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\danie\OneDrive\Uni\1. semester\IMPR\P1-Projekt\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/P1_Projekt.dir/database_gen.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/P1_Projekt.dir/database_gen.c.obj -MF CMakeFiles\P1_Projekt.dir\database_gen.c.obj.d -o CMakeFiles\P1_Projekt.dir\database_gen.c.obj -c "C:\Users\danie\OneDrive\Uni\1. semester\IMPR\P1-Projekt\database_gen.c"

CMakeFiles/P1_Projekt.dir/database_gen.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/P1_Projekt.dir/database_gen.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\danie\OneDrive\Uni\1. semester\IMPR\P1-Projekt\database_gen.c" > CMakeFiles\P1_Projekt.dir\database_gen.c.i

CMakeFiles/P1_Projekt.dir/database_gen.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/P1_Projekt.dir/database_gen.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\danie\OneDrive\Uni\1. semester\IMPR\P1-Projekt\database_gen.c" -o CMakeFiles\P1_Projekt.dir\database_gen.c.s

CMakeFiles/P1_Projekt.dir/shopping_list.c.obj: CMakeFiles/P1_Projekt.dir/flags.make
CMakeFiles/P1_Projekt.dir/shopping_list.c.obj: ../shopping_list.c
CMakeFiles/P1_Projekt.dir/shopping_list.c.obj: CMakeFiles/P1_Projekt.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\danie\OneDrive\Uni\1. semester\IMPR\P1-Projekt\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/P1_Projekt.dir/shopping_list.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/P1_Projekt.dir/shopping_list.c.obj -MF CMakeFiles\P1_Projekt.dir\shopping_list.c.obj.d -o CMakeFiles\P1_Projekt.dir\shopping_list.c.obj -c "C:\Users\danie\OneDrive\Uni\1. semester\IMPR\P1-Projekt\shopping_list.c"

CMakeFiles/P1_Projekt.dir/shopping_list.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/P1_Projekt.dir/shopping_list.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\danie\OneDrive\Uni\1. semester\IMPR\P1-Projekt\shopping_list.c" > CMakeFiles\P1_Projekt.dir\shopping_list.c.i

CMakeFiles/P1_Projekt.dir/shopping_list.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/P1_Projekt.dir/shopping_list.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\danie\OneDrive\Uni\1. semester\IMPR\P1-Projekt\shopping_list.c" -o CMakeFiles\P1_Projekt.dir\shopping_list.c.s

# Object files for target P1_Projekt
P1_Projekt_OBJECTS = \
"CMakeFiles/P1_Projekt.dir/main.c.obj" \
"CMakeFiles/P1_Projekt.dir/CalculateCheapestOption.c.obj" \
"CMakeFiles/P1_Projekt.dir/database_gen.c.obj" \
"CMakeFiles/P1_Projekt.dir/shopping_list.c.obj"

# External object files for target P1_Projekt
P1_Projekt_EXTERNAL_OBJECTS =

P1_Projekt.exe: CMakeFiles/P1_Projekt.dir/main.c.obj
P1_Projekt.exe: CMakeFiles/P1_Projekt.dir/CalculateCheapestOption.c.obj
P1_Projekt.exe: CMakeFiles/P1_Projekt.dir/database_gen.c.obj
P1_Projekt.exe: CMakeFiles/P1_Projekt.dir/shopping_list.c.obj
P1_Projekt.exe: CMakeFiles/P1_Projekt.dir/build.make
P1_Projekt.exe: CMakeFiles/P1_Projekt.dir/linklibs.rsp
P1_Projekt.exe: CMakeFiles/P1_Projekt.dir/objects1.rsp
P1_Projekt.exe: CMakeFiles/P1_Projekt.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\danie\OneDrive\Uni\1. semester\IMPR\P1-Projekt\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable P1_Projekt.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\P1_Projekt.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/P1_Projekt.dir/build: P1_Projekt.exe
.PHONY : CMakeFiles/P1_Projekt.dir/build

CMakeFiles/P1_Projekt.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\P1_Projekt.dir\cmake_clean.cmake
.PHONY : CMakeFiles/P1_Projekt.dir/clean

CMakeFiles/P1_Projekt.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\danie\OneDrive\Uni\1. semester\IMPR\P1-Projekt" "C:\Users\danie\OneDrive\Uni\1. semester\IMPR\P1-Projekt" "C:\Users\danie\OneDrive\Uni\1. semester\IMPR\P1-Projekt\cmake-build-debug" "C:\Users\danie\OneDrive\Uni\1. semester\IMPR\P1-Projekt\cmake-build-debug" "C:\Users\danie\OneDrive\Uni\1. semester\IMPR\P1-Projekt\cmake-build-debug\CMakeFiles\P1_Projekt.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/P1_Projekt.dir/depend

