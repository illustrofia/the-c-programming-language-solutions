// Checks for rudimentary syntax errors

#include <stdio.h>

#define IN 1
#define OUT 0
#define INQUOTE -1
#define MAXLINE 1000        // Maximum input line size

int getsline(char line[], int limit);
void copy(char from[], char to[]);

int main(void)
{
    char line[MAXLINE];     // Input line
    int length;             // Line length
    int line_counter;

    int state;
    int quote_start;
    int comment_start;

    int parantheses[10];
    int p;
    int brackets[10];
    int brk;
    int braces[10];
    int brc;
    int squotes[10];
    int sq;
    int dquotes[10];
    int dq;
    int comments;

    p = 0;
    brk = 0;
    brc = 0;
    sq = 0;
    dq = 0;
    comments = 0;

    for (int i = 0; i < 10; i++)
    {
        parantheses[i] = 0;
        brackets[i] = 0;
        braces[i] = 0;
        squotes[i] = 0;
        dquotes[i] = 0;
    }

    state = 0;
    line_counter = 0;
    while ((length = getsline(line, MAXLINE)) > 0)
    {
        line_counter++;
        for (int i = 0; i < length; i++)
        {
            if (state == OUT)
            {
                if ((line[i] == '/' && line[i + 1] == '/') || (line[i] == '/' && line[i + 1] == '*'))
                {
                    state = IN;
                    comment_start = i;

                    comments = line_counter;
                }
                else if (line[i] == '"' || line[i] == '\'')
                {
                    state = INQUOTE;
                    quote_start = i;

                    if (line[i] == '"')
                    {
                        dquotes[dq] = line_counter;
                        dq++;
                    }
                    else if (line[i] == '\'')
                    {
                        squotes[sq] = line_counter;
                        sq++;
                    }
                }
                else if (line[i] == '{')
                {
                    braces[brc] = line_counter;
                    brc++;
                }
                else if (line[i] == '}')
                {
                    brc--;
                    braces[brc] = 0;
                }
                else if (line[i] == '[')
                {
                    brackets[brk] = line_counter;
                    brk++;
                }
                else if (line[i] == ']')
                {
                    brk--;
                    brackets[brk] = 0;
                }
                else if (line[i] == '(')
                {
                    parantheses[p] = line_counter;
                    p++;
                }
                else if (line[i] == ')')
                {
                    p--;
                    parantheses[p] = 0;
                }
            }
            else if (state == INQUOTE && line[i] == line[quote_start] && (line[i - 1] != '\\' || line[i - 2] == '\\'))
            {
                state = OUT;

                if (line[i] == '"')
                {
                    dq--;
                    dquotes[dq] = 0;
                }
                else if (line[i] == '\'')
                {
                    sq--;
                    squotes[sq] = 0;
                }
            }
            else if (state == IN)
            {
                if (line[i] == '\n' && comment_start >= 0 && line[comment_start + 1] == '/')
                {
                    state = OUT;
                    
                    comments = 0;
                }
                else if ((line[i] == '*' && line[i + 1] == '/') && comment_start == -1)
                {
                    state = OUT;
                    
                    comments = 0;
                }
                else if (line[i] == '\n' && comment_start >= 0 && line[comment_start + 1] == '*')
                {
                    comment_start = -1;
                }
            }
        }
    }

    if (comments)
    {
        printf("Unclosed comment starting at line %i\n\n", comments);
    }

    // Prints error messages
    for (int i = 0; i < 10; i++)
    {
        if (squotes[i])
        {
            printf("Unclosed single quote starting at line %i\n\n", squotes[i]);
        }
        if (dquotes[i])
        {
            printf("Unclosed double quote starting at line %i\n\n", dquotes[i]);
        }
        if (parantheses[i])
        {
            printf("Unclosed parantheses starting at line %i\n\n", parantheses[i]);
        }
        if (brackets[i])
        {
            printf("Unclosed brackets starting at line %i\n\n", brackets[i]);
        }
        if (braces[i])
        {
            printf("Unclosed curly braces starting at line %i\n\n", braces[i]);
        }
    }

    return 0;
}

// Reads a line into s, returns length
int getsline(char s[], int limit)
{
    int c, i;

    for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; i++)
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