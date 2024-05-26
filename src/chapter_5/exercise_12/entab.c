// Replaces strings of blanks by the minimum number
// of tabs and blanks to achieve the same spacing.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_TAB_SIZE 8
#define DEFAULT_LIMITED_TAB_SIZE 4
#define DEFAULT_COLUMN_LIMIT 50

int main(int argc, char *argv[])
{
  int c, i;

  int full_tab_size = DEFAULT_TAB_SIZE;
  int limited_tab_size = DEFAULT_LIMITED_TAB_SIZE;
  int column_limit = DEFAULT_COLUMN_LIMIT;

  int blank_counter = 0;
  int column_counter = (-1);

  // Gets arguments from argv, if any
  for (i = 1; i < argc; ++i)
  {
    if (strcmp(argv[i], "0") >= 0 && strcmp(argv[i], "9") <= 0)
    {
      full_tab_size = atoi(argv[i]);
    }
    if (argv[i][0] == '-')
    {
      column_limit = (-1) * atoi(argv[i]);
    }
    else if (argv[i][0] == '+')
    {
      limited_tab_size = atoi(argv[i]);
    }
  }

  while ((c = getchar()) != EOF)
  {
    column_counter = (c == '\n') ? (-1) : ++column_counter;

    if (c == ' ')
    {
      blank_counter++;

      if (column_counter >= column_limit && blank_counter == limited_tab_size)
      {
        putchar('\t');

        blank_counter = 0;
      }
      else if (column_counter < column_limit && blank_counter == full_tab_size)
      {
        putchar('\t');

        blank_counter = 0;
      }
    }
    else
    {
      for (blank_counter; blank_counter > 0; --blank_counter)
      {
        putchar(' ');
      }

      putchar(c);
    }
  }

  return 0;
}
