#include <stdio.h>

int invert(int x, int p, int n);

int main(void)
{
  int x = 85;
  int p = 3;
  int n = 2;

  printf("%i\n", invert(x, p, n));

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
