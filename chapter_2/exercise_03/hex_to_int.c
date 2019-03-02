#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAXHEX 100

int alternate_htoi(char hex[]);


int main(void)
{
    char hex[MAXHEX] = "0Xf23";

    printf("%s\n%i\n", hex, alternate_htoi(hex));

    return 0;
}

// Converts string of hexadecimal number into equivalent integer value
int alternate_htoi(char s[])
{
    int n = 0;

    int limit = (s[0] == '0') ? 2 : 0;

    for (int i = strlen(s) - 1; i >= limit; i--)
    {
        if (s[i] <= '9')
        {
            n += pow(16, strlen(s) - 1 - i) * (s[i] - '0');
        }
        else if (s[i] <= 'F')
        {
            n += pow(16, strlen(s) - 1 - i) * (s[i] - 'A' + 10);
        }
        else if (s[i] <= 'f')
        {
            n += pow(16, strlen(s) - 1 - i) * (s[i] - 'a' + 10);
        }
    }

    return n;
}