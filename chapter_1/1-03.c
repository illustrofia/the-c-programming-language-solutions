// Prints a Fahrenheit-Celsius table
// for fahr = 0, 20,..., 300;
// floating point version

#include <stdio.h>

int main(void)
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;      // lower temperature limit
    upper = 300;    // upper temperature limit
    step = 20;      // step size

    fahr = lower;
    
    // Prints a header before the table
    printf("Fahrenheit \t Celsius\n\n");

    while (fahr <= upper)
    {
        celsius = (5.0 / 9.0) * (fahr - 32);
        printf("%3.0f \t\t %6.1f\n", fahr, celsius);
        fahr += step;
    }
}


// Observations

// If an arithetic operator has integer operands,
// an integer operation is performed. However,
// if an arithetic operator has one floating-point
// operand and one integer operand, the integer
// will be converted to floating point before the
// operation is done.