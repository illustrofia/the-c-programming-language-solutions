#include <stdio.h>

//  prints a Fhrenheit-Celsius table
//  for fahr = 0, 20,..., 300
//  floating point version

main () {
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;      //  lower temperature limit
    upper = 300;    //  upper temperature limit
    step = 20;      //  step size

    fahr = lower;

    printf("Fahrenheit \t Celsius\n\n");    // prints a header before the table

    while (fahr <= upper) {
        celsius = (5.0 / 9.0) * (fahr - 32);
        printf("%3.0f \t\t %6.1f\n", fahr, celsius);
        fahr += step;
    }
}


//  Observations

//      If an arithetic operator has integer operands,
//      an integer operation is performed. However,
//      if an arithetic operator has one floating-point
//      operand and one integer operand, the integer
//      will be converted to floating point before the
//      operation is done.