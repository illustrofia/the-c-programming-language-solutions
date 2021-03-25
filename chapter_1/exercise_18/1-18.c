// Removes trailing blanks and tabs from input

#include <stdio.h>

#define MAXLINE 1000 // Maximum input line size

int getsline(char line[], int maxline);
void copy(char from[], char to[]);

int main(void)
{
    int len;            // Line length
    char line[MAXLINE]; // Input line

    while ((len = getsline(line, MAXLINE)) > 0)
    {
        // Also, I should also write a version
        // for this program using character arrays
        for (int i = len - 1; i >= 0; i--)
        {
            if (line[i] == ' ' || line[i] == '\t')
            {
                for (int j = i; j < len; j++)
                {
                    line[j] = line[j + 1];
                }

                len--;
            }
        }

        printf("%s", line);
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
