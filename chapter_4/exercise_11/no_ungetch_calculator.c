// Instead of ungetch(), we use an internal static variable

// Needs more work, the switch executes
// the default case for some reason

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAXOP 100
#define NUMBER '0'
#define VARGET 'A'
#define VARSET '_'
#define MAXINPUT 100

int getop(char []);
void push(double);
double pop(void);
void print();
void duplicate();
void swap();
void clear();
int is_empty(void);

void varset(double n);
double varget(char var);
char var;

void ungets(char s[]);
char input[MAXINPUT] = "700 70 7 + +";

int main(void)
{
    int type;
    double op2, last_val;
    char s[MAXOP];

    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
            case NUMBER:
                push(atof(s));
            break;

            case VARGET:
                varget(var);
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
                else printf("error: zero divisor\n");
            break;

            case '%':
                if ((op2 = pop()) != 0)
                {
                    push((int)pop() % (int)op2);
                }
                else printf("error: zero divisor\n");
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

            case 'u':
                ungets(input);
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
    else printf("error: stack already empty");
}

int is_empty(void)
{
    if (sp > 0)
    {
        return 0;
    }
    
    return 1;
}

#define MAXVAR 26

double varstack[MAXVAR];
int var_sp;

void varset(double n)
{
    if (var_sp < MAXVAR && n != 0)
    {
        varstack[var_sp++] = n;
        printf("variable %c = %.3f\n", 'A' + var_sp - 1, n);
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

double varget(char var)
{
    if (varstack[var - 'A'])
    {
        push(varstack[var - 'A']);
    }
    else
    {
        printf("error: variable %c not set\n", var);
    }
}

#include <ctype.h>

int getch(void);
void ungetch(int);

int getop(char s[])
{
    int i, c;
    char static buf;
    int static buf_set = 0;

    while ((s[0] = c = buf_set-- ? buf : getchar()) == ' ' || c == '\t');

    s[1] = '\0';

    if (isalpha(c) && c <= 'Z')
    {
        var = c;
        return VARGET;
    }

    if (c == '$')
    {
        return c;
    }

    if (!isdigit(c) && c != '.' && c != '-')
    {
        return c;
    }
    
    i = 0;

    if (c == '-')
    {
        int next = getchar();
        
        if (isdigit(next))
        {
            s[++i] = c = next;
        }
        else if (next != '.')
        {
            if (next != EOF)
            {
                buf = next;
                buf_set = 1;
            }

            return c;
        }
    }

    if (isdigit(c))
    {
        while (isdigit(s[++i] = c = buf_set-- ? buf : getchar()));
    }

    if (c == '.')
    {
        while (isdigit(s[++i] = c = buf_set-- ? buf : getchar()));
    }

    s[i] = '\0';

    if (c != EOF)
    {
        buf = c;
        buf_set = 1;
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

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
    {
        printf("ungetch: too many characters\n");
    }
    else
    {
        buf[bufp++] = c;
    }
}

void ungets(char s[])
{
    for (int i = strlen(s) - 1; i >= 0; i--)
    {
        ungetch(s[i]);
    }
}