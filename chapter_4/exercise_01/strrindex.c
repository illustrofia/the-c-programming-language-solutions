// Birth of strrindex()

#include <stdio.h>
#include <string.h>

#define MAXLEN 1000

int getsline(char s[], int lim);
int strrindex(char s[], char t[]);

char pattern[] = "ould";

int main(void)
{
    char s[MAXLEN];

    while (getsline(s, MAXLEN) > 0)
    {
        if (strrindex(s, pattern))
        {
            printf("rightmost position of t in s is %d\n", strrindex(s, pattern));
        }
    }
}

int getsline(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    {
        s[i++] = c;
    }

    if (c == '\n')
    {
        s[i++] = c;
    }
    
    s[i] = '\0';

    return i;
}

int strrindex(char s[], char t[])
{
    int i, j, k;

    for (int i = strlen(s) - 1; i >= strlen(t) - 1; i--)
    {
        for (j = i, k = strlen(t) - 1; j >= 0 && k >= 0 && s[j] == t[k]; j--, k--)
            ;
        
        if (++k == 0)
        {
            return i - strlen(t) + 1;
        }
    }

    return -1;
}