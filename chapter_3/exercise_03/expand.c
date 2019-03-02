// Birth of expand()

#include <stdio.h>

#include <string.h>
#include <ctype.h>

#define MAXLEN 100
#define DOUBLE_MAXLEN 200

void expand(char s1[], char s2[]);
int getsline(char s[], int lim);

int main(void)
{
    char s1[MAXLEN];
    char s2[DOUBLE_MAXLEN];

    getsline(s1, MAXLEN);
    
    expand(s1, s2);

    printf("%s\n", s2);

    return 0;
}

void expand(char s1[], char s2[])
{
    int i, j;

    for (i = j = 0; i <= strlen(s1); i++)
    {
        if (isalpha(s1[i]) && islower(s1[i]) && isalpha(s1[i + 2]) && islower(s1[i + 2]) && s1[i + 1] == '-' && s1[i] < s1[i + 2])
        {
            s2[j] = s1[i];
            for (int k = 1; k < s1[i] - s1[i + 2]; k++)
            {
                s2[j++] = s1[i] + k;
            }

            i++;
        }
        else if (isalpha(s1[i]) && isupper(s1[i]) && isalpha(s1[i + 2]) && isupper(s1[i + 2]) && s1[i + 1] == '-' && s1[i] < s1[i + 2])
        {
            s2[j] = s1[i];
            for (int k = 1; k < s1[i] - s1[i + 2]; k++)
            {
                s2[j++] = s1[i] + k;
            }

            i++;
        }
        else if (isdigit(s1[i]) && isdigit(s1[i + 2]) && s1[i + 1] == '-' && s1[i] < s1[i + 2])
        {
            s2[j] = s1[i];
            for (int k = 1; k < s1[i] - s1[i + 2]; k++)
            {
                s2[j++] = s1[i] + k;
            }

            i++;
        }
        else
        {
            s2[j++] = s1[i];
        }
    }
}

int getsline(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
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