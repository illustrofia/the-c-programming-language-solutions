// Birth of bitcount()

#include <stdio.h>

int bitcount(unsigned x);

int main(void)
{
    int x = 85;

    printf("%i\n", bitcount(x));

    return 0;
}


int bitcount(unsigned x)
{
    int b = 0;

    while(x > 0)
    {
        x &= (x - 1);
        b++;
    }

    return b;
}

// Observations

// In a two's complement system, x &= (x - 1) deletes
// the rightmost 1-bit in x. This happens because (x - 1)
// means the rightmost 1-bit in x turns into 0, the one
// next to him becomes 1 and the first bit (parity bit)
// also becomes 1. Compared to x with the "&" operator,
// all those changes will result in 0's, which means
// the expression always results in the rightmost 1-bit in
// x becoming 0.

// Knowing this, we can write a faster version of bitcount,
// which doesn't iterate through all of the number's bits,
// but deals with the constantly-deleted rightmost 1-bit.