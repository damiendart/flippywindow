# Copyright (c) 2016 Damien Dart, <http://www.robotinaponcho.net/>.
# This file is distributed under the MIT licence. For more information,
# please refer to the accompanying "LICENCE" file.

project("FlippyWindow")
add_executable(FlippyWindow WIN32 FlippyWindow.cpp)
target_link_libraries(FlippyWindow magnification.lib)
