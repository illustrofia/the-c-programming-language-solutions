// Birth of three arguments itoa()

#include <stdio.h>

#define MAXLEN 100

void itoa(int n, char s[], int minimum_field_width);

int main(void)
{
    char s[MAXLEN];
    int n = -2147483648;
    
    itoa(n, s, 12);

    printf("%s\n", s);
}

void itoa(int n, char s[], int minimum_field_width)
{
    int i, sign;

    i = 0;
    sign = n;

    if (n < 0)
    {
        do
        {
            s[i++] = -(n % 10) + '0';
        }
        while ((n /= 10) != 0);
    }
    else 
    {
        do
        {
            s[i++] = n % 10 + '0';
        }
        while ((n /= 10) > 0);
    }

    if (sign < 0)
    {
        s[i++] = '-';
    }

    while (i < minimum_field_width)
    {
        s[i++] = ' ';
    }

    s[i--] = '\0';

    int aux;
    for (int j = 0; j < i; i--, j++)
    {
        aux = s[i];
        s[i] = s[j];
        s[j] = aux;
    }
}