KERNEL_PATH = ../system/kernel.c
KERNEL_DEPS = ../system/vga.h ../system/GDT.h
KERNEL_FLAGS = -o kernel.o -std=gnu99 -ffreestanding -nostdlib -Wall -Wextra -m32

BIN_FLAGS = -T linker.ld -o myos.bin -ffreestanding -nostdlib boot.o kernel.o -m32

run : myos.bin
	qemu-system-i386 -kernel myos.bin

myos.bin : kernel.o boot.o
	gcc $(BIN_FLAGS)

clean : 
	rm kernel.o
	rm boot.o
	rm myos.bin

kernel.o : 
	gcc -r $(KERNEL_PATH) $(KERNEL_DEPS) $(KERNEL_FLAGS)
#gcc -o myos.bin FOR SOME REASON WAS HERE

boot.o : 
	nasm -felf32 ../bootloader/boot.asm -o boot.o