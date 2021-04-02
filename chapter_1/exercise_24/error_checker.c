// Checks for rudimentary syntax errors

#include <stdio.h>

#define MAXLINE 10000

#define TRUE (1 == 1)
#define FALSE !TRUE

void get_program(char program[], int limit);
void error_check(char program[]);

int main(void)
{
    char program[MAXLINE];

    get_program(program, MAXLINE);
    error_check(program);
}

// Stores C program in program[]
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
    int single_quotes = FALSE;
    int double_quotes = FALSE;

    int line_comment = FALSE;
    int block_comment = FALSE;

    int parantheses = 0;
    int brackets = 0;
    int braces = 0;

    int i = 0;
    while (program[i] != '\0')
    {
        // Check for quotes
        if (!line_comment && !block_comment)
        {
            if (program[i] == '\'' && !single_quotes && !double_quotes)
            {
                single_quotes = TRUE;
            }
            else if (single_quotes && program[i] == '\'' && (program[i - 1] != '\\' || program[i - 2] == '\\'))
            {
                single_quotes = FALSE;
            }

            if (program[i] == '"' && !single_quotes && !double_quotes)
            {
                double_quotes = TRUE;
            }
            else if (double_quotes && program[i] == '"' && (program[i - 1] != '\\' || program[i - 2] == '\\'))
            {
                double_quotes = FALSE;
            }
        }

        // Check for comments
        if (!single_quotes && !double_quotes)
        {
            if (program[i] == '/' && program[i + 1] == '/' && !block_comment)
            {
                line_comment = TRUE;
            }
            else if (line_comment && program[i] == '\n')
            {
                line_comment = FALSE;
            }

            if (program[i] == '/' && program[i + 1] == '*' && !line_comment)
            {
                block_comment = TRUE;
            }
            else if (block_comment && program[i] == '*' && program[i + 1] == '/')
            {
                block_comment = FALSE;
            }
        }

        // Check for parantheses
        if (!line_comment && !block_comment && !single_quotes && !double_quotes)
        {
            if (program[i] == '(')
            {
                parantheses++;
            }
            else if (program[i] == ')')
            {
                parantheses--;
            }

            if (program[i] == '[')
            {
                brackets++;
            }
            else if (program[i] == ']')
            {
                brackets--;
            }

            if (program[i] == '{')
            {
                braces++;
            }
            else if (program[i] == '}')
            {
                braces--;
            }
        }

        i++;
    }

    // Print errors
    if (single_quotes)
    {
        printf("Error: Unbalanced single quotes.\n");
    }

    if (double_quotes)
    {
        printf("Error: Unbalanced double quotes.\n");
    }

    if (line_comment)
    {
        printf("Error: Unclosed line comment.\n");
    }

    if (block_comment)
    {
        printf("Error: Unclosed block comment.\n");
    }

    if (parantheses)
    {
        printf("Error: Unbalanced parantheses.\n");
    }

    if (brackets)
    {
        printf("Error: Unbalanced brackets.\n");
    }

    if (braces)
    {
        printf("Error: Unbalanced braces.\n");
    }
}
