#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAXLEN 100

int getsline(char *s, int lim);
int atoi_ptr(char *s);
void itoa_ptr(int n, char *s);
void reverse(char *s);
int strindex(char *s, char *t);
int getop(char *s);

int main(void)
{
  char s[MAXLEN];
  char t[MAXLEN];
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

  printf("Integer %i into string: \"%s\"\n\n", n, s);

  // Testing strindex()
  printf("String to search into: ");
  getsline(s, MAXLEN);

  printf("String to find: ");
  getsline(t, MAXLEN);

  int index = strindex(s, t);

  if (index >= 0)
  {
    printf("String t found in s at index %i.\n\n", index);
  }
  else
  {
    printf("String t not found in s.\n\n");
  }

  // Testing getop()

  printf("Please type an operand/operator for getop: ");
  int type = getop(s);

  printf("getop type is: %i\n", type);

  printf("s after getop is equal to \"%s\"\n", s);

  return 1;
}

#define NUMBER 0

// getop: get next operator or numeric operand (for RPC)
int getop(char *s)
{
  int c;

  // Skip whitespace
  while ((*s = c = getchar()) == ' ' || c == '\t')
    ;

  *(s + 1) = '\0';

  // Not a number
  if (!isdigit(c) && c != '.')
  {
    return c;
  }

  // Collect integer part
  if (isdigit(c))
  {
    while (isdigit(*++s = c = getchar()))
      ;
  }

  // Collect fractional part
  if (c == '.')
  {
    while (isdigit(*++s = c = getchar()))
      ;
  }

  // Push character back to input
  if (c != EOF)
  {
    ungetc(c, stdin);
  }

  *s = '\0';

  return NUMBER;
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

// strindex: return index of t in s, -1 if none
int strindex(char *s, char *t)
{
  char *s_copy;
  char *t_copy;
  int index = 0;

  for (index = 0; *s; s++, index++)
  {
    for (s_copy = s, t_copy = t; *t_copy == *s_copy; t_copy++, s_copy++)
      ;

    if (*t_copy == '\0')
    {
      return index;
    }
  }

  return -1;
}
