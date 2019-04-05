// Prints the last n (default 10) lines of input

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_NUMBER_OF_LINES 10
#define MAXLINES 5000   // Maximum number of read lines
#define MAXLEN 1000     // Maximum length of a line
#define ALLOCSIZE 10000 // Maximum allocated memory space

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

int main(int argc, char const *argv[])
{
    int nlines;

    int n = (argc > 1) ? (-1) * atoi(argv[1]) : DEFAULT_NUMBER_OF_LINES;

    printf("n: %d\n", n);

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        writelines(lineptr, n);

        return 0;
    }
    else
    {
        printf("error: input too big to sort\n");

        return 1;
    }
}

// getsline: stores line in s, returns length of s.
int getsline(char *s, int maxlen)
{
    int i = 0;

    while ((*s = getchar()) != EOF && (*s != '\n') && ++i < maxlen)
    {
        s++;
    }

    *s = '\0';

    return i;
}

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n)
{
    if (allocbuf + ALLOCSIZE - allocp >= n)
    {
        allocp += n;
        return allocp - n;
    }
    else
    {
        return 0;
    }
}

// readlines: read input lines
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;

    while ((len = getsline(line, MAXLEN)) > 0)
    {
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
        {
            return -1;
        }
        else
        {
            // Delete newline character
            line[len - 1] = '\0';
            strcpy(p, line);

            lineptr[nlines++] = p;
        }
    }

    return nlines;
}

// writelines: write output lines
void writelines(char *lineptr[], int nlines)
{
    while (nlines-- > 0)
    {
        printf("%s\n", *lineptr++);
    }
}