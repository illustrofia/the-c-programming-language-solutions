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

int invert(int x, int p, int n);

int main(void)
{
  int x = 0b01010101;
  int p = 3;
  int n = 2;

  printf(BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(x));
  printf(BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(invert(x, p, n)));

  return 0;
}

// Returns x with the n bits that begin at position p inverted
int invert(int x, int p, int n)
{
  // Example with p = 3, n = 2
  // Creates xxxx 00xx
  int scooped_x = ~(~(~0 << n) << p + 1 - n) & x;

  // Creates 0000 ii00
  int inverted_x_bits = (~(~0 << n) << p + 1 - n) & ~x;

  // xxxx 00xx | 0000 ii00 == xxxx iixx
  return scooped_x | inverted_x_bits;
}
