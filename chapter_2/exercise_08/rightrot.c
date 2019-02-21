// Birth of rightrot()

#include <stdio.h>

int rightrot(int x, int n);
int intlength();

int main(void)
{
    int x = 85;

    printf("%i\n%i\n", sizeof(x), rightrot(x, 3));

    return 0;
}


// Returns value of integer x rotated to the right by n bit positions
int rightrot(int x, int n)
{
    int mask_1 = (~(~0 << n) & x) << (sizeof(x) * 8 - 1 - n);
    int mask_2 = (~0 & x) >> n;

    return mask_1 | mask_2;
}