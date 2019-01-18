#include <stdio.h>

//  prints the value of the expression getchar() != EOF

main () {
    printf("The expression's value is equal to %d", getchar() != EOF);
}

//  Observations

//      The expression's value is 1 when the
//      character is not the EOF input signal. The
//      EOF signal is represented by "Ctrl+D" on
//      Linux machines, and by "Ctrl+Z" on Windows
//      machines.