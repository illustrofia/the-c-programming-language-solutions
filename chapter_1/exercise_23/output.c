

#include <stdio.h>

#define IN 1
#define OUT 0
#define INQUOTE -1
#define MAXLINE 1000        

int getsline(char line[], int limit);
void copy(char from[], char to[]);


int main(void)
{
    int length;             
    char line[MAXLINE];     

    int state = OUT;

    int comment_start;
    int comment_end;
    int quote_start;
    
    
    while ((length = getsline(line, MAXLINE)) > 0)
    {
        
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
            else if (state == IN) 
            {
                if (line[i] == '\n' && line[comment_start + 1] == '/')
                {
                    line[comment_start] = '\n';
                    line[comment_start + 1] = '\0';
                    state = OUT;
                    
                    
                    
                    
                }
                else if (line[i] == '\n' && line[comment_start + 1] == '*')
                {
                    line[comment_start] = '\n';
                    line[comment_start + 1] = '\0';
                    comment_start = 0;
                    
                }
                else if (line[i] == '\n' && comment_start == 0)
                {
                    line[comment_start] = '\n';
                    line[comment_start + 1] = '\0';
                    
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

        
        
            printf("%s", line);
        
    }

    return 0;
}



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