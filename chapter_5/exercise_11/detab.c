// Replaces tabs with blank spaces equivalent

#include <stdio.h>
#include <stdlib.h>

#define TAB 4

int main(int argc, char *argv[])
{
    int c, tab;

    tab = (argc > 1) ? tab = atoi(argv[1]) : TAB;

    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            for (int i = 0; i < tab; i++)
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