//Kernel specific
#include "common.h"
#include "monitor.h"
#include "descriptor_tables.h"
#include "isr.h"
#include "multiboot.h"
#include "clock.h"

//Untested
#include "kheap.h"
#include "paging.h"

int main(struct multiboot* mboot_ptr){
	vga_clear();
	vga_puts("main(): loaded Kernel\n");
	init_descriptor_tables();
	vga_puts("main(): initialized memory protection map\n");
	
	vga_puts("main(): attempting to initialize paging\n");
	init_paging();
	
	vga_puts("main(): making kheap\n");
	init_kheap();
	
	void* x = kmalloc(16);
	void* y = kmalloc(16);
	vga_puts_hex(x);
	vga_puts("\n");
	vga_puts_hex(y);
	vga_puts("\n");
	kfree(x);
	kfree(y);
	x = kmalloc(16);
	y = kmalloc(16);
	vga_puts_hex(x);
	vga_puts("\n");
	
	vga_puts("main(): initializing read-only ramdisk\n");
	mnt_initrd(mboot_ptr->mods_addr);

	vga_puts("main(): starting interrupts\n");
	sti();
	

	vga_puts("main(): reached end of execution, hanging the CPU");
	for(;;);
}
