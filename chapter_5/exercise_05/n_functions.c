// Pointer versions of the library functions
// strncpy(), strncat() and strncmp()

#include <stdio.h>

#define MAXLEN 100

void strncpy_ptr(char *s, char *t, int n);
void strncat_ptr(char *s, char *t, int n);
int strncmp_ptr(char *s, char *t, int n);

int main(void)
{
  char s[MAXLEN] = "I really love chocolate!";
  char t[MAXLEN] = " But I like icecream more!";
  char b[MAXLEN] = "I really loathe chocolate.";

  printf("Initial s: %s\nInitial b: %s\nInitial t: %s\n", s, b, t);

  // Testing strncpy_ptr
  int n = 11;

  strncpy_ptr(s, b, n);

  printf("\ns after copying %d characters from b: %s\n", n, s);

  // Testing strncmp_ptr
  if (strncmp_ptr(s, b, 11) == 0)
  {
    printf("\nFirst %d characters of s are the same as b.\n", n);
  }
  else
  {
    printf("\nFirst %d characters of s are not the same as b.\n", n);
  }

  // Testing strncat_ptr
  int m = 15;

  strncat_ptr(s, t, m);

  printf("\ns after concatenating %d characters from b to end of s: %s\n", m, s);

  return 0;
}

// Copies no more than n characters of t to s.
void strncpy_ptr(char *s, char *t, int n)
{
  while (*s++ = *t++)
  {
    if (!--n)
    {
      break;
    }
  }
}

// Concatenates n characters of t to end of s.
void strncat_ptr(char *s, char *t, int n)
{
  // Get to end of s
  while (*++s)
    ;

  // Concatenate n characters of t to end of s
  while (*s++ = *t++)
  {
    if (!--n)
    {
      break;
    }
  }

  *++s = '\0';
}

// Compares n characters of s and t.
// Returns negative, zero, or positive for
// s < t, s == t or s > t.
int strncmp_ptr(char *s, char *t, int n)
{
  for (; *s == *t; *s++, *t++)
  {
    if (*s == '\0')
    {
      return 0;
    }

    if (!--n)
    {
      break;
    }
  }

  return *s - *t;
}
