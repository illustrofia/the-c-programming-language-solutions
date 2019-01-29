// Needs comments

// Detab: Replaces sequences of blanks with tab stop

#include <stdio.h>

#define TAB 4

int main(void)
{
    int c;          // Stores input
    int blanks;     // Stores number of blanks

    blanks = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            blanks++;
            if (blanks == TAB)
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


// Write a version for this program using character arrays