// Prints reversed lines

#include <stdio.h>

#define MAXLINE 1000 // Maximum input line size

int getsline(char line[], int maxline);
void reverse(char line[], char reversed[], int length);

int main(void)
{
    int len;            // Line length
    char line[MAXLINE]; // Input line

    char reversed[MAXLINE]; // Reversed line generated here

    while ((len = getsline(line, MAXLINE)) > 0)
    {
        reverse(line, reversed, len - 2);
        printf("%s", reversed);
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

// Reverses line
void reverse(char line[], char reversed[], int length)
{
    int i = 0;

    for (length; length >= 0; length--)
    {
        reversed[i] = line[length];
        i++;
    }

    reversed[i] = '\n';
    reversed[i + 1] = '\0';
}
