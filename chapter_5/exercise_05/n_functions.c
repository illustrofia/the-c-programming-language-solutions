#include <stdio.h>

#define MAXLEN 100

void strncpy_ptr(char *s, char *t, int n);
void strncat_ptr(char *s, char *t, int n);
int strncmp_ptr(char *s, char *t, int n);

int main(void)
{
  char s[MAXLEN] = "I really love chocolate.";
  char b[MAXLEN] = "We don't loathe chocolate.";
  int n = 11;

  printf("Initial s: \"%s\"\nInitial b: \"%s\"\n", s, b);

  /**
   * Testing strncpy_ptr
  **/
  printf("\nCopying at most %d characters from b to s...\n", n);
  strncpy_ptr(s, b, n);
  printf("s: \"%s\"\n", s);

  /**
   * Testing strncmp_ptr
  **/
  printf("\nComparing at most %d characters of s to b...", n);
  if (strncmp_ptr(s, b, n) == 0)
  {
    printf("\ns == b\n");
  }
  else
  {
    printf("\ns != b\n");
  }

  /**
   * Testing strncat_ptr
  **/
  printf("\nCopying at most %d characters from b to end of s...\n", n);
  strncat_ptr(s, b, n);
  printf("\ns: \"%s\"\n", s);

  return 0;
}

// Copies no more than n characters of t to s.
void strncpy_ptr(char *s, char *t, int n)
{
  while (n-- && (*s++ = *t++))
    ;
}

// Concatenates n characters of t to end of s.
void strncat_ptr(char *s, char *t, int n)
{
  while (*++s)
    ;

  while (n-- && (*s++ = *t++))
    ;
}

// Compare at most n characters of string s to string t.
// Returns negative, zero, or positive for s < t, s == t or s > t.
int strncmp_ptr(char *s, char *t, int n)
{
  while (--n && *s++ == *t++)
    ;

  return *s - *t;
}
