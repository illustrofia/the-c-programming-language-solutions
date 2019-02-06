// Prints longest input line

#include <stdio.h>

#define MAXLINE 1000        // Maximum input line size

int getsline(char line[], int maxline);
void copy(char from[], char to[]);

int main(void)
{
    int len;                // Current line length
    char line[MAXLINE];     // Current input line

    int maxlen;             // Maximum length seen so far
    char longest[MAXLINE];  // Longest line saved here

    maxlen = 0;
    while ((len = getsline(line, MAXLINE)) > 0)
    {
        if (len > maxlen)
        {
            maxlen = len;
            copy(line, longest);
        }
    }

    if (maxlen > 0)
    {
        printf("\nLongest line is %d characters:\n%s\n", maxlen, longest);
    }

    return 0;
}


// Reads a line into s, return length
int getsline(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
    {
        s[i] = c;
    }

    if (c == '\n')
    {
        s[i] = c;
        i++;
    }
    
    s[i] = '\0';
    return i;
}

// Copies 'from' into 'to'
void copy(char from[], char to[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
    {
        i++;
    }
}