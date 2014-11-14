#include "common.h"
#include "paging.h"
#include "virtix_proc.h"

#define HANG()	cli(); \
		hlt();

virtix_proc_t* flat_load_bin(void* addr){
	cli();
	virtix_proc_t* proc = mk_empty_proc();
	proc->registers.useresp = 100;
	proc->registers.eip = 0;
	
	proc->name = "FLAT_BIN";

	unsigned int mem = (unsigned int) kmalloc_a(PAGE_S);
	vga_puts("flat_load_bin(): move ");
	vga_puts_hex(addr);
	vga_puts(" to ");
	vga_puts_hex(mem);
	vga_puts("\n");

	mmap_page(proc->cr3, 0, mem);
	memcpy(mem, addr, 512);

	sti();
	return proc;
}
