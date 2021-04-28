// Readlines stores lines in an array supplied by main

#include <stdio.h>
#include <string.h>

#define MAXMEMORY 5000 // Maximum storage memory
#define MAXLINES 50    // Maximum number of read lines

int readlines(char *lineptr[], int maxlines, char memory[], int maxmemory);
void writelines(char *lineptr[], int nlines);

void qsort(char *v[], int left, int right);

int main(void)
{
  int nlines;

  char memory[MAXMEMORY];
  char *lineptr[MAXLINES];

  if ((nlines = readlines(lineptr, MAXLINES, memory, MAXMEMORY)) >= 0)
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

#define MAXLEN 1000 // Maximum length of a line

// readlines: read input lines
int readlines(char *lineptr[], int maxlines, char memory[], int maxmemory)
{
  int len, nlines;
  char *p = memory;
  char line[MAXLEN];

  nlines = 0;
  while ((len = getsline(line, MAXLEN)) > 0)
  {
    if (nlines >= maxlines || p + len > memory + maxmemory)
    {
      return -1;
    }
    else
    {
      strcpy(p, line);
      lineptr[nlines++] = p;
      p += len + 1;
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
void swap(char *v[], int i, int j)
{
  char *temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}
