// Determines ranges of char, short, int, long, both signed and unsigned

#include <stdio.h>
#include <limits.h>

int main(void)
{
  // char
  printf("Range of signed char: %d ... %d.\n", CHAR_MIN, CHAR_MAX);
  printf("Range of unsigned char: 0 ... %u.\n\n", UCHAR_MAX);

  // short
  printf("Range of signed short: %d ... %d.\n", SHRT_MIN, SHRT_MAX);
  printf("Range of unsigned short: 0 ... %u.\n\n", USHRT_MAX);

  // int
  printf("Range of signed int: %d ... %d.\n", INT_MIN, INT_MAX);
  printf("Range of unsigned int: 0 ... %u.\n\n", UINT_MAX);

  // long
  printf("Range of unsigned long: 0 ... %lu.\n", ULONG_MAX);
  printf("Range of signed long: %ld ... %ld.\n\n", LONG_MIN, LONG_MAX);

  // float
  printf("Range of signed float: %e ... %e.\n", __FLT_MIN__, __FLT_MAX__);
}
