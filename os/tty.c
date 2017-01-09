#include <stddef.h>
#include <stdint.h>
#include "lib.h"

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;
static size_t tty_row;
static size_t tty_col;
static uint8_t tty_color;
static uint16_t *tty_buf;

enum vga_color {
	BLACK,
	BLUE,
	GREEN,
	CYAN,
	RED,
	MAGENTA,
	BROWN,
	LGREY,
	DGREY,
	LBLUE,
	LGREEN,
	LCYAN,
	LRED,
	LMAGENTA,
	LBROWN,
	WHITE,
};

uint8_t
tty_packcolors(enum vga_color fg, enum vga_color bg)
{
	return fg | bg << 4;
}

uint16_t
tty_packentry(char c, uint8_t color)
{
	uint16_t c16 = c;
	uint16_t color16 = color;
	return c16 | color16 << 8;
}

void
tty_init(void)
{
	size_t x, y;
	
	tty_row = 0;
	tty_col = 0;
	tty_color = tty_packcolors(LGREY, BLACK);
	tty_buf = (uint16_t *)0xB8000;
	
	for (y = 0; y < VGA_HEIGHT; y++) {
		for (x = 0; x < VGA_WIDTH; x++) {
			const size_t i = y*VGA_WIDTH + x;
			tty_buf[i] = tty_packentry(' ', tty_color);
		}
	}
}

void
tty_putentry(char c, uint8_t color, size_t x, size_t y)
{
	const size_t i = y*VGA_WIDTH + x;
	tty_buf[i] = tty_packentry(c, color);
}

void
tty_clear(uint16_t *buf, size_t nbytes)
{
	size_t i;
	for (i = 0; i < nbytes; i++) {
		buf[i] = tty_packentry(' ', tty_color);
	}
}

void
tty_scroll(size_t nlines)
{
	size_t i, nbytes = (VGA_HEIGHT-nlines) * VGA_WIDTH;
	for (i = 0; i < nbytes; i++) {
		tty_buf[i] = tty_buf[i+VGA_WIDTH];
	}
	tty_clear(tty_buf+nbytes, VGA_WIDTH);
}

size_t
tty_rowinc(void)
{
	if (++tty_row == VGA_HEIGHT) {
		tty_scroll(1);
		tty_row = tty_row-1;
	}
	return tty_row;
}

void
tty_putchar(char c)
{
	if (c == '\n') {
		tty_rowinc();
		tty_col = 0;
		return;
	}
	tty_putentry(c, tty_color, tty_col, tty_row);
	if (++tty_col == VGA_WIDTH) {
		tty_col = 0;
		tty_rowinc();
	}
}

void
tty_putstr(const char* str)
{
	size_t len = strlen(str), i;
	for (i = 0; i < len; i++) {
		tty_putchar(str[i]);
	}
}
