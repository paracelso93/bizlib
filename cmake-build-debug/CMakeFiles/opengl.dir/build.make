# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/edoardobiasio/CLionProjects/opengl/bizlib

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/edoardobiasio/CLionProjects/opengl/bizlib/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/opengl.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/opengl.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/opengl.dir/flags.make

CMakeFiles/opengl.dir/main.cpp.o: CMakeFiles/opengl.dir/flags.make
CMakeFiles/opengl.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/edoardobiasio/CLionProjects/opengl/bizlib/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/opengl.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opengl.dir/main.cpp.o -c /Users/edoardobiasio/CLionProjects/opengl/bizlib/main.cpp

CMakeFiles/opengl.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opengl.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/edoardobiasio/CLionProjects/opengl/bizlib/main.cpp > CMakeFiles/opengl.dir/main.cpp.i

CMakeFiles/opengl.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opengl.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/edoardobiasio/CLionProjects/opengl/bizlib/main.cpp -o CMakeFiles/opengl.dir/main.cpp.s

CMakeFiles/opengl.dir/shader.cpp.o: CMakeFiles/opengl.dir/flags.make
CMakeFiles/opengl.dir/shader.cpp.o: ../shader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/edoardobiasio/CLionProjects/opengl/bizlib/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/opengl.dir/shader.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opengl.dir/shader.cpp.o -c /Users/edoardobiasio/CLionProjects/opengl/bizlib/shader.cpp

CMakeFiles/opengl.dir/shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opengl.dir/shader.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/edoardobiasio/CLionProjects/opengl/bizlib/shader.cpp > CMakeFiles/opengl.dir/shader.cpp.i

CMakeFiles/opengl.dir/shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opengl.dir/shader.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/edoardobiasio/CLionProjects/opengl/bizlib/shader.cpp -o CMakeFiles/opengl.dir/shader.cpp.s

CMakeFiles/opengl.dir/texture.cpp.o: CMakeFiles/opengl.dir/flags.make
CMakeFiles/opengl.dir/texture.cpp.o: ../texture.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/edoardobiasio/CLionProjects/opengl/bizlib/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/opengl.dir/texture.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opengl.dir/texture.cpp.o -c /Users/edoardobiasio/CLionProjects/opengl/bizlib/texture.cpp

CMakeFiles/opengl.dir/texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opengl.dir/texture.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/edoardobiasio/CLionProjects/opengl/bizlib/texture.cpp > CMakeFiles/opengl.dir/texture.cpp.i

CMakeFiles/opengl.dir/texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opengl.dir/texture.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/edoardobiasio/CLionProjects/opengl/bizlib/texture.cpp -o CMakeFiles/opengl.dir/texture.cpp.s

CMakeFiles/opengl.dir/color_rect.cpp.o: CMakeFiles/opengl.dir/flags.make
CMakeFiles/opengl.dir/color_rect.cpp.o: ../color_rect.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/edoardobiasio/CLionProjects/opengl/bizlib/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/opengl.dir/color_rect.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opengl.dir/color_rect.cpp.o -c /Users/edoardobiasio/CLionProjects/opengl/bizlib/color_rect.cpp

CMakeFiles/opengl.dir/color_rect.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opengl.dir/color_rect.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/edoardobiasio/CLionProjects/opengl/bizlib/color_rect.cpp > CMakeFiles/opengl.dir/color_rect.cpp.i

CMakeFiles/opengl.dir/color_rect.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opengl.dir/color_rect.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/edoardobiasio/CLionProjects/opengl/bizlib/color_rect.cpp -o CMakeFiles/opengl.dir/color_rect.cpp.s

CMakeFiles/opengl.dir/window.cpp.o: CMakeFiles/opengl.dir/flags.make
CMakeFiles/opengl.dir/window.cpp.o: ../window.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/edoardobiasio/CLionProjects/opengl/bizlib/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/opengl.dir/window.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opengl.dir/window.cpp.o -c /Users/edoardobiasio/CLionProjects/opengl/bizlib/window.cpp

CMakeFiles/opengl.dir/window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opengl.dir/window.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/edoardobiasio/CLionProjects/opengl/bizlib/window.cpp > CMakeFiles/opengl.dir/window.cpp.i

CMakeFiles/opengl.dir/window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opengl.dir/window.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/edoardobiasio/CLionProjects/opengl/bizlib/window.cpp -o CMakeFiles/opengl.dir/window.cpp.s

CMakeFiles/opengl.dir/biz.cpp.o: CMakeFiles/opengl.dir/flags.make
CMakeFiles/opengl.dir/biz.cpp.o: ../biz.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/edoardobiasio/CLionProjects/opengl/bizlib/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/opengl.dir/biz.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opengl.dir/biz.cpp.o -c /Users/edoardobiasio/CLionProjects/opengl/bizlib/biz.cpp

CMakeFiles/opengl.dir/biz.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opengl.dir/biz.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/edoardobiasio/CLionProjects/opengl/bizlib/biz.cpp > CMakeFiles/opengl.dir/biz.cpp.i

CMakeFiles/opengl.dir/biz.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opengl.dir/biz.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/edoardobiasio/CLionProjects/opengl/bizlib/biz.cpp -o CMakeFiles/opengl.dir/biz.cpp.s

# Object files for target opengl
opengl_OBJECTS = \
"CMakeFiles/opengl.dir/main.cpp.o" \
"CMakeFiles/opengl.dir/shader.cpp.o" \
"CMakeFiles/opengl.dir/texture.cpp.o" \
"CMakeFiles/opengl.dir/color_rect.cpp.o" \
"CMakeFiles/opengl.dir/window.cpp.o" \
"CMakeFiles/opengl.dir/biz.cpp.o"

# External object files for target opengl
opengl_EXTERNAL_OBJECTS =

opengl: CMakeFiles/opengl.dir/main.cpp.o
opengl: CMakeFiles/opengl.dir/shader.cpp.o
opengl: CMakeFiles/opengl.dir/texture.cpp.o
opengl: CMakeFiles/opengl.dir/color_rect.cpp.o
opengl: CMakeFiles/opengl.dir/window.cpp.o
opengl: CMakeFiles/opengl.dir/biz.cpp.o
opengl: CMakeFiles/opengl.dir/build.make
opengl: CMakeFiles/opengl.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/edoardobiasio/CLionProjects/opengl/bizlib/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable opengl"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/opengl.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/opengl.dir/build: opengl

.PHONY : CMakeFiles/opengl.dir/build

CMakeFiles/opengl.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/opengl.dir/cmake_clean.cmake
.PHONY : CMakeFiles/opengl.dir/clean

CMakeFiles/opengl.dir/depend:
	cd /Users/edoardobiasio/CLionProjects/opengl/bizlib/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/edoardobiasio/CLionProjects/opengl/bizlib /Users/edoardobiasio/CLionProjects/opengl/bizlib /Users/edoardobiasio/CLionProjects/opengl/bizlib/cmake-build-debug /Users/edoardobiasio/CLionProjects/opengl/bizlib/cmake-build-debug /Users/edoardobiasio/CLionProjects/opengl/bizlib/cmake-build-debug/CMakeFiles/opengl.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/opengl.dir/depend

