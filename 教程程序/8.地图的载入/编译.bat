@echo off
IF not EXIST Nes_output.nes goto build
del Nes_output.nes
:build
echo ���ڱ���.....
cl65 -o Nes_output.nes -t nes *.c
IF not EXIST Nes_output.nes goto end
echo ��ʾ:������ɣ�
exit
:end
echo ��ʾ:����ʧ�ܣ�




