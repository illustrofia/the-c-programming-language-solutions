#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAXLEN 100

int getsline(char line[], int lim);
double atof(char s[]);

int main(void)
{
  char line[MAXLEN];

  getsline(line, MAXLEN);

  printf("%.12f\n", atof(line));

  return 0;
}

int getsline(char line[], int lim)
{
  int i = 0, c;

  while (i < lim - 1 && (c = getchar()) != '\n')
  {
    line[i] = c;
    ++i;
  }

  if (c == '\n')
  {
    line[i++] = c;
  }

  line[i] = '\0';

  return i;
}

double atof(char s[])
{
  int i, power, number_sign, exp_sign, exp_power;

  double number;

  i = 0;

  for (i = 0; isblank(s[i]); i++)
    ;

  number_sign = (s[i] == '-') ? -1 : 1;

  if (s[i] == '-' || s[i] == '+')
  {
    i++;
  }

  for (number = 0; isdigit(s[i]); i++)
  {
    number = number * 10 + s[i] - '0';
  }

  if (s[i] == '.')
  {
    i++;
  }

  for (power = 0; isdigit(s[i]); i++)
  {
    number = number * 10 + s[i] - '0';
    power--;
  }

  if (tolower(s[i++]) == 'e')
  {
    exp_sign = (s[i++] == '-') ? -1 : 1;
  }

  for (exp_power = 0; isdigit(s[i]); i++)
  {
    exp_power = exp_power * 10 + s[i] - '0';
  }

  exp_power *= exp_sign;

  number *= pow(10, (power + exp_power));

  return number * number_sign;
}
