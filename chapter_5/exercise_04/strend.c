#include <stdio.h>

#define MAXLEN 100

int strend(char *s, char *t);
int my_strlen(char *s);

int main(void)
{
  char s[MAXLEN] = "I really love chocolate! But I like icecream more!";
  char t[MAXLEN] = "But I like  icecream more!";

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

int strend(char *s, char *t)
{
  char *t_start = t;

  while (*++s)
    ;

  while (*++t)
    ;

  while (t_start <= t)
  {
    if (*s-- != *t--)
    {
      return 0;
    }
  }

  return 1;
}
