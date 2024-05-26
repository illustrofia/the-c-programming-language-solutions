#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 100

void itob(int n, char s[], int b);
char itoc(int a);
void reverse(char s[]);

int main(void)
{
  char s[MAXLEN];
  int n = 56;
  int b = 16;

  itob(n, s, b);

  printf("%s\n", s);
}

void itob(int n, char s[], int b)
{
  int i = 0, sign = n;

  do
  {
    s[i++] = itoc(abs(n) % b);
  } while (n /= b);

  if (sign < 0)
  {
    s[i++] = '-';
  }

  s[i] = '\0';

  reverse(s);
}

char itoc(int a)
{
  if (a <= 9)
  {
    return a + '0';
  }

  return a + 'a' - 10;
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
