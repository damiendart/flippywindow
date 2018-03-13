magick convert FlippyWindow.svg -scale 16 tmp1.png
magick convert FlippyWindow.svg -scale 32 tmp2.png
magick convert FlippyWindow.svg -scale 48 tmp3.png
magick convert FlippyWindow.svg -scale 128 tmp4.png
magick convert FlippyWindow.svg -scale 256 tmp5.png
magick convert tmp*.png FlippyWindow.ico
del tmp*.png
