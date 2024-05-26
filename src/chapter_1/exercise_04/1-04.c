// Prints a Celsius-Fahrenheit table
// for celsius = 0, 20,..., 300;
// floating point version

#include <stdio.h>

int main(void)
{
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  celsius = lower;

  // Prints header before table
  printf("Celsius \t Fahrenheit\n\n");

  while (celsius <= upper)
  {
    fahr = (9.0 / 5.0 * celsius) + 32;
    printf("%3.0f \t\t %6.0f\n", celsius, fahr);
    celsius += step;
  }
}

// Observations

// If an arithmetic operator has integer operands,
// an integer operation is performed. However,
// if an arithetic operator has one floating-point
// operand and one integer operand, the integer
// will be converted to floating point before the
// operation is done.
