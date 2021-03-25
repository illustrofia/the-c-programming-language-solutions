// Prints lines longer than 80 characters

#include <stdio.h>

#define MAXLINE 1000 // Maximum input line size

int getsline(char line[], int maxline);
void copy(char from[], char to[]);

int main(void)
{
    int len;            // Current line length
    char line[MAXLINE]; // Current input line

    while ((len = getsline(line, MAXLINE) - 1) > 0)
    {
        if (len > 80)
        {
            printf("\n%s\n", line);
            printf("Line size: %d", len);
        }
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
