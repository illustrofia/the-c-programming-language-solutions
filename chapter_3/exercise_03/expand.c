#include <stdio.h>
#include <ctype.h>

#define MAXLEN 100

int getsline(char s[], int lim);
void expand(char s1[], char s2[]);

int main(void)
{
  char s1[MAXLEN];
  char s2[2 * MAXLEN];

  while (getsline(s1, MAXLEN) != 0)
  {
    expand(s1, s2);
    printf("%s\n", s2);
  }

  return 0;
}

int getsline(char s[], int lim)
{
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
  {
    s[i] = c;
  }

  if (c == '\n')
  {
    s[i] = c;
    i++;
  }

  s[i] = '\0';

  return i;
}

void expand(char s1[], char s2[])
{
  int i, j, k;

  for (i = 0, j = 0; s1[i] != '\0'; i++, j++)
  {
    if (s1[i] == '-' && s1[i - 1] < s1[i + 1])
    {
      if (isalpha(s1[i - 1]) && isalpha(s1[i + 1]))
      {
        if ((isupper(s1[i - 1]) && isupper(s1[i + 1])) || (islower(s1[i - 1]) && islower(s1[i + 1])))
        {
          for (k = s1[i - 1] + 1; k < s1[i + 1]; k++)
          {
            s2[j++] = k;
          }

          i++;
        }
      }
      else if (isdigit(s1[i - 1]) && isdigit(s1[i + 1]))
      {
        for (k = s1[i - 1] + 1; k < s1[i + 1] && isdigit(k); k++)
        {
          s2[j++] = k;
        }

        i++;
      }
    }

    s2[j] = s1[i];
  }

  s2[j] = '\0';
}

/**
 * for each character of the line
 * if character is equal to '-'
 * if character before is smaller than character after
 *    if characters before and after are letters
 *      for j = character before; j <= character after; j++
 *        print character to s2
 *    else if character before and after are numbers
 *      for j = character before; j <= character after; j++
 *        print character to s2
**/
