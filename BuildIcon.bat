@REM Copyright (c) 2016-2018 Damien Dart, <https://www.robotinaponcho.net/>.
@REM This file is distributed under the MIT licence. For more
@REM information, please refer to the accompanying "LICENCE" file.


@ECHO OFF

WHERE magick >nul 2>nul
IF %ERRORLEVEL% EQU 0 (
  magick convert FlippyWindow.svg -scale 16 tmp1.png
  magick convert FlippyWindow.svg -scale 32 tmp2.png
  magick convert FlippyWindow.svg -scale 48 tmp3.png
  magick convert FlippyWindow.svg -scale 128 tmp4.png
  magick convert FlippyWindow.svg -scale 256 tmp5.png
  magick convert tmp*.png FlippyWindow.ico
  del tmp*.png
  ECHO "FlippyWindow.ico" created!
) ELSE (
  ECHO ERROR: ImageMagick is required.
)

@ECHO ON
