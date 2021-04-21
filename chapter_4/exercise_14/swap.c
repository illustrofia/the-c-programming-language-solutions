#include <stdio.h>

#define swap(t, x, y) \
  t aux = (x);        \
  (x) = (y);          \
  (y) = aux;

int main(void)
{
  int x, y;
  x = 5;
  y = 10;

  swap(int, x, y);

  printf("x = %d\ny = %d\n", x, y);

  return 0;
}
