KERNEL_PATH = ../system/kernel.c
KERNEL_DEPS = ../system/vga.h
KERNEL_FLAGS = -o kernel.o -std=gnu99 -ffreestanding -nostdlib -Wall -Wextra -m32

BIN_FLAGS = -T linker.ld -o myos.bin -ffreestanding -nostdlib boot.o kernel.o -m32

run : myos.bin
	qemu-system-i386 -kernel myos.bin

bin : kernel.o boot.o
	gcc $(BIN_FLAGS)
	rm kernel.o
	rm boot.o

clean : 
	rm kernel.o
	rm boot.o

kernel.o : 
	gcc -r $(KERNEL_PATH) $(KERNEL_DEPS) $(KERNEL_FLAGS)

boot.o : 
	nasm -felf32 ../bootloader/boot.asm -o boot.o