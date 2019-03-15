// Version of atof() that handles scientific notation

#include <stdio.h>
#include <ctype.h>

#define MAXLEN 100

int getsline(char line[], int lim);
double atof(char s[]);

int main(void)
{
    char line[MAXLEN];

    getsline(line, MAXLEN);

    printf("%f\n", atof(line));

    return 0;
}

int getsline(char line[], int lim)
{
    int i = 0, c;

    while (i < lim - 1 && (c = getchar()) != '\n')
    {
        line[i] = c;
        ++i;
    }

    if (c == '\n')
    {
        line[i++] = c;
    }

    line[i] = '\0';

    return i;
}

double atof(char s[])
{
    double val, power;
    int i, sign, exp_sign, exp_power;

    for (i = 0; isspace(s[i]); i++);

    sign = (s[i] == '-') ? -1 : 1;

    if (s[i] == '+' || s[i] == '-')
    {
        i++;
    }

    for (val = 0.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
    }

    if (s[i] == '.')
    {
        i++;
    }

    for (power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power /= 10;
    }

    if (s[i] == 'e' || s[i] == 'E')
    {
        if (s[++i] == '-')
        {
            exp_sign = -1;
        }
        else
        {
            exp_sign = 1;
        }

        exp_power = 0;
        while (isdigit(s[++i]))
        {
            exp_power = 10 * exp_power + (s[i] - '0');
        }

        for (exp_power; exp_power > 0 ; exp_power--)
        {
            if (exp_sign < 0)
            {
                power /= 10;
            }
            else
            {
                power *= 10;
            }
        }
    }

    return sign * val * power;
}