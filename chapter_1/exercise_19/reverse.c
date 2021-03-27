// Prints reversed lines

#include <stdio.h>

#define MAXLINE 1000 // Maximum input line size

int getsline(char line[], int maxline);
void reverse(char line[], int length);

int main(void)
{
    char line[MAXLINE]; // Input line
    int length;         // Line length

    while ((length = getsline(line, MAXLINE)) > 0)
    {
        reverse(line, length);
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
    else
    {
        s[i + 1] = '\n';
        i += 2;
    }

    s[i] = '\0';
    return i;
}

// Reverses line
void reverse(char line[], int length)
{
    int i = 0;
    int j = length - 2;
    int temp;

    while (i < j)
    {
        temp = line[i];
        line[i] = line[j];
        line[j] = temp;

        i++;
        j--;
    }
}
