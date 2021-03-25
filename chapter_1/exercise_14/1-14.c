// Prints a vertical histogram representing the character frequency in input

#include <stdio.h>

#define LIMIT 255

int main(void)
{
    int chars[LIMIT];

    for (int i = 0; i <= LIMIT; i++)
    {
        chars[i] = 0;
    }

    int c;       // Gets characters from input
    int max = 0; // Stores maximum frequency

    while ((c = getchar()) != EOF)
    {
        chars[c]++;
        if (chars[c] > max)
        {
            max = chars[c];
        }
    }

    // Histogram printing explained after end of main()
    printf("\nHistogram of the characters:\n\n");
    for (int i = max; i > 0; i--)
    {
        for (int j = 0; j <= LIMIT; j++)
        {
            if (chars[j])
            {
                if (chars[j] >= i)
                {
                    printf(" ### ");
                }
                else
                {
                    printf("     ");
                }
            }
        }

        printf("\n");
    }

    // Prints bottom row of characters
    for (int i = 0; i <= LIMIT; i++)
    {
        if (chars[i])
        {
            if (i == '\n')
            {
                printf("  \\n ");
            }
            else if (i == '\t')
            {
                printf("  \\t ");
            }
            else
            {
                printf("  %c  ", i);
            }
        }
    }

    printf("\n");

    // Prints row of character frequencies
    for (int i = 0; i <= LIMIT; i++)
    {
        if (chars[i])
        {
            if (chars[i] < 10)
            {
                printf(" 00%i ", chars[i]);
            }
            else if (chars[i] < 100)
            {
                printf(" 0%i ", chars[i]);
            }
            else
            {
                printf(" %i ", chars[i]);
            }
        }
    }

    printf("\n");
}

// The for loop starts with i representing
// the maximum character frequency.
// Only the most frequent characters will
// print a symbol here. The others must print
// blank spaces here, though, so they fill
// the space for the symbols to fit the
// corresponding character. We only print
// characters that have appeard at least
// once
