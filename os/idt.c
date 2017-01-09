#include <stdint.h>
#include "lib.h"

struct idt_entry
{
    uint16_t base_lo; /* low bits of the offset */
    uint16_t sel;
    uint8_t always0;
    uint8_t flags;
    uint16_t base_hi; /* high bits of the offset */
} __attribute__((packed));

struct idt_entry idt[256];
struct idt_ptr idtp;

struct idt_ptr
{
    uint16_t limit;
    uint32_t base;
} __attribute__((packed));

void idt_set_gate(unsigned char num, unsigned long base, unsigned short sel, unsigned char flags)
{
	idt[num].base_lo = (base & 0xFFFF);
	idt[num].sel = sel;
	idt[num].always0 = 0;
	idt[num].flags = flags;
	idt[num].base_hi = (base>>16) & 0xFFFF;
}

extern void idt_load();

void idt_install()
{
	idtp.limit = (sizeof (struct idt_entry) * 256) - 1;
	idtp.base = (uint32_t)&idt;

    /* Clear out the entire IDT, initializing it to zeros */
	memset(&idt, 0, sizeof(struct idt_entry) * 256);

    /* Add any new ISRs to the IDT here using idt_set_gate */

    /* Points the processor's internal register to the new IDT 
	idt_load();*/
}
