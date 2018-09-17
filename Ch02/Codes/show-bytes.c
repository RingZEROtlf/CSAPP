/*
 * show-bytes.c - output the byte representation of given object
 */

#include <stdio.h>

void show_bytes(unsigned char *start, size_t len)
{
    for (size_t i = 0; i < len; i++) printf(" %.2x", start[i]);
    printf("\n");
}

#define SHOW_BYTES(arg, type)   show_bytes((unsigned char *) &(arg), sizeof(type))

void test_show_bytes(int val)
{
    int ival = val;
    float fval = (float) ival;
    int *pval = &ival;
    SHOW_BYTES(ival, int);
    SHOW_BYTES(fval, float);
    SHOW_BYTES(pval, int*);
}

int main()
{
    test_show_bytes(12345);
    return 0;
}

