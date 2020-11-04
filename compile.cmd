@echo off
cd Assembly
nasm.exe -f bin boot.asm -o boot.bin
pause
nasm.exe -f elf64 ExtendedProgram.asm -o ExtendedProgram.o
pause
move boot.bin "C:\Users\D\Desktop\sldpOS\sldpOS"
move ExtendedProgram.o "C:\Users\D\Desktop\sldpOS\sldpOS"
pause
cd ..
wsl /usr/local/x86_64elfgcc/bin/x86_64-elf-g++ -ffreestanding -mno-red-zone -m64 -c "./C/kernel.cpp" -o "Kernel.o"
ld -Ttext 0x8000 ExtendedProgram.o kernel.o -o kernel.tmp
objcopy -O binary kernel.tmp kernel.bin
copy /b boot.bin+kernel.bin bootloader.bin
pause
cd "C:\Program Files\qemu"
qemu-system-x86_64 -vga std -fda "C:\Users\D\Desktop\sldpOS\sldpOS\bootloader.bin"
