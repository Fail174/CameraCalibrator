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

# Include any dependencies generated for this target.
include src/CMakeFiles/onvifdiscovery.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/onvifdiscovery.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/onvifdiscovery.dir/flags.make

src/CMakeFiles/onvifdiscovery.dir/onvifdiscovery_autogen/mocs_compilation.cpp.o: src/CMakeFiles/onvifdiscovery.dir/flags.make
src/CMakeFiles/onvifdiscovery.dir/onvifdiscovery_autogen/mocs_compilation.cpp.o: src/onvifdiscovery_autogen/mocs_compilation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/libonvif/libONVIF/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/onvifdiscovery.dir/onvifdiscovery_autogen/mocs_compilation.cpp.o"
	cd /home/user/libonvif/libONVIF/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/onvifdiscovery.dir/onvifdiscovery_autogen/mocs_compilation.cpp.o -c /home/user/libonvif/libONVIF/build/src/onvifdiscovery_autogen/mocs_compilation.cpp

src/CMakeFiles/onvifdiscovery.dir/onvifdiscovery_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/onvifdiscovery.dir/onvifdiscovery_autogen/mocs_compilation.cpp.i"
	cd /home/user/libonvif/libONVIF/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/libonvif/libONVIF/build/src/onvifdiscovery_autogen/mocs_compilation.cpp > CMakeFiles/onvifdiscovery.dir/onvifdiscovery_autogen/mocs_compilation.cpp.i

src/CMakeFiles/onvifdiscovery.dir/onvifdiscovery_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/onvifdiscovery.dir/onvifdiscovery_autogen/mocs_compilation.cpp.s"
	cd /home/user/libonvif/libONVIF/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/libonvif/libONVIF/build/src/onvifdiscovery_autogen/mocs_compilation.cpp -o CMakeFiles/onvifdiscovery.dir/onvifdiscovery_autogen/mocs_compilation.cpp.s

src/CMakeFiles/onvifdiscovery.dir/OnvifDiscoveryClient.cpp.o: src/CMakeFiles/onvifdiscovery.dir/flags.make
src/CMakeFiles/onvifdiscovery.dir/OnvifDiscoveryClient.cpp.o: ../src/OnvifDiscoveryClient.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/libonvif/libONVIF/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/onvifdiscovery.dir/OnvifDiscoveryClient.cpp.o"
	cd /home/user/libonvif/libONVIF/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/onvifdiscovery.dir/OnvifDiscoveryClient.cpp.o -c /home/user/libonvif/libONVIF/src/OnvifDiscoveryClient.cpp

src/CMakeFiles/onvifdiscovery.dir/OnvifDiscoveryClient.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/onvifdiscovery.dir/OnvifDiscoveryClient.cpp.i"
	cd /home/user/libonvif/libONVIF/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/libonvif/libONVIF/src/OnvifDiscoveryClient.cpp > CMakeFiles/onvifdiscovery.dir/OnvifDiscoveryClient.cpp.i

src/CMakeFiles/onvifdiscovery.dir/OnvifDiscoveryClient.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/onvifdiscovery.dir/OnvifDiscoveryClient.cpp.s"
	cd /home/user/libonvif/libONVIF/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/libonvif/libONVIF/src/OnvifDiscoveryClient.cpp -o CMakeFiles/onvifdiscovery.dir/OnvifDiscoveryClient.cpp.s

src/CMakeFiles/onvifdiscovery.dir/OnvifDiscovery.cpp.o: src/CMakeFiles/onvifdiscovery.dir/flags.make
src/CMakeFiles/onvifdiscovery.dir/OnvifDiscovery.cpp.o: ../src/OnvifDiscovery.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/libonvif/libONVIF/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/onvifdiscovery.dir/OnvifDiscovery.cpp.o"
	cd /home/user/libonvif/libONVIF/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/onvifdiscovery.dir/OnvifDiscovery.cpp.o -c /home/user/libonvif/libONVIF/src/OnvifDiscovery.cpp

src/CMakeFiles/onvifdiscovery.dir/OnvifDiscovery.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/onvifdiscovery.dir/OnvifDiscovery.cpp.i"
	cd /home/user/libonvif/libONVIF/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/libonvif/libONVIF/src/OnvifDiscovery.cpp > CMakeFiles/onvifdiscovery.dir/OnvifDiscovery.cpp.i

src/CMakeFiles/onvifdiscovery.dir/OnvifDiscovery.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/onvifdiscovery.dir/OnvifDiscovery.cpp.s"
	cd /home/user/libonvif/libONVIF/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/libonvif/libONVIF/src/OnvifDiscovery.cpp -o CMakeFiles/onvifdiscovery.dir/OnvifDiscovery.cpp.s

src/CMakeFiles/onvifdiscovery.dir/DiscoveryMatch.cpp.o: src/CMakeFiles/onvifdiscovery.dir/flags.make
src/CMakeFiles/onvifdiscovery.dir/DiscoveryMatch.cpp.o: ../src/DiscoveryMatch.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/libonvif/libONVIF/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/onvifdiscovery.dir/DiscoveryMatch.cpp.o"
	cd /home/user/libonvif/libONVIF/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/onvifdiscovery.dir/DiscoveryMatch.cpp.o -c /home/user/libonvif/libONVIF/src/DiscoveryMatch.cpp

