# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/user/libonvif/libONVIF

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/user/libonvif/libONVIF/build

# Utility rule file for onvifdiscovery_autogen.

# Include the progress variables for this target.
include src/CMakeFiles/onvifdiscovery_autogen.dir/progress.make

src/CMakeFiles/onvifdiscovery_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/user/libonvif/libONVIF/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC for target onvifdiscovery"
	cd /home/user/libonvif/libONVIF/build/src && /usr/bin/cmake -E cmake_autogen /home/user/libonvif/libONVIF/build/src/CMakeFiles/onvifdiscovery_autogen.dir/AutogenInfo.json Release

onvifdiscovery_autogen: src/CMakeFiles/onvifdiscovery_autogen
onvifdiscovery_autogen: src/CMakeFiles/onvifdiscovery_autogen.dir/build.make

.PHONY : onvifdiscovery_autogen

# Rule to build all files generated by this target.
src/CMakeFiles/onvifdiscovery_autogen.dir/build: onvifdiscovery_autogen

.PHONY : src/CMakeFiles/onvifdiscovery_autogen.dir/build

src/CMakeFiles/onvifdiscovery_autogen.dir/clean:
	cd /home/user/libonvif/libONVIF/build/src && $(CMAKE_COMMAND) -P CMakeFiles/onvifdiscovery_autogen.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/onvifdiscovery_autogen.dir/clean

src/CMakeFiles/onvifdiscovery_autogen.dir/depend:
	cd /home/user/libonvif/libONVIF/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/user/libonvif/libONVIF /home/user/libonvif/libONVIF/src /home/user/libonvif/libONVIF/build /home/user/libonvif/libONVIF/build/src /home/user/libonvif/libONVIF/build/src/CMakeFiles/onvifdiscovery_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/onvifdiscovery_autogen.dir/depend
