#include <stdio.h>
#include <math.h>

void printbin(unsigned int x);
unsigned int rightrot(int x, int n);

int main(void)
{
  unsigned int x = 0b11011101;

  printbin(x);
  printbin(rightrot(x, 3));

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

// Returns value of integer x rotated to the right by n bit positions
unsigned int rightrot(int x, int n)
{
  // Moves the n rightmost bits of x to the beginning
  unsigned int mask_1 = (~(~0 << n) & x) << (sizeof(x) * 8 - n);

  // Copies x without the n rightmost bits
  unsigned int mask_2 = (~0 & x) >> n;

  // Joins the two masks
  return mask_1 | mask_2;
}
