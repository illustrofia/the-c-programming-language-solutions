// Folds long input lines

#include <stdio.h>

#define MAXLINE 1000 // Maximum input line size

#define TRUE (1 == 1)
#define FALSE !TRUE

#define OFFSET 10
#define BREAKING_POINT 80

int getsline(char line[], int limit);
void fold(char line[], char folded_line[], int max_line_length);

int main(void)
{
  char line[MAXLINE];
  char folded_line[MAXLINE * 2];

  while ((getsline(line, MAXLINE)) > 0)
  {
    fold(line, folded_line, BREAKING_POINT);
    printf("%s", folded_line);
  }

  return 0;
}

// Reads a line into s, return length
int getsline(char s[], int limit)
{
  int c, i;

  for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; i++)
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

// Folds line[] into folded_line[]. Inserts '-' characters if line is too long
void fold(char line[], char folded_line[], int max_line_length)
{
  int i, j, m;
  int column = 0;
  int split = FALSE;
  int last_blank = 0;

  for (i = 0, j = 0; line[i] != '\0'; ++i, ++j)
  {
    folded_line[j] = line[i];

    if (folded_line[j] == '\n')
    {
      column = 0;
    }

    column++;

    if (column == max_line_length - OFFSET)
    {
      split = TRUE;
    }

    if (split && (folded_line[j] == ' ' || folded_line[j] == '\t'))
    {
      last_blank = j;
    }

    if (column == max_line_length)
    {
      if (last_blank)
      {
        folded_line[last_blank] = '\n';
        column = j - last_blank;
        last_blank = 0;
      }
      else
      {
        folded_line[j++] = '-';
        folded_line[j] = '\n';

        column = 0;
      }

      split = FALSE;
    }
  }

  folded_line[j] = '\0';
}
