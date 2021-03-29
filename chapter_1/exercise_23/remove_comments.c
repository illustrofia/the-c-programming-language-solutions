// Removes comments from a C program

#include <stdio.h>

#define IN 1
#define OUT 0
#define INQUOTE -1
#define MAXLINE 1000        // Maximum input line size

int get_program(char line[], int limit);
void copy(char from[], char to[]);

// Needs comments. Needs formating on that long if condition (line 73, it has a humongous amount of columns)
int main(void)
{
    int length;             // Line length
    char line[MAXLINE];     // Input line

    int state = OUT;

    int comment_start;
    int comment_end;
    int quote_start;
    // int useless line;

    while ((length = getsline(line, MAXLINE)) > 0)
    {
        // useless_line = 0;
        for (int i = 0; i < length; i++)
        {
            if (state == OUT && (line[i] == '"' || line[i] == '\''))
            {
                state = INQUOTE;
                quote_start = i;
            }
            else if (state == INQUOTE && line[i] == line[quote_start])
            {
                state = OUT;
            }
            else if (state == OUT)
            {
                if ((line[i] == '/' && line[i + 1] == '/') || (line[i] == '/' && line[i + 1] == '*'))
                {
                    state = IN;
                    comment_start = i;
                }
            }
            else if (state == IN) // This structure needs a lot of commenting, at least for myself
            {
                if (line[i] == '\n' && line[comment_start + 1] == '/')
                {
                    line[comment_start] = '\n';
                    line[comment_start + 1] = '\0';
                    state = OUT;
                    // if (comment_start == 0)
                    // {
                    //     useless_line++;
                    // }
                }
                else if (line[i] == '\n' && line[comment_start + 1] == '*')
                {
                    line[comment_start] = '\n';
                    line[comment_start + 1] = '\0';
                    comment_start = 0;
                    // useless_line++;
                }
                else if (line[i] == '\n' && comment_start == 0)
                {
                    line[comment_start] = '\n';
                    line[comment_start + 1] = '\0';
                    // useless_line++;
                }
                else if ((line[i] == '*' && line[i + 1] == '/') && !(line[comment_start] == '/' && line[comment_start + 1] == '/'))
                {
                    comment_end = i + 2;
                    for (int j = comment_end; j <= length; j++)
                    {
                        line[comment_start + j - comment_end] = line[j];
                    }
                    state = OUT;
                    length = length - comment_end + comment_start;
                    i = comment_start;
                }
            }
        }

        // if(!useless_line)
        // {
            printf("%s", line);
        // }
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
