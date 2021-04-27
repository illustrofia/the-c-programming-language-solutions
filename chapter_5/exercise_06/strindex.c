#include <stdio.h>

#define MAXLEN 100

int getsline(char *s, int lim);
int strindex(char *s, char *t);

int main(void)
{
  char s[MAXLEN];
  char t[MAXLEN];

  // Testing strindex()
  printf("String to search into: ");
  getsline(s, MAXLEN);

  printf("String to find: ");
  getsline(t, MAXLEN);

  int index = strindex(s, t);

  if (index >= 0)
  {
    printf("String t found in s at index %i.\n\n", index);
  }
  else
  {
    printf("String t not found in s.\n\n");
  }

  return 1;
}

int getsline(char *s, int lim)
{
  int length = 0;

  while ((*s = getchar()) != EOF && *s != '\n' && lim--)
  {
    s++;
    length++;
  }

  *s = '\0';

  return length;
}

// strindex: return index of t in s, -1 if none
int strindex(char *s, char *t)
{
  char *s_copy;
  char *t_copy;
  int index = 0;

  for (index = 0; *s; s++, index++)
  {
    for (s_copy = s, t_copy = t; *t_copy == *s_copy; t_copy++, s_copy++)
      ;

    if (*t_copy == '\0')
    {
      return index;
    }
  }

  return -1;
}
