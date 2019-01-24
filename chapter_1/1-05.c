// Prints a Fahrenheit-Celsius table
// for fahr = 300, 280,..., 0;
// floating-point version using for loop

#include <stdio.h>

int main(void)
{
    int fahr;

    // Prints a header before the table
    printf("Fahrenheit \t Celsius\n\n");

    for (fahr = 300; fahr >= 0; fahr -= 20)
    {
        printf("%3d \t\t %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
    }
}


// Observations

// In this case, the for loop is not as
// human-friendly as the while loop. However,
// it is much more compact, and the control
// statements are kept together in one place.
// If we'd want to make it more readable, we could
// declare the constants inside the header before
// the loop and calculate the celsius value using
// a separate variable before the printf call.