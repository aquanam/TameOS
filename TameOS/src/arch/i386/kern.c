/* Main kernel */

#include <stdbool.h>
#include <stddef.h>

/* pragma */
#define PRAGMA(x) _Pragma (#x)

/* targeting wrong operating system? */
#if defined(__linux__)
PRAGMA(GCC error "cross-compiler is needed")
#endif

/* wrong arch? */
#if !defined(__i386__)
PRAGMA(GCC error "wrong arch")
#endif

#include "lib/c/int.h"
#include "lib/c/string.h"
#include "lib/panic.h"
#include "lib/cpu.h"
#include "lib/vga.h"
#include "lib/tty.h"

/* kernel main: invoked by boot.s */
void kernel_main(void)
{
    /* init terminal */
    init_terminal();

    /* main terminal printing */

    terminalws("Welcome to TameOS!\n");

    /* CPU info */

    const size_t CYAN_ENTRY   = vga_entry_color(CYAN,        BLACK);
    const size_t BLUE_ENTRY   = vga_entry_color(BLUE,        BLACK);
    const size_t LGREEN_ENTRY = vga_entry_color(LIGHT_GREEN, BLACK);

    terminal_setcolor(LGREEN_ENTRY);
    terminalws("\n## CPU info ##\n");

    /* brand name */

    char brandname[48];
    get_cpu_brand(brandname);

    terminal_setcolor(CYAN_ENTRY);
    terminalws("CPU brand name: ");

    terminal_setcolor(BLUE_ENTRY);
    terminalws(brandname);
    terminal_putchar('\n');

    /* model number */

    char modelnum[20];
    itoa(get_model(), modelnum, 10);
    modelnum[19] = '\0'; /* o7 */

    terminal_setcolor(CYAN_ENTRY);
    terminalws("CPU model number: ");

    terminal_setcolor(BLUE_ENTRY);
    terminalws(modelnum);
    terminal_putchar('\n');

    /* family number */

    char familynum[20];
    itoa(get_family(), familynum, 10);
    familynum[19] = '\0';  /* o7 */

    terminal_setcolor(CYAN_ENTRY);
    terminalws("CPU family number: ");

    terminal_setcolor(BLUE_ENTRY);
    terminalws(familynum);
    terminal_putchar('\n');

    /* vendor string */

    char *vendor = get_vendor_str();
    
    terminal_setcolor(CYAN_ENTRY);
    terminalws("CPU vendor string: ");

    terminal_setcolor(BLUE_ENTRY);
    terminalws(vendor);
    terminalws("\n\n");

    terminal_setcolor(vga_entry_color(LIGHT_GREY, BLACK));

    /* fun */

    terminalws("If you can see this then that means it works :-)\n");
    terminal_setcolor(vga_entry_color(LIGHT_RED, BLUE));

    /* VGA terminal test */
    
    // terminal_setcolor(vga_entry_color(LIGHT_BLUE, BLACK));
    // terminalws("\nTERMINAL TEST\n\n");
    
    // const char *letter = "a\n";
    // for (size_t i = 0; i < 30; i++)
    //     terminalws(letter);
}
