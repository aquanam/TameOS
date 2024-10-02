#include <cpuid.h>

#include "cpu.h"
#include "c/int.h"
#include "c/string.h"

/* documentations for these functions should
   be specified in string.h */

int get_model(void)
{
    xuint32_t eax, ebx, ecx, edx;
    __cpuid(1, eax, ebx, ecx, edx);

    int family = (eax >> 8) & 0xF;
    int model  = (eax >> 4) & 0xF;

    if (family == 0x6 || family == 0xF) {
        model += ((eax >> 16) & 0xF) << 4;
    }

    return model;
}

int get_family(void)
{
    xuint32_t eax, ebx, ecx, edx;
    __cpuid(1, eax, ebx, ecx, edx);

    int family = (eax >> 8) & 0xF;
    return family;
}

char *get_vendor_str(void)
{
    int eax = 0;
    int ebx = 0, ecx = 0, edx = 0;
    __cpuid(0, eax, ebx, ecx, edx);

    static char vendor[13];

    memcpy(&vendor[0], &ebx, 4);
    memcpy(&vendor[4], &edx, 4);
    memcpy(&vendor[8], &ecx, 4); 
    
    vendor[12] = '\0';  /* o7 */

    return vendor;
}

void get_cpu_brand(char *brand)
{
    xuint32_t eax, ebx, ecx, edx;

    /* zero out brand dest */
    for (int i = 0; i < 48; i++) {
        brand[i] = 0;
    }

    __cpuid(0x80000002, eax, ebx, ecx, edx);
    *((unsigned int *) brand)        = eax;
    *((unsigned int *) (brand + 4))  = ebx;
    *((unsigned int *) (brand + 8))  = ecx;
    *((unsigned int *) (brand + 12)) = edx;

    __cpuid(0x80000003, eax, ebx, ecx, edx);
    *((unsigned int *) (brand + 16)) = eax;
    *((unsigned int *) (brand + 20)) = ebx;
    *((unsigned int *) (brand + 24)) = ecx;
    *((unsigned int *) (brand + 28)) = edx;

    __cpuid(0x80000004, eax, ebx, ecx, edx);
    *((unsigned int *) (brand + 32)) = eax;
    *((unsigned int *) (brand + 36)) = ebx;
    *((unsigned int *) (brand + 40)) = ecx;

    *((unsigned int *) (brand + 44)) = edx;
    brand[47] = '\0';  /* o7 */
}

int check_ecx_feat(unsigned int cpuidfeat)
{
    xuint32_t __unused;
    
    /* this is so we don't get 'var may be uninitialized'
     * warnings */
    unsigned int ecx = 0;
    
    __get_cpuid(1, &__unused, &__unused, &ecx, &__unused);

    /* return boolean output */
    return (ecx & cpuidfeat) != 0;
}

int check_edx_feat(unsigned int cpuidfeat)
{
    xuint32_t __unused;
    
    /* same here */
    xuint32_t edx = 0;
    
    __get_cpuid(1, &__unused, &__unused, &__unused, &edx);

    /* same as this */
    return (edx & cpuidfeat) != 0;
}