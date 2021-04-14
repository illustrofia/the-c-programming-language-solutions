#include <stdio.h>

#define MAXLEN 100

void itoa(int n, char s[]);

int main(void)
{
  char s[MAXLEN];
  int n = -2147483648; // largest negative number

  itoa(n, s);

  printf("%s\n", s);
}

void itoa(int n, char s[])
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
    } while ((n /= 10) != 0);
  }

  if (sign < 0)
  {
    s[i++] = '-';
  }

  s[i--] = '\0';

  int aux;
  for (int j = 0; j < i; i--, j++)
  {
    aux = s[i];
    s[i] = s[j];
    s[j] = aux;
  }
}

/**
 * Note:
 * In a two's complement number representation, the negative numbers
 * are represented this way: first bit represents the sign. If it is
 * 1, it means the number is negative. All of the following bits are
 * actually positive values added to the negative number.
 *
 * Example:
 * 1000 0000 represents -1111 1111.
 * 1000 0001 represents -1111 1111 + 0000 0001 = -1111 1110
 *
 * So if we multiply 1000...0000 (the largest negative number) with -1,
 * the value should be 1111...1111, so the sign bit is overflown and
 * the number becomes -1.
**/
