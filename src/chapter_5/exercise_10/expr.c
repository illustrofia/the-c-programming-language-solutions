#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLEN 100 // Maximum length of operand
#define NUMBER 0

int getop(char *arg);
void push(double f);
double pop(void);

int main(int argc, char *argv[])
{
  int op2;

  for (int i = 1; i < argc; i++)
  {
    switch (getop(argv[i]))
    {
    case NUMBER:
      push(atof(argv[i]));
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

    default:
      printf("error: unknown command %s\n", argv[i]);
      break;
    }
  }

  printf("result: %g\n", pop());

  return 0;
}

int getop(char *arg)
{
  // Skip blanks
  while (isblank(*arg))
  {
    arg++;
  }

  // Not a number?
  if (!isdigit(*arg) && *arg != '.' && *arg != '-')
  {
    return *arg;
  }

  // Negative number or just '-' operator?
  if (*arg == '-')
  {
    if (!isdigit(*(arg + 1)) && *(arg + 1) != '.')
    {
      return '-';
    }
  }

  return NUMBER;
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