src/CMakeFiles/onvifdiscovery.dir/DiscoveryMatch.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/onvifdiscovery.dir/DiscoveryMatch.cpp.i"
	cd /home/user/libonvif/libONVIF/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/libonvif/libONVIF/src/DiscoveryMatch.cpp > CMakeFiles/onvifdiscovery.dir/DiscoveryMatch.cpp.i

src/CMakeFiles/onvifdiscovery.dir/DiscoveryMatch.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/onvifdiscovery.dir/DiscoveryMatch.cpp.s"
	cd /home/user/libonvif/libONVIF/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/libonvif/libONVIF/src/DiscoveryMatch.cpp -o CMakeFiles/onvifdiscovery.dir/DiscoveryMatch.cpp.s

src/CMakeFiles/onvifdiscovery.dir/generated/soapwsddProxy.cpp.o: src/CMakeFiles/onvifdiscovery.dir/flags.make
src/CMakeFiles/onvifdiscovery.dir/generated/soapwsddProxy.cpp.o: ../src/generated/soapwsddProxy.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/libonvif/libONVIF/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/onvifdiscovery.dir/generated/soapwsddProxy.cpp.o"
	cd /home/user/libonvif/libONVIF/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/onvifdiscovery.dir/generated/soapwsddProxy.cpp.o -c /home/user/libonvif/libONVIF/src/generated/soapwsddProxy.cpp

src/CMakeFiles/onvifdiscovery.dir/generated/soapwsddProxy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/onvifdiscovery.dir/generated/soapwsddProxy.cpp.i"
	cd /home/user/libonvif/libONVIF/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/libonvif/libONVIF/src/generated/soapwsddProxy.cpp > CMakeFiles/onvifdiscovery.dir/generated/soapwsddProxy.cpp.i

src/CMakeFiles/onvifdiscovery.dir/generated/soapwsddProxy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/onvifdiscovery.dir/generated/soapwsddProxy.cpp.s"
	cd /home/user/libonvif/libONVIF/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/libonvif/libONVIF/src/generated/soapwsddProxy.cpp -o CMakeFiles/onvifdiscovery.dir/generated/soapwsddProxy.cpp.s

# Object files for target onvifdiscovery
onvifdiscovery_OBJECTS = \
"CMakeFiles/onvifdiscovery.dir/onvifdiscovery_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/onvifdiscovery.dir/OnvifDiscoveryClient.cpp.o" \
"CMakeFiles/onvifdiscovery.dir/OnvifDiscovery.cpp.o" \
"CMakeFiles/onvifdiscovery.dir/DiscoveryMatch.cpp.o" \
"CMakeFiles/onvifdiscovery.dir/generated/soapwsddProxy.cpp.o"

# External object files for target onvifdiscovery
onvifdiscovery_EXTERNAL_OBJECTS =

src/libonvifdiscovery.so: src/CMakeFiles/onvifdiscovery.dir/onvifdiscovery_autogen/mocs_compilation.cpp.o
src/libonvifdiscovery.so: src/CMakeFiles/onvifdiscovery.dir/OnvifDiscoveryClient.cpp.o
src/libonvifdiscovery.so: src/CMakeFiles/onvifdiscovery.dir/OnvifDiscovery.cpp.o
src/libonvifdiscovery.so: src/CMakeFiles/onvifdiscovery.dir/DiscoveryMatch.cpp.o
src/libonvifdiscovery.so: src/CMakeFiles/onvifdiscovery.dir/generated/soapwsddProxy.cpp.o
src/libonvifdiscovery.so: src/CMakeFiles/onvifdiscovery.dir/build.make
src/libonvifdiscovery.so: src/libonvifcommon.so
src/libonvifdiscovery.so: /usr/lib/x86_64-linux-gnu/libssl.so
src/libonvifdiscovery.so: /usr/lib/x86_64-linux-gnu/libcrypto.so
src/libonvifdiscovery.so: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.12.8
src/libonvifdiscovery.so: src/CMakeFiles/onvifdiscovery.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/user/libonvif/libONVIF/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX shared library libonvifdiscovery.so"
	cd /home/user/libonvif/libONVIF/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/onvifdiscovery.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/onvifdiscovery.dir/build: src/libonvifdiscovery.so

.PHONY : src/CMakeFiles/onvifdiscovery.dir/build

src/CMakeFiles/onvifdiscovery.dir/clean:
	cd /home/user/libonvif/libONVIF/build/src && $(CMAKE_COMMAND) -P CMakeFiles/onvifdiscovery.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/onvifdiscovery.dir/clean

src/CMakeFiles/onvifdiscovery.dir/depend:
	cd /home/user/libonvif/libONVIF/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/user/libonvif/libONVIF /home/user/libonvif/libONVIF/src /home/user/libonvif/libONVIF/build /home/user/libonvif/libONVIF/build/src /home/user/libonvif/libONVIF/build/src/CMakeFiles/onvifdiscovery.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/onvifdiscovery.dir/depend

