#include <stdio.h>
#include <stdlib.h>

#define TAB 8

int main(int argc, char *argv[])
{
  int c;
  int spaces;
  int line_position;

  line_position = 0;
  spaces = 0;
  while ((c = getchar()) != EOF)
  {
    line_position++;

    if (c == ' ')
    {
      spaces++;

      if (line_position % TAB == 0 && spaces > 0)
      {
        putchar('\t');
        spaces = 0;
      }
    }
    else
    {
      while (spaces)
      {
        putchar(' ');
        spaces--;
      }

      putchar(c);
    }

    if (c == '\n')
    {
      line_position = 0;
    }
  }
}

/**
 *
 * argc: number of arguments. argv[argc] == '\0
 * argv: [prog_title] 4 8 16
 *
 **/

int main2(int argc, char *argv[])
{
  int c;
  int spaces = 0;
  int line_position = 0;
  int i = 1;
  int current_tab_stop = atoi(*(argv + 1));

  while ((c = getchar()) != EOF)
  {
    line_position++;

    for (int i = argc - 1; i >= 1; i--)
    {
      if (line_position > atoi(*(argv + i)))
      {
        current_tab_stop = atoi(*(argv + i));
        break;
      }
    }

    if (c == ' ')
    {
      spaces++;

      if (line_position % current_tab_stop == 0 && spaces > 0)
      {
        putchar('\t');
        spaces = 0;
      }
    }
    else
    {
      while (spaces)
      {
        puchar(' ');
        spaces--;
      }

      putchar(c);
    }

    if (c == '\n')
    {
      line_position = 0;
    }
  }
}
