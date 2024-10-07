#if !defined(LIBC_STRING_H_TAME)
#define LIBC_STRING_H_TAME

#include <stddef.h>

/* Get the string length
 * @param str: the string value */
size_t strlen(const char *str);

/* Reverse a string
 * @param str: the string value */
void strrev(char *str);

/* Concatinates two strings
 * @param dest: destination (also string A)
 * @param str: a string value*/
char *strcat(char *dest, const char *str);

/* Copy an area of memory to another place
 * @param dest: destination
 * @param src: area of memory
 * @param n: number of iterations to copy
 * 
 * This function does not handle overlapping conditions,
 * unlike memmove. */
void *memcpy(void *dest, const void *src, size_t n);

/* Copy an area of memory to another place
 * @param dest: destination
 * @param src: area of memory
 * @param n: number of iterations to copy */
void *memmove(void *dest, const void *src, size_t n);

/* Converts an integer value to a null-terminated string
 * @param value: the integer value
 * @param dest: destination (stores string)
 * @param base: numerical base */
void itoa(int value, char *dest, int base);

#endif /* LIBC_STRING_H_TAME */