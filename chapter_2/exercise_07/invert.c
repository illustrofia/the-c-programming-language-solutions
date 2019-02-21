// Birth of invert()

#include <stdio.h>

int invert(int x, int p, int n);

int main(void)
{
    int x = 85;
    
    printf("%i\n", invert(x, 3, 2));

    return 0;
}


// Returns x with the n bits that begin at position p inverted
int invert(int x, int p, int n)
{
    int ones_with_inverted_n_bits_of_x_in_position_p = ~((~(~0 << n) << (p + 1 - n)) & x);
    int x_with_n_bits_in_position_p_equal_to_1 = (~(~0 << n) << (p + 1 - n)) | x;

    return ones_with_inverted_n_bits_of_x_in_position_p & x_with_n_bits_in_position_p_equal_to_1;
}