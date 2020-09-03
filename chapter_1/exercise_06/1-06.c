// Prints the value of the expression getchar() != EOF

#include <stdio.h>

int main(void)
{
    printf("The expression's value is equal to %d.\n", getchar() != EOF);
}

// Observations

// The expression's value is 1 when the
// character is not the EOF input signal. The
// EOF signal is represented by "Ctrl+D" on
// Linux machines, and by "Ctrl+Z" on Windows
// machines.
