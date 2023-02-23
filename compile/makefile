KERNEL_PATH = ../system/kernel.c
KERNEL_DEPS = ../system/vga.h

run : myos.bin
	qemu-system-i386 -kernel myos.bin

bin : kernel.o boot.o
	gcc -T linker.ld -o myos.bin -ffreestanding -nostdlib boot.o kernel.o -m32
	rm kernel.o
	rm boot.o

clean : 
	rm kernel.o
	rm boot.o

kernel.o : 
	gcc -r $(KERNEL_PATH) $(KERNEL_DEPS) -o kernel.o -std=gnu99 -ffreestanding -nostdlib -Wall -Wextra -m32

boot.o : 
	nasm -felf32 ../bootloader/boot.asm -o boot.o