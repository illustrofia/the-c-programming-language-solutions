#include <stdio.h>

#define IN 1
#define OUT 0

// Counts lines, words, and characters in input

main () {
    int c, state;

    state = OUT;
    while ((c = getchar()) != EOF) {
        if (c != ' ' && c != '\n' && c != '\t') {
            state = IN;
            putchar(c);
        }
        else if (state == IN) {
            state = OUT;
            putchar('\n');
        }
    }
}

// Observations

// To test the program, I would pass on
// extremely long words, tabs, extremely long
// groups of blanks and special characters, such as
// {}, /, ;, etc.