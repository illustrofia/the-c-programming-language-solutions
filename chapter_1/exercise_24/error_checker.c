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

        /**
         *
         * COMMENTS
         *
         **/

        // start line comment
        if (program[i] == '/' && program[i + 1] == '/' && !block_comment && !single_quotes && !double_quotes)
        {
            line_comment = TRUE;
        }

        // end line comment
        if (program[i] == '\n')
        {
            line_comment = FALSE;
        }

        // start block comment
        if (program[i] == '/' && program[i + 1] == '*' && !line_comment && !single_quotes && !double_quotes)
        {
            block_comment = TRUE;
        }

        // end block comment
        if (block_comment && program[i] == '*' && program[i + 1] == '/')
        {
            block_comment = FALSE;
        }

        /**
         *
         * QUOTES
         *
         **/

        // start single quotes
        if (!single_quotes && program[i] == '\'' && program[i] != '\\' && !line_comment && !block_comment && !double_quotes)
        {
            single_quotes++;
        }
        // end single quotes
        if (single_quotes && program[i] == '\'' && program[i - 1] != '\\' && !line_comment && !block_comment)
        {
            single_quotes--;
        }

        // start double quotes
        if (!double_quotes && program[i] == '"' && !line_comment && !block_comment && !single_quotes)
        {
            double_quotes++;
        }
        // end double quotes
        if (double_quotes && program[i] == '"' && program[i - 1] != '\\' && !line_comment && !block_comment)
        {
            double_quotes--;
        }

        /**
         *
         * PARANTHESES
         *
         **/

        // increment parantheses
        if (program[i] == '(' && !line_comment && !block_comment && !single_quotes && !double_quotes)
        {
            parantheses++;
        }
        // decrement parantheses
        if (program[i] == ')' && !line_comment && !block_comment && !single_quotes && !double_quotes)
        {
            parantheses--;
        }

        // increment brackets
        if (program[i] == '[' && !line_comment && !block_comment && !single_quotes && !double_quotes)
        {
            brackets++;
        }
        // decrement brackets
        if (program[i] == ']' && !line_comment && !block_comment && !single_quotes && !double_quotes)
        {
            brackets--;
        }

        // increment braces
        if (program[i] == '{' && !line_comment && !block_comment && !single_quotes && !double_quotes)
        {
            braces++;
        }
        // decrement braces
        if (program[i] == '}' && !line_comment && !block_comment && !single_quotes && !double_quotes)
        {
            braces--;
        }

        i++;
    }

    /**
     *
     * Check for errors
     *
     **/

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
