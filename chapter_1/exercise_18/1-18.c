// Removes trailing blanks and tabs from input

#include <stdio.h>

#define MAXLINE 1000 // Maximum input line size

int getsline(char line[], int maxline);
int remove_trailing_blanks(char line[], int length);

int main(void)
{
    char line[MAXLINE]; // Input line
    int len;            // Line length
    int newline_ending; // For newline ending character

    while ((len = getsline(line, MAXLINE) - 1) > 0)
    {
        remove_trailing_blanks(line, len);

        printf("\n%s", line);
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

int remove_trailing_blanks(char line[], int length)
{
    int i = length - 1;

    while (line[i] == ' ' || line[i] == '\t' || line[i] == '\n')
    {
        i--;
    }

    line[i + 1] = '\n';
    line[i + 2] = '\0';
}
