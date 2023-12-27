FlippyWindow
============

[FlippyWindow][] is a simple Windows application that non-destructively
flips any part of your screen horizontally, in real-time and using
minimal resources. Flipping images (or viewing things with a mirror) is
a technique used to [help view things with “fresh eyes”][] which can aid
with [spotting visual issues][].

FlippyWindow requires Windows 8 or a later Windows operating system as
it (ab)uses the [second release of the Magnification API][].

  [FlippyWindow]: <https://www.robotinaponcho.net/projects/flippywindow/>
  [help view things with “fresh eyes”]: <http://www.comic-tools.com/2008/10/my-mirror-is-most-important.html>
  [spotting visual issues]: <https://yourfirstproduct.com/info/bmreverse>
  [second release of the Magnification API]: <https://msdn.microsoft.com/en-us/library/windows/desktop/ms692162(v=vs.85).aspx>


## Building FlippyWindow

1)  Grab a copy of [FlippyWindow’s source code][] (which is also
    available on [GitHub][]).
2)  Build FlippyWindow’s icon with “BuildIcon.bat” (you’ll need
    [ImageMagick][] installed and available from the command line).
3)  Use CMake to generate Visual Studio bumf.
4)  Use the generated Visual Studio bumf to build FlippyWindow.

  [FlippyWindow’s source code]: <https://www.robotinaponcho.net/git/flippywindow.git>
  [GitHub]: <https://github.com/damiendart/flippywindow>
  [ImageMagick]: <https://www.imagemagick.org/>


## Licence

FlippyWindow is written by Damien Dart and is licenced under the MIT
licence. For more information, please refer to the accompanying
“LICENCE” file.
