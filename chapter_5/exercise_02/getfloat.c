// Birth of getfloat()

#include <stdio.h>
#include <ctype.h>

#define SIZE 100
#define MAXLEN 200

int getfloat(double *pn);

int main(void)
{
    double number = 0.0;

    getfloat(&number);

    printf("%f\n", number);

    return 0;
}

int getch(void);
void ungetch(int c);

int getfloat(double *pn)
{
    int c, sign;
    double power;

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

    for (*pn = 0.0; isdigit(c); c = getch())
    {
        *pn = 10.0 * *pn + (c - '0');
    }

    if (c == '.')
    {
        c = getch();

        if (!isdigit(c))
        {
            ungetch(c);
            ungetch ('.');
            return 0;
        }
    }

    for (power = 1.0; isdigit(c); c = getch())
    {
        *pn = 10.0 * *pn + (c - '0');
        power /= 10;
    }

    *pn *= sign;

    *pn *= power;

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