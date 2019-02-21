// Birth of setbits()

#include <stdio.h>

int setbits(int x, int p, int n, int y);

int main(void)
{
    int x = 85;
    int y = 12;

    printf("%i\n", setbits(x, 3, 2, y));

    return 0;
}


// Returns x with the n bits that begin at
// position p set to the rightmost n bits of y
int setbits(int x, int p, int n, int y)
{
    int rightmost_n_bits_of_y_in_position_p = (~(~0 << n) & y) << (p + 1 - n);
    int x_with_n_0s_in_position_p = ~(~(~0 << n) << (p + 1 - n)) & x;

    return rightmost_n_bits_of_y_in_position_p | x_with_n_0s_in_position_p;
}