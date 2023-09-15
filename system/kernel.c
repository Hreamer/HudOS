#include "./GDT.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "./vga.h"

extern void reloadSegments();
extern void setGdt(void *, size_t);
 
void kernel_main(void) 
{
	/* Initialize terminal interface */
	terminal_initialize();

	/* Setup information for encoding GDT */
	static uint8_t gdt_table[24];
	struct GDT null_descriptor = {0, 0x00000000, 0x00, 0x0};
	struct GDT KM_CodeSegment = {0, 0xFFFFF, 0x9A, 0xC};
	struct GDT KM_DataSegment = {0, 0xFFFFF, 0x92, 0xC};

	/* encode the gdt table */
	encodeGdtEntry(&gdt_table[0], null_descriptor);
	encodeGdtEntry(&gdt_table[8], KM_CodeSegment);
	encodeGdtEntry(&gdt_table[16], KM_DataSegment);

	/* Tell CPU Where GDT is */
	setGdt(&gdt_table, 23);
	reloadSegments();
 
	terminal_writestring("Hello, Kernel World \n");
}
