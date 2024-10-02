#if !defined(LIB_PANIC_H_TAME)
#define LIB_PANIC_H_TAME

/* documentation of functions should be in
 * panic.h */

/* Invoke a kernel panic
 * @param data: a string value */
__attribute__((__noreturn__))
void kpanic(const char *data);

#endif  /* LIB_PANIC_H_TAME */