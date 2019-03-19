// Pointer version of strcat()

#include <stdio.h>

#define MAXLEN 100

void pointer_strcat(char *s, char *t);

int main(void)
{
    char s[MAXLEN] = "I really love chocolate!";
    char t[MAXLEN] = " But I like icecream more!";

    pointer_strcat(s, t);

    printf("%s\n", s);

    return 0;
}

void pointer_strcat(char *s, char *t)
{
    // Get to end of s
    while (*++s);

    // Concatenate t at end of s
    while (*s++ = *t++);
}
