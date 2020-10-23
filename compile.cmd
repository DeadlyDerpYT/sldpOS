@echo off
cd Assembly
nasm.exe -f bin boot.asm -o boot.bin
nasm.exe -f bin ExtendedProgram.asm -o ExtendedProgram.bin
pause
move boot.bin "C:\Users\D\Desktop\sldpOS\sldpOS"
move ExtendedProgram.bin "C:\Users\D\Desktop\sldpOS\sldpOS"
pause
cd ..
copy /b boot.bin+ExtendedProgram.bin bootloader.bin
pause
cd "C:\Program Files\qemu"
qemu-system-x86_64 -fda "C:\Users\D\Desktop\sldpOS\sldpOS\bootloader.bin"