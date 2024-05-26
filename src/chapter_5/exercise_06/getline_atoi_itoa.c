#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLEN 100

int getsline(char *s, int lim);
int atoi_ptr(char *s);
void itoa_ptr(int n, char *s);
void reverse(char *s);

int main(void)
{
  char s[MAXLEN];
  int n;

  // Testing getsline() and reverse()
  printf("String to reverse: ");
  getsline(s, MAXLEN);

  reverse(s);

  printf("Result: %s\n\n", s);

  // Testing atoi()
  printf("String to convert into integer: ");
  getsline(s, MAXLEN);

  n = atoi_ptr(s);

  printf("String \"%s\" into integer: %i\n\n", s, n);

  itoa_ptr(n, s);

  printf("Integer %i into string: \"%s\"\n", n, s);

  return 1;
}

int getsline(char *s, int lim)
{
  int length = 0;

  while ((*s = getchar()) != EOF && *s != '\n' && lim--)
  {
    s++;
    length++;
  }

  *s = '\0';

  return length;
}

// atoi: converts string of characters into integer
int atoi_ptr(char *s)
{
  int n, sign;

  for (; isspace(*s); s++)
    ;

  sign = (*s == '-') ? -1 : 1;

  if (*s == '-' || *s == '+')
  {
    s++;
  }

  for (n = 0; isdigit(*s); s++)
  {
    n = n * 10 + (*s - '0');
  }

  return n * sign;
}

// itoa: converts integer into string of characters
void itoa_ptr(int n, char *s)
{
  char *s_start = s;

  int sign = (n < 0) ? -1 : 1;

  while (n)
  {
    *s++ = abs(n) % 10 + '0';
    n /= 10;
  }

  if (sign < 0)
  {
    *s++ = '-';
  }

  *s = '\0';

  reverse(s_start);
}

void reverse(char *s)
{
  char *t = s;
  char aux;

  while (*(t + 1))
    t++;

  for (; (t - s > 0); t--, s++)
  {
    aux = *s;
    *s = *t;
    *t = aux;
  }
}
