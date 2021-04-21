#include <stdio.h>
#include <string.h>

#define MAXLEN 100

void itoa_rec(int n, char s[]);
void reverse(char s[]);

int main(void)
{
  int n = 12345;
  char s[MAXLEN];

  itoa_rec(n, s);

  printf("%i = \"%s\"\n", n, s);

  return 0;
}

void itoa_rec(int n, char s[])
{
  if (n / 10)
  {
    itoa_rec(n / 10, s);
  }

  s[strlen(s)] = n % 10 + '0';

  s[strlen(s)] = '\0';

  return;
}
