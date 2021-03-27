// Replaces strings of blanks by the minimum number
// of tabs and blanks to achieve the same spacing.

#include <stdio.h>

#define TAB 8

int main(void)
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
