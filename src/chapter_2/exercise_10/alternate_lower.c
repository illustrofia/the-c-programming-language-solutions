#include <stdio.h>

int alternate_lower(int c);

int main(void)
{
  char a = 'L';

  putchar(alternate_lower(a));
  putchar('\n');

  return 0;
}

int alternate_lower(int c)
{
  return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}
