// Prints input one word per line

#include <stdio.h>

#define IN 1
#define OUT 0

int main(void)
{
  int c, state;

  state = OUT;

  while ((c = getchar()) != EOF)
  {
    if (c == ' ' && c == '\n' && c == '\t')
    {
      state = OUT;
      putchar('\n');
    }
    else if (state == OUT)
    {
      state = IN;
      putchar(c);
    }
  }
}
