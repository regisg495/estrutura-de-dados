# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2.1\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\regis\CLionProjects\AlgoritmosOrdenacaoEBusca

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\regis\CLionProjects\AlgoritmosOrdenacaoEBusca\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SearchAndSortAlgorithms.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SearchAndSortAlgorithms.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SearchAndSortAlgorithms.dir/flags.make

CMakeFiles/SearchAndSortAlgorithms.dir/main.c.obj: CMakeFiles/SearchAndSortAlgorithms.dir/flags.make
CMakeFiles/SearchAndSortAlgorithms.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\regis\CLionProjects\AlgoritmosOrdenacaoEBusca\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/SearchAndSortAlgorithms.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\SearchAndSortAlgorithms.dir\main.c.obj   -c C:\Users\regis\CLionProjects\AlgoritmosOrdenacaoEBusca\main.c

CMakeFiles/SearchAndSortAlgorithms.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SearchAndSortAlgorithms.dir/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\regis\CLionProjects\AlgoritmosOrdenacaoEBusca\main.c > CMakeFiles\SearchAndSortAlgorithms.dir\main.c.i

CMakeFiles/SearchAndSortAlgorithms.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SearchAndSortAlgorithms.dir/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\regis\CLionProjects\AlgoritmosOrdenacaoEBusca\main.c -o CMakeFiles\SearchAndSortAlgorithms.dir\main.c.s

CMakeFiles/SearchAndSortAlgorithms.dir/sort.c.obj: CMakeFiles/SearchAndSortAlgorithms.dir/flags.make
CMakeFiles/SearchAndSortAlgorithms.dir/sort.c.obj: ../sort.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\regis\CLionProjects\AlgoritmosOrdenacaoEBusca\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/SearchAndSortAlgorithms.dir/sort.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\SearchAndSortAlgorithms.dir\sort.c.obj   -c C:\Users\regis\CLionProjects\AlgoritmosOrdenacaoEBusca\sort.c

CMakeFiles/SearchAndSortAlgorithms.dir/sort.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SearchAndSortAlgorithms.dir/sort.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\regis\CLionProjects\AlgoritmosOrdenacaoEBusca\sort.c > CMakeFiles\SearchAndSortAlgorithms.dir\sort.c.i

CMakeFiles/SearchAndSortAlgorithms.dir/sort.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SearchAndSortAlgorithms.dir/sort.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\regis\CLionProjects\AlgoritmosOrdenacaoEBusca\sort.c -o CMakeFiles\SearchAndSortAlgorithms.dir\sort.c.s

CMakeFiles/SearchAndSortAlgorithms.dir/search.c.obj: CMakeFiles/SearchAndSortAlgorithms.dir/flags.make
CMakeFiles/SearchAndSortAlgorithms.dir/search.c.obj: ../search.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\regis\CLionProjects\AlgoritmosOrdenacaoEBusca\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/SearchAndSortAlgorithms.dir/search.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\SearchAndSortAlgorithms.dir\search.c.obj   -c C:\Users\regis\CLionProjects\AlgoritmosOrdenacaoEBusca\search.c

CMakeFiles/SearchAndSortAlgorithms.dir/search.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SearchAndSortAlgorithms.dir/search.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\regis\CLionProjects\AlgoritmosOrdenacaoEBusca\search.c > CMakeFiles\SearchAndSortAlgorithms.dir\search.c.i

CMakeFiles/SearchAndSortAlgorithms.dir/search.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SearchAndSortAlgorithms.dir/search.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\regis\CLionProjects\AlgoritmosOrdenacaoEBusca\search.c -o CMakeFiles\SearchAndSortAlgorithms.dir\search.c.s

CMakeFiles/SearchAndSortAlgorithms.dir/basiclist.c.obj: CMakeFiles/SearchAndSortAlgorithms.dir/flags.make
CMakeFiles/SearchAndSortAlgorithms.dir/basiclist.c.obj: ../basiclist.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\regis\CLionProjects\AlgoritmosOrdenacaoEBusca\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/SearchAndSortAlgorithms.dir/basiclist.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\SearchAndSortAlgorithms.dir\basiclist.c.obj   -c C:\Users\regis\CLionProjects\AlgoritmosOrdenacaoEBusca\basiclist.c

CMakeFiles/SearchAndSortAlgorithms.dir/basiclist.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SearchAndSortAlgorithms.dir/basiclist.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\regis\CLionProjects\AlgoritmosOrdenacaoEBusca\basiclist.c > CMakeFiles\SearchAndSortAlgorithms.dir\basiclist.c.i

CMakeFiles/SearchAndSortAlgorithms.dir/basiclist.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SearchAndSortAlgorithms.dir/basiclist.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\regis\CLionProjects\AlgoritmosOrdenacaoEBusca\basiclist.c -o CMakeFiles\SearchAndSortAlgorithms.dir\basiclist.c.s

# Object files for target SearchAndSortAlgorithms
SearchAndSortAlgorithms_OBJECTS = \
"CMakeFiles/SearchAndSortAlgorithms.dir/main.c.obj" \
"CMakeFiles/SearchAndSortAlgorithms.dir/sort.c.obj" \
"CMakeFiles/SearchAndSortAlgorithms.dir/search.c.obj" \
"CMakeFiles/SearchAndSortAlgorithms.dir/basiclist.c.obj"

# External object files for target SearchAndSortAlgorithms
SearchAndSortAlgorithms_EXTERNAL_OBJECTS =

SearchAndSortAlgorithms.exe: CMakeFiles/SearchAndSortAlgorithms.dir/main.c.obj
SearchAndSortAlgorithms.exe: CMakeFiles/SearchAndSortAlgorithms.dir/sort.c.obj
SearchAndSortAlgorithms.exe: CMakeFiles/SearchAndSortAlgorithms.dir/search.c.obj
SearchAndSortAlgorithms.exe: CMakeFiles/SearchAndSortAlgorithms.dir/basiclist.c.obj
SearchAndSortAlgorithms.exe: CMakeFiles/SearchAndSortAlgorithms.dir/build.make
SearchAndSortAlgorithms.exe: CMakeFiles/SearchAndSortAlgorithms.dir/linklibs.rsp
SearchAndSortAlgorithms.exe: CMakeFiles/SearchAndSortAlgorithms.dir/objects1.rsp
SearchAndSortAlgorithms.exe: CMakeFiles/SearchAndSortAlgorithms.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\regis\CLionProjects\AlgoritmosOrdenacaoEBusca\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable SearchAndSortAlgorithms.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\SearchAndSortAlgorithms.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SearchAndSortAlgorithms.dir/build: SearchAndSortAlgorithms.exe

.PHONY : CMakeFiles/SearchAndSortAlgorithms.dir/build

CMakeFiles/SearchAndSortAlgorithms.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\SearchAndSortAlgorithms.dir\cmake_clean.cmake
.PHONY : CMakeFiles/SearchAndSortAlgorithms.dir/clean

CMakeFiles/SearchAndSortAlgorithms.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\regis\CLionProjects\AlgoritmosOrdenacaoEBusca C:\Users\regis\CLionProjects\AlgoritmosOrdenacaoEBusca C:\Users\regis\CLionProjects\AlgoritmosOrdenacaoEBusca\cmake-build-debug C:\Users\regis\CLionProjects\AlgoritmosOrdenacaoEBusca\cmake-build-debug C:\Users\regis\CLionProjects\AlgoritmosOrdenacaoEBusca\cmake-build-debug\CMakeFiles\SearchAndSortAlgorithms.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SearchAndSortAlgorithms.dir/depend

