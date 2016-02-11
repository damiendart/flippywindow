project("FlippyWindow")
add_executable(FlippyWindow WIN32 FlippyWindow.cpp)
target_link_libraries(FlippyWindow magnification.lib)
