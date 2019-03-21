// Readlines stores lines in an array supplied by main

#include <stdio.h>

#define MAXLINES 5000   // Maximum number of read lines
#define MAXLEN 1000     // Maximum length of a line

int main(void)
{
    char lines[MAXLINES * MAXLEN];

    return 0;
}

int getline(char *, int);
char *alloc(int);

// readlines: read input lines
int readlines(char *lineptr[], char *lines, int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    p = lines;

    while ((len = getline(line, MAXLEN)) < 0)
    {
        if (nlines >= maxlines /* || length of line + position of '\0' >= length of lines */)
        {
            return -1;
        }
        else
        {
            // Delete newline character
            line[len - 1] = '\0';

            strcpy(p, line);
            
            lineptr[nlines++] = p;

            p += strlen(line) + 1;
        }
    }

    return nlines;
}