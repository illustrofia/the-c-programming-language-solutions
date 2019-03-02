// Determines ranges of char, short, int, long, both signed and unsigned

#include <stdio.h>
#include <limits.h>

int main(void)
{
    // char
    printf("Range of signed char is between %d and %d.\n", CHAR_MIN, CHAR_MAX);
    printf("Range of unsigned char is between 0 and %u.\n\n", UCHAR_MAX);

    // short
    printf("Range of signed short is between %d and %d.\n", SHRT_MIN, SHRT_MAX);
    printf("Range of unsigned short is between 0 and %u.\n\n", USHRT_MAX);

    // int
    printf("Range of signed int is between %d and %d.\n", INT_MIN, INT_MAX);
    printf("Range of unsigned int is between 0 and %u.\n\n", UINT_MAX);

    // long
    printf("Range of unsigned long is between 0 and %lu.\n", ULONG_MAX);
    printf("Range of signed long is between %ld and %ld.\n\n", LONG_MIN, LONG_MAX);

    // float
    printf("Range of signed float is between %e and %e.\n", __FLT_MIN__, __FLT_MAX__);
}