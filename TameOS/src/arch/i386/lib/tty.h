#if !defined(LIB_TTY_H_TAME)
#define LIB_TTY_H_TAME

#include "c/int.h"

extern size_t terminal_row;
extern size_t terminal_column;

extern uint8_t terminal_color;
extern uint8_t BGTERM_COLOR;

extern uint16_t *terminal_buffer;

/* Initialize terminal */
void init_terminal(void);

/* Set terminal color
 * @param color: color entry */
void terminal_setcolor(uint8_t color);

/* Put entry at position
 * @param c: character
 * @param color: color entry
 * @param x: x position
 * @param y: y position */
void terminal_putentryat(char c, uint8_t color, size_t x, size_t y);

/* Scroll once */
void terminal_scroll(void);

/* Put character
 * @param c: character */
void terminal_putchar(char c);

/* Write data
 * @param data: a string value
 * @param size: the size of the string */
void terminalw(const char *data, size_t size);

/* Write string
 * @param data: a string value */
void terminalws(const char *data);

#endif  /* LIB_TTY_H_TAME */