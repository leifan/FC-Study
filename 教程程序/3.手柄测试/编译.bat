@echo off
IF not EXIST Nes_output.nes goto build
del Nes_output.nes
:build
echo 正在编译.....
cl65 -o Nes_output.nes -t nes *.c
echo 编译完成


