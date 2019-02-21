#include <stdio.h>

int alternate_lower(int c);


int main(void)
{
    char a = 'L';

    putchar(alternate_lower(a));

    return 0;
}

    squeeze(s1, s2);

    squeeze(s1, s2);

int alternate_lower(int c)
{
    return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}