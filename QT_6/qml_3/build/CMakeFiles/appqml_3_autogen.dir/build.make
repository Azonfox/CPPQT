# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/azfox/PROJECT/CPPQT/QT_6/qml_3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/azfox/PROJECT/CPPQT/QT_6/qml_3/build

# Utility rule file for appqml_3_autogen.

# Include any custom commands dependencies for this target.
include CMakeFiles/appqml_3_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/appqml_3_autogen.dir/progress.make

CMakeFiles/appqml_3_autogen: .rcc/qmlcache/appqml_3_qmlcache_loader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/azfox/PROJECT/CPPQT/QT_6/qml_3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC for target appqml_3"
	/usr/bin/cmake -E cmake_autogen /home/azfox/PROJECT/CPPQT/QT_6/qml_3/build/CMakeFiles/appqml_3_autogen.dir/AutogenInfo.json ""

.rcc/qmlcache/appqml_3_qmlcache_loader.cpp: /usr/lib/qt6/libexec/qmlcachegen
.rcc/qmlcache/appqml_3_qmlcache_loader.cpp: .rcc/qmlcache/appqml_3_qml_loader_file_list.rsp
.rcc/qmlcache/appqml_3_qmlcache_loader.cpp: .rcc/qmake_qml_3.qrc
.rcc/qmlcache/appqml_3_qmlcache_loader.cpp: .rcc/appqml_3_raw_qml_0.qrc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/azfox/PROJECT/CPPQT/QT_6/qml_3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating .rcc/qmlcache/appqml_3_qmlcache_loader.cpp"
	/usr/lib/qt6/libexec/qmlcachegen --resource-name qmlcache_appqml_3 --resource /home/azfox/PROJECT/CPPQT/QT_6/qml_3/build/.rcc/qmake_qml_3.qrc --resource /home/azfox/PROJECT/CPPQT/QT_6/qml_3/build/.rcc/appqml_3_raw_qml_0.qrc -o /home/azfox/PROJECT/CPPQT/QT_6/qml_3/build/.rcc/qmlcache/appqml_3_qmlcache_loader.cpp @/home/azfox/PROJECT/CPPQT/QT_6/qml_3/build/.rcc/qmlcache/appqml_3_qml_loader_file_list.rsp

appqml_3_autogen: .rcc/qmlcache/appqml_3_qmlcache_loader.cpp
appqml_3_autogen: CMakeFiles/appqml_3_autogen
appqml_3_autogen: CMakeFiles/appqml_3_autogen.dir/build.make
.PHONY : appqml_3_autogen

# Rule to build all files generated by this target.
CMakeFiles/appqml_3_autogen.dir/build: appqml_3_autogen
.PHONY : CMakeFiles/appqml_3_autogen.dir/build

CMakeFiles/appqml_3_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/appqml_3_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/appqml_3_autogen.dir/clean

CMakeFiles/appqml_3_autogen.dir/depend:
	cd /home/azfox/PROJECT/CPPQT/QT_6/qml_3/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/azfox/PROJECT/CPPQT/QT_6/qml_3 /home/azfox/PROJECT/CPPQT/QT_6/qml_3 /home/azfox/PROJECT/CPPQT/QT_6/qml_3/build /home/azfox/PROJECT/CPPQT/QT_6/qml_3/build /home/azfox/PROJECT/CPPQT/QT_6/qml_3/build/CMakeFiles/appqml_3_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/appqml_3_autogen.dir/depend

