#include <stdio.h>

#define MAXLINE 100

void alternate_squeeze(char s1[], char s2[]);

int main(void)
{
    char s1[MAXLINE] = "I love chocolate";
    char s2[MAXLINE] = "oh, daughter";

    alternate_squeeze(s1, s2);

    printf("%s\n", s1);

    return 0;
}

void alternate_squeeze(char s1[], char s2[])
{
    int i, j, k;

    for (k = 0; s2[k] != '\0'; k++)
    {
        for (i = j = 0; s1[i] != '\0'; i++)
        {
            if (s1[i] != s2[k])
            {
                s1[j++] = s1[i];
            }
        }

        s1[j] = '\0';
    }
}