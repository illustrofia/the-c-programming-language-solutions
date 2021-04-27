#include <stdio.h>
#include <ctype.h>

#define MAXLEN 100

int getsline(char *s, int lim);
int getop(char *s);

int main(void)
{
  char s[MAXLEN];

  // Testing getop()
  printf("Operand/operator for getop: ");
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
