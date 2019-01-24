#include <stdio.h>

// We use IN and OUT to check if we are inside/outside a word
#define IN 1
#define OUT 0
// LIMIT is the maximum word length
#define LIMIT 45

// Prints a vertical histogram of the word lengths in input
main () {
    int lengths[LIMIT];
    
    // Initialization of the word lengths array with 0
    for (int i = 0; i < LIMIT; i++) {
        lengths[i] = 0;
    }

    int letters = 0;    // used to count the letters inside a word
    int state = OUT;    // used to keep track of whether we are inside or outside a word
    int c;              // used to get characters from input
    int max = 0;        // used to keep track of the most frequent word length

    while ((c = getchar()) != EOF) {

        // If the imput is a letter of the alphabet, we know we are inside a word
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
            state = IN;
            letters++;

        }
        else if (state == IN) {
            state = OUT;

            // We increment the value corresponding the word length inside the array 
            lengths[letters]++;

            if (lengths[letters] > max) { 
                max = lengths[letters];
            }
            letters = 0;
        }
    }
    
    printf("\nHistogram of the word lengths:\n\n");

    // i corresponds to rows, while j to columns 
    for (int i = max; i >= 0; i--) {
        for (int j = 0; j < LIMIT; j++) {
            if (lengths[j]) {
                
                // Since there is no word of 0 length,
                // we want to print the corresponding 
                // word lengths on the bottom row
                if (i) {

                    // Check notes at end of main() for explanation
                    if (lengths[j] >= i) {
                        // symbol used for showing the word has reached that frequency
                        printf("###");
                    }
                    else {
                        // blank space instead of symbol
                        printf("   ");
                    }
                }
                else {

                    // printing of bottom row (word lengths)
                    if (j < 10) {
                        printf("00%i", j);
                    }
                    else {
                        printf("0%i", j);
                    }
                }
                printf(" ");
            }
        }
        printf("\n");
    }
}


// The for loop starts with i representing
// the maximum word length frequency. 
// Only the most frequent words will print
// a symbol here. The others must print
// blank spaces here, though, so they fill
// the space for the symbols to fit the
// corresponding word length. Basically, we
// are printing a table.


// Observations

// The most complicated part in this program
// was actually the printing of the histogram.
// Printing a table is not very easy as you need
// to format it in such a way that is pleasing
// to look at.