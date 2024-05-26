// Prints a Fahrenheit-Celsius table
// for fahr = 0, 20,..., 300;
// using functions

#include <stdio.h>

float fahr_to_celsius(float fahr);

int main(void)
{
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;   // lower temperature limit
  upper = 300; // upper temperature limit
  step = 20;   // step size

  fahr = lower;

  printf("Fahrenheit \t Celsius\n");
  while (fahr <= upper)
  {
    printf("%3.0f \t\t %6.1f\n", fahr, fahr_to_celsius(fahr));
    fahr += step;
  }

  return 0;
}

// Returns celsius equivalent of fahr
float fahr_to_celsius(float fahr)
{
  return (5.0 / 9.0) * (fahr - 32);
}
