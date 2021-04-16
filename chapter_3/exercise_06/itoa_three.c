#include <stdio.h>
#include <string.h>

#define MAXLEN 100

void itoa(int n, char s[], int minimum_field_width);
void reverse(char s[]);

int main(void)
{
  char s[MAXLEN];
  int n = -214;

  itoa(n, s, 6);

  printf("%s\n", s);
}

void itoa(int n, char s[], int minimum_field_width)
{
  int i, sign;

  i = 0;
  sign = n;

  if (n < 0)
  {
    do
    {
      s[i++] = -(n % 10) + '0';
    } while ((n /= 10) != 0);
  }
  else
  {
    do
    {
      s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
  }

  if (sign < 0)
  {
    s[i++] = '-';
  }

  while (i < minimum_field_width)
  {
    s[i++] = ' ';
  }

  s[i] = '\0';

  reverse(s);
}

void reverse(char s[])
{
  int i, j, aux;

  for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
  {
    aux = s[i];
    s[i] = s[j];
    s[j] = aux;
  }
}
