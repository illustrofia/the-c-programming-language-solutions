
#include <stdio.h>

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c\n"
#define BYTE_TO_BINARY(byte)   \
  (byte & 128 ? '1' : '0'),    \
      (byte & 64 ? '1' : '0'), \
      (byte & 32 ? '1' : '0'), \
      (byte & 16 ? '1' : '0'), \
      (byte & 8 ? '1' : '0'),  \
      (byte & 4 ? '1' : '0'),  \
      (byte & 2 ? '1' : '0'),  \
      (byte & 1 ? '1' : '0')

int rightrot(int x, int n);
int intlength();

int main(void)
{
  int x = 0b01010101;

  printf(BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(x));
  printf(BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(rightrot(x, 3)));

  return 0;
}

// Returns value of integer x rotated to the right by n bit positions
int rightrot(int x, int n)
{
  int mask_1 = (~(~0 << n) & x) << (sizeof(x) * 8 - 1 - n);
  int mask_2 = (~0 & x) >> n;

  return mask_1 | mask_2;
}
