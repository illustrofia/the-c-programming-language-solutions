// Replaces strings of blanks by the minimum number
// of tabs and blanks to achieve the same spacing.

#include <stdio.h>
#include <stdlib.h>
#define TAB 4

int main(int argc, char *argv[])
{
  int c;
  int blanks = 0;
  int tab;

  tab = (argc > 1) ? atoi(argv[1]) : TAB;

  while ((c = getchar()) != EOF)
  {
    if (c == ' ')
    {
      blanks++;

      if (blanks == tab)
      {
        putchar('\t');

        blanks = 0;
      }
    }
    else
    {
      for (blanks; blanks > 0; blanks--)
      {
        putchar(' ');
      }

      putchar(c);
    }
  }

  return 0;
}
