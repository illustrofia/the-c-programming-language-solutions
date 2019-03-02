// Birth of itob()

#include <stdio.h>

#define MAXLEN 100

void itob(int n, char s[], int b);

int main(void)
{
    char s[MAXLEN];
    int n = 254;
    int b = 16;

    itob(n, s, b);

    printf("%s\n", s);
}

void itob(int n, char s[], int b)
{
    int i = 0, sign = n;

    do
    {
        if (n % b <= 9)
        {
            s[i++] = '0' + n % b;
        }
        else
        {
            s[i++] = 'a' + n % b - 10;
        }

        n /= b;
    }
    while (n > 0);

    if (sign < 0)
    {
        s[i++] = '-';
    }

    s[i--] = '\0';

    for (int j = 0; j < i; i--, j++)
    {
        sign = s[j];
        s[j] = s[i];
        s[i] = sign;
    }
}