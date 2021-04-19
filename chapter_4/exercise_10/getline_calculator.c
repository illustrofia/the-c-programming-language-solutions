#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXLINE 500
#define MAXOP 100
#define NUMBER '0'
#define VARGET '#'
#define VARSET '_'
#define MAXINPUT 100

int getop(char s[]);
void push(double);
double pop(void);
void print();
void duplicate();
void swap();
void clear();
int is_empty(void);

void varset(double n);
void varget();
char var;

void print_instructions();
int getsline(char s[], int lim);

char line[MAXLINE];
int line_p;

int main(void)
{
  int type;
  double op2, last_val;
  char s[MAXOP];

  print_instructions();

  while (getsline(line, MAXLINE) != 0)
  {
    line_p = 0;

    while ((type = getop(s)) != '\0')
    {
      switch (type)
      {
      case NUMBER:
        push(atof(s));
        break;

      case VARGET:
        varget();
        break;

      case VARSET:
        varset(pop());
        break;

      case '$':
        push(last_val);
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

      case '^':
        op2 = pop();
        push(pow(op2, pop()));
        break;

      case '~':
        push(sin(pop()));
        break;

      case 'e':
        push(exp(pop()));
        break;

      case '\n':
        if (!is_empty())
        {
          last_val = pop();
          printf("\t%.8g\n", last_val);
        }
        break;

      case 'p':
        print();
        break;

      case 'd':
        duplicate();
        break;

      case 's':
        swap();
        break;

      case 'c':
        clear();
        break;

      default:
        printf("error: unknown command %s\n", s);
        break;
      }
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

void print()
{
  if (sp > 0)
  {
    printf("Top element in stack: %.8g\n", val[sp - 1]);
  }
  else
  {
    printf("error: stack empty\n");
  }
}

void duplicate()
{
  if (sp > 0)
  {
    push(val[sp - 1]);
  }
  else
  {
    printf("error: stack empty\n");
  }
}

void swap()
{
  if (sp > 1)
  {
    double op1 = pop();
    double op2 = pop();

    push(op1);
    push(op2);
  }
  else
  {
    printf("error: not enough elements to swap\n");
  }
}

void clear()
{
  if (sp)
  {
    sp = 0;
  }
  else
    printf("error: stack already empty\n");
}

int is_empty(void)
{
  if (sp > 0)
  {
    return 0;
  }

  return 1;
}

#include <ctype.h>

int getop(char s[])
{
  int i, c;

  while ((s[0] = c = line[line_p++]) == ' ' || c == '\t')
    ;

  s[1] = '\0';

  if (!isdigit(c) && c != '.' && c != '-')
  {
    return c;
  }

  i = 0;

  // Check if - is an operand or a sign
  if (c == '-')
  {
    s[++i] = c = line[line_p++];

    if (!isdigit(c) && c != '.')
    {
      if (c != EOF)
      {
        line_p--;
      }

      return '-';
    }
  }

  if (isdigit(c))
  {
    while (isdigit(s[++i] = c = line[line_p++]))
      ;
  }

  if (c == '.')
  {
    while (isdigit(s[++i] = c = line[line_p++]))
      ;
  }

  s[i] = '\0';

  if (c != EOF)
  {
    line_p--;
  }

  return NUMBER;
}

#define MAXVAR 26

double varstack[MAXVAR];
int var_sp;

void varset(double n)
{
  int next = line[line_p++];
  if (isalpha(next) && next <= 'Z')
  {
    if (var_sp < MAXVAR && n != 0)
    {
      varstack[next - 'A'] = n;
      printf("variable %c = %.3f\n", next, varstack[next - 'A']);
    }
    else if (var_sp >= MAXVAR)
    {
      printf("error: variable stack overflow\n");
    }
    else
    {
      printf("error: cannot set variable to 0\n");
    }
  }
  else
  {
    line_p--;
    printf("error: only uppercase letter variables\n");
  }
}

void varget()
{
  int next = line[line_p++];
  if (isalpha(next) && next <= 'Z')
  {
    if (varstack[next - 'A'])
    {
      push(varstack[next - 'A']);
    }
    else
    {
      printf("error: variable %c not set\n", next);
    }
  }
  else
  {
    line_p--;
    printf("error: only uppercase letter variables\n");
  }
}

#include <string.h>

int getsline(char s[], int lim)
{
  int c, i;

  i = 0;
  while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
  {
    s[i++] = c;
  }

  if (c == '\n')
  {
    s[i++] = c;
  }

  s[i] = '\0';

  return i;
}

void print_instructions()
{
  printf("Commands:\n");
  printf("set variable: _[name]\n");
  printf("get variable [name]: #[name]\n");
  printf("last printed value: $\n");
}
