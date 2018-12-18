@echo off
IF not EXIST Nes_output.nes goto build
del Nes_output.nes
:build
echo 正在编译.....
cl65 -o Nes_output.nes -t nes *.c
IF not EXIST Nes_output.nes goto end
echo 提示:编译完成！
exit
:end
echo 提示:编译失败！




