#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char[]);
void push(double);
double pop(void);
void print();
void duplicate();
void swap();
void clear();

int main(void)
{
  int type;
  double op2;
  char s[MAXOP];

  while ((type = getop(s)) != EOF)
  {
    switch (type)
    {
    case NUMBER:
      push(atof(s));
      break;

    case '+':
      push(pop() + pop());
      break;

    case '-':
      op2 = pop();
      push(pop() - op2);
      break;

    case '*':
      push(pop() * pop());
      break;

    case '/':
      if ((op2 = pop()) != 0)
      {
        push(pop() / op2);
      }
      else
        printf("error: zero divisor\n");
      break;

    case '%':
      if ((op2 = pop()) != 0)
      {
        push((int)pop() % (int)op2);
      }
      else
        printf("error: zero divisor\n");
      break;

    case '\n':
      printf("\t%.8g\n", pop());
      break;

    default:
      printf("error: unknown command %s\n", s);
      break;
    }
  }

  return 0;
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f)
{
  if (sp < MAXVAL)
  {
    val[sp++] = f;
  }
  else
  {
    printf("error: stack overflow, can't push %g\n", f);
  }
}

double pop(void)
{
  if (sp > 0)
  {
    return val[--sp];
  }
  else
  {
    printf("error: stack empty\n");
    return 0.0;
  }
}

#include <ctype.h>

int getch(void);

int getop(char s[])
{
  int i, c;

  static int buf = 0;

  if (buf == 0)
  {
    c = getch();
  }
  else
  {
    c = buf;
    buf = 0;
  }

  while ((s[0] = c) == ' ' || c == '\t')
  {
    c = getch();
  }

  s[1] = '\0';

  if (!isdigit(c) && c != '.' && c != '-')
  {
    return c;
  }

  i = 0;

  // Check if - is an operand or a sign
  if (c == '-')
  {
    s[++i] = c = getch();

    if (!isdigit(c) && c != '.')
    {
      if (c != EOF)
      {
        buf = c;
      }

      return '-';
    }
  }

  if (isdigit(c))
  {
    while (isdigit(s[++i] = c = getch()))
      ;
  }

  if (c == '.')
  {
    while (isdigit(s[++i] = c = getch()))
      ;
  }

  s[i] = '\0';

  if (c != EOF)
  {
    buf = c;
  }

  return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}
