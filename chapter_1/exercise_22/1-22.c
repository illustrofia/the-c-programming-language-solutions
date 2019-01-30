// Needs comments

// Folds long input lines

#include <stdio.h>

#define MAXLINE 1000        // Maximum input line size
#define MAXLENGTH 70        // Maximum line length

int getsline(char line[], int limit);
void copy(char from[], char to[]);
void format(char line[], int length, int limit);

int main(void)
{
    int length;             // Line length
    char line[MAXLINE];     // Input line

    while ((length = getsline(line, MAXLINE)) > 0)
    {
        format(line, length, MAXLENGTH);
        printf("\n%s", line);
    }
    return 0;
}


// Reads a line into s, return length
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

// Formats long lines
void format(char line[], int length, int limit)
{
    int last_blank;
    int j;

    last_blank = 0;
    j = limit - 1;
    while (j > last_blank && j < length)
    {
        if (line[j] == ' ' || line[j] == '\t')
        {
            last_blank = j;
            line[last_blank] = '\n';
            j += limit;
            j++;
        }
        j--;
        if (j == last_blank)
        {
            for (int i = j + 1; i < length; i++)
            {
                if (line[i] == ' ' || line[j] == 't')
                {
                    last_blank = i;
                    line[last_blank] = '\n';
                    j = last_blank + limit;
                    break;
                }
            }
        }
    }
    
}