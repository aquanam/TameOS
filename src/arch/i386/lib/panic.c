#include "c/string.h"
#include "tty.h"

void kpanic(const char *data)
{
    terminalws(strcat("kernel panic: ", data));
    asm volatile("hlt");
}