// La parole est d'argent, le silence est d'or.

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXLEN 100
#define NUMBER 0
#define MAXVAL 100

int getop(char *s, char *op);
void push(double f);
double pop(void);

int main(int argc, char *argv[])
{
  char op[MAXLEN];
  int op2;

  int i;
  for (i = 0; i < argc; ++i)
  {
    switch (getop(argv[i], op))
    {
    case NUMBER:
      push(atof(op));
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
      printf("error: unknown command %s\n", op);
      break;
    }
  }

  printf("result: %g\n", pop());

  return 0;
}

// getop: get next operator or numeric operand (for RPC)
int getop(char *s, char *op)
{

  *op = *s;

  *(op + 1) = '\0';

  // Not a number
  if (!isdigit(*op) && *op != '.')
  {
    return *op;
  }

  // Collect integer part
  if (isdigit(*op))
  {
    while (isdigit(*(++op) = *(++s)))
      ;
  }

  // Collect fractional part
  if (*op == '.')
  {
    while (isdigit(*(++op) = *(++s)))
      ;
  }

  // Push character back to input
  if (*op != EOF)
  {
    ungetc(*op, stdin);
  }

  *op = '\0';

  return NUMBER;
}

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
