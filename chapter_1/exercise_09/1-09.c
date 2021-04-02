// Replaces each string of one or more blanks by a single blank

#include <stdio.h>

int main(void)
{
  // Variables for a character and the previous one
  int c, prev_c;

  // Prints first character of the input
  // Assignment to prev_c for comparison to c in while loop below
  putchar(prev_c = getchar());

  while ((c = getchar()) != EOF)
  {
    // If the current character and the previous one are not both blanks
    if (!(c == ' ' && prev_c == ' '))
    {
      putchar(c);
    }

    prev_c = c;
  }
}

// Observations

// Although the condition inside the if structure
// may not be the most compact, it is more readable
// for most people.
