// Description

#include <stdio.h>
#include <string.h>

#define MAXLEN 100

void recursive_itoa (int n, char s[]);
void reverse(char s[]);

int main(void)
{
    char s[MAXLEN] = "";
    int n = 12345;

    recursive_itoa(n, s);

    printf("%i = '%s'\n", n, s);

    return 0;
}

void recursive_itoa (int n, char s[])
{
    int s_len = strlen(s);

    s[s_len] = n % 10 + '0';

    if (n / 10)
    {
        return recursive_itoa(n / 10, s);
    }

    s[++s_len] = '\0';

    reverse(s);

    return;
}

void reverse(char s[])
{
    int i = strlen(s) - 1;
    int aux;

    for (int j = 0; j < i; i--, j++)
    {
        aux = s[i];
        s[i] = s[j];
        s[j] = aux;
    }
}