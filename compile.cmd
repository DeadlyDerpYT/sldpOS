@echo off
cd Assembly
nasm.exe -f bin boot.asm -o boot.bin
nasm.exe -f bin ExtendedProgram.asm -o ExtendedProgram.bin
move boot.bin "C:\Users\D\Desktop\sldpOS"
move ExtendedProgram.bin "C:\Users\D\Desktop\sldpOS"
pause
cd ..
copy /b boot.bin+ExtendedProgram.bin bootloader.bin
pause
cd "C:\Program Files\qemu"
qemu-system-x86_64 "C:\Users\D\Desktop\sldpOS\bootloader.bin"