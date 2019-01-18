#include <stdio.h>

//  prints the number of blanks,
//  tabs and newlines in input

main () {
    int c;
    int blanks, tabs, newlines;

    blanks = 0;
    tabs = 0;
    newlines = 0;

//  counts the blanks, tabs and newlines
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            blanks++;
        } else if (c == '\t') {
            tabs++;
        } else if (c == '\n') {
            newlines++;
        }
    }

    printf("There are %d blanks, %d tabs, and %d newlines.\n", blanks, tabs, newlines);
}

//  Observations

//      When writing code in C, the programmer
//      must be careful when comparing values,
//      to use the double equals sign. It is also
//      interestig that, when declaring a variable,
//      if we do not assign it a specific value,
//      its value will be the default (automatic)
//      one. We must also be careful to be specific
//      when using functions, to provide all of the
//      arguments, or the output will not be the
//      correct one.