# Copyright (c) 2016-2018 Damien Dart, <https://www.robotinaponcho.net/>.
# This file is distributed under the MIT licence. For more information,
# please refer to the accompanying "LICENCE" file.

cmake_minimum_required (VERSION 2.6)

project("FlippyWindow")
set(VERSION_MAJOR 0)
set(VERSION_MINOR 1)
configure_file(
  "${PROJECT_SOURCE_DIR}/FlippyWindow.h.in"
  "${PROJECT_SOURCE_DIR}/FlippyWindow.h")
include_directories("${PROJECT_SOURCE_DIR}")
add_executable(FlippyWindow WIN32 FlippyWindow.cpp FlippyWindow.rc)
target_link_libraries(FlippyWindow magnification.lib)
