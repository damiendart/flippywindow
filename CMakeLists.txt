# Copyright (c) 2016 Damien Dart, <http://www.robotinaponcho.net/>.
# This file is distributed under the MIT licence. For more information,
# please refer to the accompanying "LICENCE" file.

project("FlippyWindow")
set(VERSION_MAJOR 0)
set(VERSION_MINOR 1)
configure_file(
  "${PROJECT_SOURCE_DIR}/FlippyWindow.h.in"
  "${PROJECT_SOURCE_DIR}/FlippyWindow.h")
include_directories("${PROJECT_SOURCE_DIR}")
add_executable(FlippyWindow WIN32 FlippyWindow.cpp FlippyWindow.rc)
target_link_libraries(FlippyWindow magnification.lib)
