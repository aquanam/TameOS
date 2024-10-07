#if !defined(LIB_VGA_H_TAME)
#define LIB_VGA_H_TAME

#include "c/int.h"

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;

/* color constants */
enum vga_color {
	BLACK = 0,
	BLUE = 1,
	GREEN = 2,
	CYAN = 3,
	RED = 4,
	MAGENTA = 5,
	BROWN = 6,
	LIGHT_GREY = 7,
	DARK_GREY = 8,
	LIGHT_BLUE = 9,
	LIGHT_GREEN = 10,
	LIGHT_CYAN = 11,
	LIGHT_RED = 12,
	LIGHT_MAGENTA = 13,
	LIGHT_BROWN = 14,
	WHITE = 15
};

/* Create a VGA entry by color
 * @param fg: foreground color
 * @param bg: background color */
uint8_t vga_entry_color(enum vga_color fg, enum vga_color bg);

/* Create a VGA entry
 * @param uc: character
 * @param color: color entry*/
uint16_t vga_entry(unsigned char uc, uint8_t color);

#endif /* LIB_VGA_H_TAME */