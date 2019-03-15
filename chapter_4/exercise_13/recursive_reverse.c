// Birth of recursive version of reverse()

#include <stdio.h>
#include <string.h>

#define MAXLEN 100

void reverse(char s[]);

int main(void)
{
    char s[MAXLEN] = "test string";

    reverse(s);

    printf("%s\n", s);

    return 0;
}


void reverse(char s[])
{
    static int i = 0;
    static int j = 0;

    if (s[i] != '\0')
    {
        char c = s[i++];
        reverse(s);

        s[j++] = c;
    }
}