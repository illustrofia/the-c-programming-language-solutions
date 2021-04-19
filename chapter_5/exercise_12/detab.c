// Replaces tabs with blank spaces equivalent

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_TAB_SIZE 8
#define DEFAULT_LIMITED_TAB_SIZE 4
#define DEFAULT_COLUMN_LIMIT 50

int main(int argc, char *argv[])
{
  int c, i;

  int tab_size;
  int full_tab_size = DEFAULT_TAB_SIZE;
  int limited_tab_size = DEFAULT_LIMITED_TAB_SIZE;
  int column_limit = DEFAULT_COLUMN_LIMIT;

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

    if (c == '\t')
    {
      tab_size = (column_counter > column_limit) ? limited_tab_size : full_tab_size;

      for (i = 0; i < tab_size; i++)
      {
        putchar(' ');
      }
    }
    else
    {
      putchar(c);
    }
  }

  return 0;
}
