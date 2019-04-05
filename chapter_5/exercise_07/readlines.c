// Readlines stores lines in an array supplied by main

#include <stdio.h>
#include <string.h>

#define MAXLINES 5000   // Maximum number of read lines
#define MAXLEN 1000     // Maximum length of a line

int readlines(char *lineptr[], char *lines, int maxlines, int maxlen);
void writelines(char *lineptr[], int nlines);

void qsort(char *v[], int left, int right);

int main(void)
{
    int nlines;

    char lines[MAXLINES * MAXLEN];
    char *lineptr[MAXLINES];

    if ((nlines = readlines(lineptr, lines, MAXLINES, MAXLEN)) >= 0)
    {
        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("error: input too big to sort\n");
        return 1;
    }

    return 0;
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

// readlines: read input lines
int readlines(char *lineptr[], char *lines, int maxlines, int maxlen)
{
    int len, nlines;
    char *p, line[MAXLEN];
    char *end_of_lines = lines + maxlines * maxlen;

    nlines = 0;

    while ((len = getsline(line, maxlen)) > 0)
    {
        if (nlines >= maxlines || lines + len >= end_of_lines)
        {
            return -1;
        }
        else
        {
            // Delete newline character
            line[len - 1] = line[len - 1] == '\n' ? '\0' : line[len - 1];

            strcpy(lines, line);

            // lineptr[nlines] points at beginning of line (each ending in '\0') in lines array
            lineptr[nlines++] = lines;
            lines += len + 1;
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

// qsort: sort array into increasing order
void qsort(char *v[], int left, int right)
{
    int i, last;
    void swap(char *v[], int i, int j);

    // If array contains fewer than 2 elements, do nothing
    if (left >= right)
    {
        return;
    }

    swap(v, left, (left + right) / 2);

    last = left;

    for (i = left + 1; i <= right; i++)
    {
        if (strcmp(v[i], v[left]) < 0)
        {
            swap(v, ++last, i);
        }
    }

    swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

// swap: interchange v[i] and v[j]
void swap (char *v[], int i, int j)
{
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
