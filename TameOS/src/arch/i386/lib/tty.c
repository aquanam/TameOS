#include "vga.h"
#include "c/int.h"
#include "c/string.h"

/* documentation for these functions should
 * be in tty.h */

size_t terminal_row;
size_t terminal_column;

uint8_t terminal_color;
uint8_t BGTERM_COLOR;

uint16_t *terminal_buffer;

void init_terminal(void)
{
    /* set up terminal config */
    terminal_row    = 0;
    terminal_column = 0;


    terminal_color  = vga_entry_color(LIGHT_GREY, BLACK);
    /* REMEMBER: This is the background color, and will not
                 be changed in terminal_setcolor (function below) */
    BGTERM_COLOR    = vga_entry_color(BLACK, BLACK);
    
    terminal_buffer = (uint16_t *) 0xB8000;

    /* make the effect of a background color */
    for (size_t y = 0; y < VGA_HEIGHT; y++) {
        for (size_t x = 0; x < VGA_WIDTH; x++) {
            const size_t index = y * VGA_WIDTH + x;
            terminal_buffer[index] = vga_entry(' ', BGTERM_COLOR);
        }
    }
}

void terminal_setcolor(uint8_t color)
{
    terminal_color = color;
}

void terminal_putentryat(char c, uint8_t color, size_t x, size_t y)
{
    const size_t index = y * VGA_WIDTH + x;
    terminal_buffer[index] = vga_entry(c, color);
}


void terminal_scroll(void)
{
    /* move every row one line up */
    memmove(terminal_buffer,
            terminal_buffer + VGA_WIDTH,
            VGA_WIDTH * (VGA_HEIGHT - 1) * sizeof(uint16_t));

    /* clear line at bottom */
    size_t index = (VGA_HEIGHT - 1) * VGA_WIDTH;

    for(size_t x = 0; x < VGA_WIDTH; x++)
        terminal_buffer[index + x] = vga_entry(' ', BGTERM_COLOR);
}

void terminal_putchar(char c)
{
    if (c == '\n') {
        terminal_column = 0;
        if (++terminal_row == VGA_HEIGHT) {
            terminal_scroll();
            terminal_row = VGA_HEIGHT - 1;
        }

        return;
    }
    
    /* put char entry */
    terminal_putentryat(c, terminal_color, terminal_column, terminal_row);

    if (++terminal_column == VGA_WIDTH) {
        terminal_column = 0;
        if (++terminal_row == VGA_HEIGHT) {
            terminal_scroll();
            terminal_row = VGA_HEIGHT - 1;
        }
    }
}   

void terminalw(const char *data, size_t size)
{
    for (size_t i = 0; i < size; i++)
        terminal_putchar(data[i]);
}

void terminalws(const char *data)
{
    terminalw(data, strlen(data));
}
