// Counts lines, words, and characters in input

#include <stdio.h>

#define IN 1
#define OUT 0

int main(void)
{
    int c;           // Character input variable
    int nl = 1;      // Line counter; initialized 1, because input is at least one line
    int nw = 0;      // Word counter
    int nc = 0;      // Character counter
    int state = OUT; // Stores whether INside or OUTside a word; initialized OUTside of word

    while ((c = getchar()) != EOF)
    {
        nc++;

        if (c == '\n')
        {
            nl++;
        }

        if (c == ' ' || c == '\n' || c == '\t')
        {
            state = OUT;
        }
        else if (state == OUT)
        {
            state = IN;
            nw++;
        }
    }

    printf("\n%d lines, %d words, %d characters\n", nl, nw, nc);
}

// Observations

// Series of special characters, such as commas, points,
// colons, etc., might be considered words.
