#include <stddef.h>

#include "string.h"

/* documentations for these functions should
   be specified in string.h */

void strrev(char *str)
{
    /* first and last pointer */
    int pf = 0;
    int pl = strlen(str) - 1;

    char tempc;

    while (pf < pl) {
        tempc = str[pf];
        str[pf] = str[pl];
        str[pl] = tempc;

        pf++;
        pl--;
    }
}

size_t strlen(const char *str)
{
    size_t len = 0;  /* current length */
    while (str[len])
        len++;

    return len;
}

char *strcat(char *dest, const char *str)
{
    char *tempd = dest;

    while (*dest)
        dest++;

    while ((*dest++ = *str++) != '\0')
        /* operation already done */;

    return tempd;
}

void *memcpy(void *dest, const void *src, size_t n)
{
    unsigned char *udest = (unsigned char *) dest;
    unsigned char *usrc  = (unsigned char *) src;

    if (udest < usrc) {
        while (n--)
            *udest++ = *usrc++;
    }

    return dest;
}

void *memmove(void *dest, const void *src, size_t n)
{
    unsigned char *udest = (unsigned char *) dest;
    unsigned char *usrc  = (unsigned char *) src;

    if (udest < usrc) {
        while (n--)
            *udest++ = *usrc++;
    /* overlapping condition */
    } else if (udest > usrc) {
        udest += n;
        usrc  += n;

        /* it is important to work backwards otherwize we
           might overwrite what is in udest */
        while (n--)
            *--udest = *--usrc;
    }

    return udest; 
}

void itoa(int value, char *dest, int base)
{
    /* is the base valid? */
    if (base < 2 || base > 36) {
        *dest = '\0';
        return;
    }

    char *base_index = "0123456789abcdefghijklmnopqrstuvwxyz";
    
    char *ptra = dest;
    int sign = value < 0;

    if (value == 0)
        *ptra++ = '0';
    else {
        unsigned int uval = (unsigned int) (sign ? -value : value);

        while (uval) {
            *ptra++ = base_index[uval % base];
            uval /= base;
        }

        /* negative sign for base 10 case */
        if (sign && base == 10) {
            *ptra++ = '-';
        }
    }

    *ptra = 0;

    char *ptrb = dest;
    char tempc;

    ptra--;
    while (ptrb < ptra) {
        tempc = *ptra;
        *ptra-- = *ptrb;
        *ptrb++ = tempc;
    }
}
