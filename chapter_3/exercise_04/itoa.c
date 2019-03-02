// Modified version of itoa()

#include <stdio.h>

#define MAXLEN 100

void itoa(int n, char s[]);

int main(void)
{
    char s[MAXLEN];
    int n = -2147483648;
    
    itoa(n, s);

    printf("%s\n", s);
}

void itoa(int n, char s[])
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

    s[i--] = '\0';

    int aux;
    for (int j = 0; j < i; i--, j++)
    {
        aux = s[i];
        s[i] = s[j];
        s[j] = aux;
    }
}

// Observation

// The smallest possible number in a two's complementary number representation,
// when multiplied with (-1), will become with 1 unit greater than the greatest
// number. We cannot store that value using the same amount of bits, because
// the sign bit will overflow. To solve this, we do not multiply with (-1), but
// instead leave the number as is, and provide different conversions depending
// on the polarity of the number.