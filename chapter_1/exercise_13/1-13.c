// Prints a vertical histogram of the word lengths from input

#include <stdio.h>

#define IN 1
#define OUT 0

// Maximum word length
#define LIMIT 45

int main(void)
{
    int lengths[LIMIT]; // Stores lengths frequencies

    for (int i = 0; i < LIMIT; i++)
    {
        lengths[i] = 0;
    }

    int letters = 0; // Stores each word length
    int state = OUT; // Keeps track of whether we are inside or outside a word
    int c;           // Gets characters from input
    int max = 0;     // Stores the maximum word length frequency

    // Populates length frequencies array
    while ((c = getchar()) != EOF)
    {
        // If the input is a letter of the alphabet, we know we are inside a word
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        {
            state = IN;

            letters++;
        }
        else if (state == IN) // OBS: Only if we were inside a word do we execute this part
        {
            state = OUT;

            lengths[letters]++; // Increment the corresponding length frequency

            if (lengths[letters] > max)
            {
                max = lengths[letters];
            }

            letters = 0;
        }
    }

    // Histogram printing explained after end of main()
    printf("\nWord lengths histogram:\n\n");
    for (int i = max; i > 0; i--)
    {
        for (int j = 0; j < LIMIT; j++)
        {
            if (lengths[j])
            {
                if (lengths[j] >= i)
                {
                    printf("####");
                }
                else
                {
                    printf("    ");
                }

                printf(" ");
            }
        }

        printf("\n");
    }

    // Bottom row printing (word lengths)
    for (int i = 0; i < LIMIT; i++)
    {
        if (lengths[i])
        {
            if (i < 10)
            {
                printf(" 0%i  ", i);
            }
            else
            {
                printf(" %i  ", i);
            }
        }
    }

    printf("\n");
}

// The for loop starts with i representing
// the highest length frequency.
// Only the most frequent word lengths will
// print a symbol here. The others must print
// blank spaces to fill the space for the symbols
// to fit the corresponding word length.
// We only print word lengths that have appeard
// at least once.
