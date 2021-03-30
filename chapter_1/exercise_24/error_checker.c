// Checks for rudimentary syntax errors

#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define MAXLINE 10000

void get_program(char program[], int limit);
void error_check(char program[]);

int main(void)
{
    char program[MAXLINE];

    get_program(program, MAXLINE);
    error_check(program);
}

// Gets a C program in program[]
void get_program(char program[], int limit)
{
    int c, i = 0;

    while (i < limit - 1 && (c = getchar()) != EOF)
    {
        program[i++] = c;
    }

    program[i++] = '\n';
    program[i] = '\0';
}

// Checks a C program for rudimentary syntax errors
void error_check(char program[])
{
    int single_quotes = 0;
    int double_quotes = 0;

    int line_comment = FALSE;
    int block_comment = FALSE;

    int parantheses = 0;
    int brackets = 0;
    int braces = 0;

    int i = 0;
    while (program[i] != '\0')
    {
        // Check if we're inside quote
        if (!single_quotes && program[i] == "'")
        {
            single_quotes++;
        }
    }
}
