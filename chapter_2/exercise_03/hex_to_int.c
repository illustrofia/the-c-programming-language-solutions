#include <stdio.h>
#include <math.h>

#define MAXHEX 100

int alternate_htoi(char hex[]);


int main(void)
{
    char hex[MAXHEX] = "f";

    printf("%i\n", alternate_htoi(hex));

    return 0;
}

// Converts string of hexadecimal digits into equivalent integer value
int alternate_htoi(char hex[])
{
    int i;
    int hexquivalent;
    int spare;

    i = 0;
    while (hex[i] != EOF)
    {
        i++;
    }

    hexquivalent = 0;
    for (int j = i; j >= 0; j--)
    {
        if (hex[j] >= 'A' && hex[j] <= 'F')
        {
            spare = 10 + hex[j] - 'A';
        }
        else if (hex[j] >= 'a' && hex[j] <= 'f')
        {
            spare = 10 + hex[j] - 'a';
        }

        if (hex[i] >= '0' && hex[i] <= '9')
        {
            hexquivalent += pow(16, i - j) * (hex[i] - '0');
        }
        else
        {
            hexquivalent += pow(16, i - j) * spare;
        }
    }

    return hexquivalent;
}