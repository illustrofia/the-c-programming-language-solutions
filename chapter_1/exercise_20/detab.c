// Replaces tabs with blank spaces equivalent

#include <stdio.h>

#define TAB_LENGTH 8

int main(void)
{
    int c;

    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            for (int i = 0; i < TAB_LENGTH; i++)
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
