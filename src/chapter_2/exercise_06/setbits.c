#include <stdio.h>
#include <math.h>

void printbin(unsigned int x);
int setbits(int x, int p, int n, int y);

int main(void)
{
  int x = 0b01010101;
  int y = 0b1010;

  int p = 3;
  int n = 2;

  printbin(x);
  printbin(setbits(x, p, n, y));

  return 0;
}

void printbin(unsigned int x)
{
  int n = sizeof(unsigned int);

  printf("0b");

  int i;
  for (i = n * 8 - 1; i >= 0; i--)
  {
    (x & (unsigned int)pow(2, i)) ? putchar('1') : putchar('0');
  }

  putchar('\n');
}

// Returns x with the n bits that begin at
// position p set to the rightmost n bits of y
int setbits(int x, int p, int n, int y)
{

  // Example with p = 3, n = 2
  // Creates: xxxx 00xx
  int scooped_x = ~(~(~0 << n) << (p + 1 - n)) & x;

  // Creates 0000 yy00
  int y_bits = (~(~0 << n) & y) << (p + 1 - n);

  // xxxx 00xx | 0000 yy00 == xxxx yyxx
  return scooped_x | y_bits;
}
