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
include src/CMakeFiles/onvifimaging.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/onvifimaging.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/onvifimaging.dir/flags.make

src/CMakeFiles/onvifimaging.dir/onvifimaging_autogen/mocs_compilation.cpp.o: src/CMakeFiles/onvifimaging.dir/flags.make
src/CMakeFiles/onvifimaging.dir/onvifimaging_autogen/mocs_compilation.cpp.o: src/onvifimaging_autogen/mocs_compilation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/libonvif/libONVIF/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/onvifimaging.dir/onvifimaging_autogen/mocs_compilation.cpp.o"
	cd /home/user/libonvif/libONVIF/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/onvifimaging.dir/onvifimaging_autogen/mocs_compilation.cpp.o -c /home/user/libonvif/libONVIF/build/src/onvifimaging_autogen/mocs_compilation.cpp

src/CMakeFiles/onvifimaging.dir/onvifimaging_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/onvifimaging.dir/onvifimaging_autogen/mocs_compilation.cpp.i"
	cd /home/user/libonvif/libONVIF/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/libonvif/libONVIF/build/src/onvifimaging_autogen/mocs_compilation.cpp > CMakeFiles/onvifimaging.dir/onvifimaging_autogen/mocs_compilation.cpp.i

src/CMakeFiles/onvifimaging.dir/onvifimaging_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/onvifimaging.dir/onvifimaging_autogen/mocs_compilation.cpp.s"
	cd /home/user/libonvif/libONVIF/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/libonvif/libONVIF/build/src/onvifimaging_autogen/mocs_compilation.cpp -o CMakeFiles/onvifimaging.dir/onvifimaging_autogen/mocs_compilation.cpp.s

src/CMakeFiles/onvifimaging.dir/generated/soapImagingBindingProxy.cpp.o: src/CMakeFiles/onvifimaging.dir/flags.make
src/CMakeFiles/onvifimaging.dir/generated/soapImagingBindingProxy.cpp.o: ../src/generated/soapImagingBindingProxy.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/libonvif/libONVIF/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/onvifimaging.dir/generated/soapImagingBindingProxy.cpp.o"
	cd /home/user/libonvif/libONVIF/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/onvifimaging.dir/generated/soapImagingBindingProxy.cpp.o -c /home/user/libonvif/libONVIF/src/generated/soapImagingBindingProxy.cpp

src/CMakeFiles/onvifimaging.dir/generated/soapImagingBindingProxy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/onvifimaging.dir/generated/soapImagingBindingProxy.cpp.i"
	cd /home/user/libonvif/libONVIF/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/libonvif/libONVIF/src/generated/soapImagingBindingProxy.cpp > CMakeFiles/onvifimaging.dir/generated/soapImagingBindingProxy.cpp.i

src/CMakeFiles/onvifimaging.dir/generated/soapImagingBindingProxy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/onvifimaging.dir/generated/soapImagingBindingProxy.cpp.s"
	cd /home/user/libonvif/libONVIF/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/libonvif/libONVIF/src/generated/soapImagingBindingProxy.cpp -o CMakeFiles/onvifimaging.dir/generated/soapImagingBindingProxy.cpp.s

src/CMakeFiles/onvifimaging.dir/OnvifImagingClient.cpp.o: src/CMakeFiles/onvifimaging.dir/flags.make
src/CMakeFiles/onvifimaging.dir/OnvifImagingClient.cpp.o: ../src/OnvifImagingClient.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/libonvif/libONVIF/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/onvifimaging.dir/OnvifImagingClient.cpp.o"
	cd /home/user/libonvif/libONVIF/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/onvifimaging.dir/OnvifImagingClient.cpp.o -c /home/user/libonvif/libONVIF/src/OnvifImagingClient.cpp

src/CMakeFiles/onvifimaging.dir/OnvifImagingClient.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/onvifimaging.dir/OnvifImagingClient.cpp.i"
	cd /home/user/libonvif/libONVIF/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/libonvif/libONVIF/src/OnvifImagingClient.cpp > CMakeFiles/onvifimaging.dir/OnvifImagingClient.cpp.i

src/CMakeFiles/onvifimaging.dir/OnvifImagingClient.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/onvifimaging.dir/OnvifImagingClient.cpp.s"
	cd /home/user/libonvif/libONVIF/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/libonvif/libONVIF/src/OnvifImagingClient.cpp -o CMakeFiles/onvifimaging.dir/OnvifImagingClient.cpp.s

# Object files for target onvifimaging
onvifimaging_OBJECTS = \
"CMakeFiles/onvifimaging.dir/onvifimaging_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/onvifimaging.dir/generated/soapImagingBindingProxy.cpp.o" \
"CMakeFiles/onvifimaging.dir/OnvifImagingClient.cpp.o"

# External object files for target onvifimaging
onvifimaging_EXTERNAL_OBJECTS =

src/libonvifimaging.so: src/CMakeFiles/onvifimaging.dir/onvifimaging_autogen/mocs_compilation.cpp.o
src/libonvifimaging.so: src/CMakeFiles/onvifimaging.dir/generated/soapImagingBindingProxy.cpp.o
src/libonvifimaging.so: src/CMakeFiles/onvifimaging.dir/OnvifImagingClient.cpp.o
src/libonvifimaging.so: src/CMakeFiles/onvifimaging.dir/build.make
src/libonvifimaging.so: src/libonvifcommon.so
src/libonvifimaging.so: /usr/lib/x86_64-linux-gnu/libssl.so
src/libonvifimaging.so: /usr/lib/x86_64-linux-gnu/libcrypto.so
src/libonvifimaging.so: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.12.8
src/libonvifimaging.so: src/CMakeFiles/onvifimaging.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/user/libonvif/libONVIF/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX shared library libonvifimaging.so"
	cd /home/user/libonvif/libONVIF/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/onvifimaging.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/onvifimaging.dir/build: src/libonvifimaging.so

.PHONY : src/CMakeFiles/onvifimaging.dir/build

src/CMakeFiles/onvifimaging.dir/clean:
	cd /home/user/libonvif/libONVIF/build/src && $(CMAKE_COMMAND) -P CMakeFiles/onvifimaging.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/onvifimaging.dir/clean

src/CMakeFiles/onvifimaging.dir/depend:
	cd /home/user/libonvif/libONVIF/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/user/libonvif/libONVIF /home/user/libonvif/libONVIF/src /home/user/libonvif/libONVIF/build /home/user/libonvif/libONVIF/build/src /home/user/libonvif/libONVIF/build/src/CMakeFiles/onvifimaging.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/onvifimaging.dir/depend

