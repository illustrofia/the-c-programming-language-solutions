// Birth of strend()

#include <stdio.h>

#define MAXLEN 100

int strend(char *s, char *t);
int my_strlen(char *s);

int main(void)
{
  char s[MAXLEN] = "I really love chocolate! But I like icecream more!";
  char t[MAXLEN] = " But I like icecream more!";

  if (strend(s, t))
  {
    printf("String 't' occurs at end of 's'\n");
  }
  else
  {
    printf("String 't' does not occur at end of 's'\n");
  }

  return 0;
}

int my_strlen(char *s)
{
  int length = 0;

  // While *s doesn't point to '\0'
  while (*s++ && ++length)
    ;

  return length;
}

int strend(char *s, char *t)
{
  int t_length = my_strlen(t);

  // Get to end of both strings
  while (*++s)
    ;
  while (*++t)
    ;

  // Compare t's characters with s's characters until t's beginning
  while (t_length--)
  {
    if (*--s != *--t)
    {
      return 0;
    }
  }

  return 1;
}
