#include <stdio.h>
#include <math.h>

void printbin(unsigned int x);
int bitcount(unsigned int x);

int main(void)
{
  unsigned int x = 0b11011101;

  printbin(x);
  printf("x has %d bits of 1\n", bitcount(x));

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

int bitcount(unsigned x)
{
  int b = 0;

  while (x > 0)
  {
    x &= (x - 1);
    b++;
  }

  return b;
}

/**
 * Let's extract 1 from x:
 * 1101 1101 - 1 =
 * 1101 1100 - 1 =
 * 1101 1011 - 1 =
 * 1101 1010
 *
 * The rightmost 1-bit is switched to 0 each time.
 * If we compare the two values, the result is the
 * deletion of the rightmost 1-bit.
 *
 * 1101 1101 &
 * 1101 1100 =
 * 1101 1100
 *
 * So each time we do x &= (x - 1), we delete the rightmost 1-bit
**/

/**
 * 1011 0111 &
 * 1011 0110
 * 1011 0110 &
 * 1011 0101
 * 1011 0100 &
 * 1011 0011
 * 1011 0000
 **/
