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
gcc -Ttext 0x8000 -ffreestanding -mno-red-zone -m64 -c "./C/Kernel.cpp" -o "Kernel.o"
ld -T"link.ld"
objcopy -O binary kernel.tmp kernel.bin
copy /b boot.bin+kernel.bin bootloader.bin
pause
cd "C:\Program Files\qemu"
qemu-system-x86_64 -fda "C:\Users\D\Desktop\sldpOS\sldpOS\bootloader.bin"
