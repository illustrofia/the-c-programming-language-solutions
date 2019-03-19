// Fixed getint()

#include <stdio.h>
#include <ctype.h>

#define SIZE 100
#define MAXLEN 200

int getint(int *pn);
void printbuf();

int main(void)
{
    int number = 0;

    getint(&number);

    printf("%d\n", number);

    printbuf();

    return 0;
}

int getch(void);
void ungetch(int c);

int getint(int *pn)
{
    int c, sign;

    while(isspace(c = getch()));

    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-')
    {
        c = getch();

        if (!isdigit(c))
        {
            ungetch(c);
            ungetch(sign == 1 ? '+' : '-');
            return 0;
        }
    }

    for (*pn = 0; isdigit(c); c = getch())
    {
        *pn = 10 * *pn + (c - '0');
    }

    *pn *= sign;

    if (c != EOF)
    {
        ungetch(c);
    }

    return c;
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

void printbuf()
{
    if (bufp)
    {
        printf("Buffer: [");

        for (int i = bufp - 1; i >= 0; i--)
        {
            if (i)
            {
                printf("'%c', ", buf[i] != '\n' ? buf[i] : '.');
            }
            else
            {
                printf("'%c'", buf[i] != '\n' ? buf[i] : '.');
            }
        }

        printf("]\n");
    }
}