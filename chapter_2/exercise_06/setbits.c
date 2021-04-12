#include <stdio.h>

int setbits(int x, int p, int n, int y);

int main(void)
{
  int x = 85;
  int y = 12;
  int p = 3;
  int n = 2;

  printf("%i\n", setbits(x, p, n, y));

  return 0;
}

// Returns x with the n bits that begin at
// position p set to the rightmost n bits of y
int setbits(int x, int p, int n, int y)
{

  // Example with p = 3, n = 2
  // Creates: xxxx 00xx
  int scooped_x = ~(~(~0 << n) << p + 1 - n) & x;

  // Creates 0000 yy00
  int y_bits = (~(~0 << n) & y) << (p + 1 - n);

  // xxxx 00xx | 0000 yy00 == xxxx yyxx
  return scooped_x | y_bits;
}
