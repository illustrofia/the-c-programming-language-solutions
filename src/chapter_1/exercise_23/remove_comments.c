// Removes comments from a C program

#include <stdio.h>
#define MAXLINE 10000

#define TRUE (1 == 1)
#define FALSE !TRUE

void get_program(char line[], int limit);
void remove_comments(char str[], char str_no_com[]);

int main(void)
{
  char program[MAXLINE];
  char program_no_com[MAXLINE];

  get_program(program, MAXLINE);
  remove_comments(program, program_no_com);

  printf("%s", program_no_com);
}

void get_program(char line[], int limit)
{
  int c, i = 0;

  while (i < limit - 1 && (c = getchar()) != EOF)
  {
    line[i++] = c;
  }

  line[i] = '\0';
}

void remove_comments(char str[], char str_no_com[])
{
  int inline_com = FALSE;
  int block_com = FALSE;
  int in_quote = FALSE;

  int i = 0, j = 0;
  while (str[i] != '\0')
  {
    // If we're inside a quote, copy character
    if (!in_quote && str[i] == '"' && !block_com && !inline_com)
    {
      in_quote = TRUE;
      str_no_com[j++] = str[i++];
    }
    else if (in_quote && str[i] == '"')
    {
      in_quote = FALSE;
      str_no_com[j++] = str[i++];
    }

    // If "we're not inside quote, check if we're not inside a comment
    if (!in_quote)
    {
      if (!block_com && str[i] == '/' && str[i + 1] == '*' && !inline_com)
      {
        block_com = TRUE;
      }

      if (str[i] == '*' && str[i + 1] == '/')
      {
        block_com = FALSE;
        i += 2;
      }

      if (str[i] == '/' && str[i + 1] == '/')
      {
        inline_com = TRUE;
      }

      if (str[i] == '\n')
      {
        inline_com = FALSE;
      }

      // If we're not inside a comment, copy character
      if (!inline_com && !block_com)
      {
        str_no_com[j++] = str[i++];
      }
      else
      {
        i++;
      }
    }
    else // If we're not inside a quote or a comment, copy character
    {
      str_no_com[j++] = str[i++];
    }
  }
}
