// Folds long input lines

#include <stdio.h>

#define MAXLINE 1000 // Maximum input line size

int getsline(char line[], int limit);
void copy(char from[], char to[]);
void fold(char line[], int length, int max_line_length);

int main(void)
{
    char line[MAXLINE];
    int length;

    while ((length = getsline(line, MAXLINE)) > 0)
    {
        fold(line, length, 80);
        printf("%s", line);
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

void fold(char line[], int length, int max_line_length)
{
    if (length - 2 < max_line_length) // Line fold is not necessary
        return;

    int i, j;
    int folded; //Cheks if first search failed

    for (i = max_line_length; i <= length - 2; i += max_line_length)
    {
        folded = 0;
        // Searches for whitespace character in descending order
        for (j = i; j >= 0 && line[j] != '\n'; j--)
        {
            if (line[j] == ' ' || line[i] == '\t')
            {
                line[j] = '\n';
                i = j + 1; // New line starts at position j + 1, rifht after newline character
                folded = 1;
                break;
            }
        }

        // If line was not folded, search the opposite order for whitespace
        if (!folded)
        {
            for (j = i + 1; j++; j <= length - 2)
            {
                if (line[j] == ' ' || line[i] == '\t')
                {
                    line[j] = '\n';
                    i = j;
                    break;
                }
            }
        }
    }
}
