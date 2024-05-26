#include <stdio.h>
#include <math.h>

void printbin(unsigned int x);
int invert(int x, int p, int n);

int main(void)
{
  int x = 0b01010101;
  int p = 3;
  int n = 4;

  printbin(x);
  printbin(invert(x, p, n));

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

// Returns x with the n bits that begin at position p inverted
int invert(int x, int p, int n)
{
  // Example with p = 3, n = 2
  // Creates xxxx 00xx
  int scooped_x = ~(~(~0 << n) << (p + 1 - n)) & x;

  // Creates 0000 ii00
  int inverted_x_bits = (~(~0 << n) << (p + 1 - n)) & ~x;

  // xxxx 00xx | 0000 ii00 == xxxx iixx
  return scooped_x | inverted_x_bits;
}
