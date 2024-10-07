#if !defined(LIBC_INT_H_TAME)
#define LIBC_INT_H_TAME

/* type declaration for integers */

/* size_t is a type to hold any array index */

typedef typeof(sizeof(0)) size_t;         /* size_t */

/* integer bit width types */

/* signed */

typedef signed char  int8_t;              /* int8_t */
typedef signed short int16_t;             /* int16_t */
typedef signed long      int32_t;     /* int32_t */
typedef signed long long int64_t;     /* int64_t */
/* provide i386 with x86_64 32_t and 64_t bit width */
typedef signed int  xint32_t;         /* xint32_t */
typedef signed long xint64_t;         /* xint64_t */

typedef unsigned char  uint8_t;           /* uint8_t */
typedef unsigned short uint16_t;          /* uint16_t */
typedef unsigned long      uint32_t;  /* uint32_t */
typedef unsigned long long uint64_t;  /* uint64_t */
/* same here, but unsigned */
typedef unsigned int  xuint32_t;      /* xuint32_t */
typedef unsigned long xuint64_t;      /* xuint32_t */

#endif /* LIBC_INT_H_TAME */