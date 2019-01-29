// Detab: Replaces tabs with blank spaces equivalent

#include <stdio.h>

#define TAB 4

int main(void)
{
    int c;

    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            for (int i = 0; i < TAB; i++)
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

// Observations

// I used a symbolic parameter for the
// tab equivalent, since it does not
// require any memory to store.

// Also, I should also write a version
// for this program using character arrays