// Has problems removing comments with /* */ totems, chec line 30 in ouput file
// Needs comments. Needs formating on that long if condition (line 28, it has a humongous amount of columns)
// Also, I do not understand the problem with handling character constants

// Removes comments from a C program

#include <stdio.h>

#define IN 1
#define OUT 0
#define MAXLINE 1000        // Maximum input line size

int getsline(char line[], int limit);
void copy(char from[], char to[]);

int main(void)
{
    int length;             // Line length
    char line[MAXLINE];     // Input line
    int comment_start, comment_end/*, useless_line*/;
    int state = OUT;
    
    while ((length = getsline(line, MAXLINE)) > 0)
    {
        // useless_line = 0;
        for (int i = 0; i < length; i++)
        {
            if (state == OUT)
            {
                // This condition needs explanations and formating
                if ((/*(line[i - 1] != '"' && line[i - 1] != "'") && */line[i] == '/' && line[i + 1] == '/') || (line[i] == '/' && line[i + 1] == '*'))
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
                else if (line[i] == '*' && line[i + 1] == '/')
                {
                    comment_end = i + 2;
                    for (int j = comment_end; j <= length; j++)
                    {
                        line[j - comment_end] = line[j];
                    }
                    state = OUT;
                    length -= (comment_end + 1);
                    i = 0;
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