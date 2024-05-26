// Sort program with -r and -f flag
// Program deletes last character from read lines; needs fix

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLINES 5000
#define MAXLEN 1000
#define ALLOCSIZE 10000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines, int reverse);

void quicksort(void *v[], int left, int right,
               int (*comp)(void *, void *));

int numcmp(char *s1, char *s2);
int strfcmp(char *s1, char *s2);

int main(int argc, char const *argv[])
{
  int nlines;
  int numeric = 0;
  int reverse = 0;
  int fold = 0;
  int i;

  if (argc > 1)
  {
    for (i = 1; i < argc; i++)
    {
      if (strcmp(argv[i], "-n") == 0)
      {
        numeric = 1;
      }
      else if (strcmp(argv[i], "-r") == 0)
      {
        reverse = 1;
      }
      else if (strcmp(argv[i], "-f") == 0)
      {
        fold = 1;
      }
    }
  }

  if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
  {
    if (numeric)
    {
      quicksort((void **)lineptr, 0, nlines - 1,
                (int (*)(void *, void *))(numcmp));
    }
    else if (fold)
    {
      quicksort((void **)lineptr, 0, nlines - 1,
                (int (*)(void *, void *))(strfcmp));
    }
    else
    {
      quicksort((void **)lineptr, 0, nlines - 1,
                (int (*)(void *, void *))(strcmp));
    }

    writelines(lineptr, nlines, reverse);

    return 0;
  }
  else
  {
    printf("input too big to sort\n");

    return 1;
  }

  return 0;
}

void quicksort(void *v[], int left, int right,
               int (*comp)(void *, void *))
{
  int i, last;

  void swap(void *v[], int, int);

  if (left >= right)
  {
    return;
  }

  swap(v, left, (left + right) / 2);

  last = left;

  for (i = left + 1; i <= right; i++)
  {
    if ((*comp)(v[i], v[left]) < 0)
    {
      swap(v, ++last, i);
    }
  }

  swap(v, left, last);
  quicksort(v, left, last - 1, comp);
  quicksort(v, last + 1, right, comp);
}

int numcmp(char *s1, char *s2)
{
  double v1, v2;

  v1 = atof(s1);
  v2 = atof(s2);

  if (v1 < v2)
  {
    return -1;
  }
  else if (v1 > v2)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int strfcmp(char *s1, char *s2)
{
  while (*s1 && *s2)
  {
    if (tolower(*s1) > tolower(*s2))
    {
      return 1;
    }
    else if (tolower(*s1) < tolower(*s2))
    {
      return -1;
    }

    ++s1, ++s2;
  }

  return 0;
}

void swap(void *v[], int i, int j)
{
  void *temp;
  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
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
void writelines(char *lineptr[], int nlines, int reverse)
{
  int i = 0;

  if (reverse)
  {
    for (i = nlines; --i > 0; *lineptr++)
      ;

    while (nlines-- > 0)
    {
      printf("%s\n", *lineptr--);
    }
  }
  else
  {
    while (nlines-- > 0)
    {
      printf("%s\n", *lineptr++);
    }
  }
}
