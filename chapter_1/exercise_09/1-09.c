// Replaces each string of one or more blanks by a single blank

#include <stdio.h>

int main(void)
{
    int c, prev_c;

    c = getchar();
    while ((c = getchar()) != EOF)
    {
        // The character currently in c and the one in prev_c can't be both blanks
        if (!(c == ' ' && prev_c == ' '))
        {
            putchar(c);
        }
        prev_c = c;
    }
}

// Observations

// Although the condition inside the if structure
// may not be the most compact, it is more readable
// for most people.