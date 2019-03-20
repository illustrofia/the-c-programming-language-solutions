// La parole est d'argent, le silence est d'or.

#include <stdio.h>
#include <ctype.h>

#define MAXLEN 100

void getsline(char *s);
int atoi(char *s);
void reverse(char *s);
int strindex(char *s, char *t);
int getop(char *s);

int main(void)
{
    char s[MAXLEN];
    char t[MAXLEN];

    // Testing getsline() and reverse()
    printf("String to reverse: ");
    getsline(s);

    reverse(s);

    printf("Result: %s\n\n", s);

    // Testing atoi()
    printf("String to convert into integer: ");
    getsline(s);

    printf("String \"%s\" into integer: %i\n\n", s, atoi(s));

    // Testing strindex()
    printf("String to search into: ");
    getsline(s);

    printf("String to find: ");
    getsline(t);

    int index = strindex(s, t);

    if (index >= 0)
    {
        printf("String t found in s at index %i.\n\n", index);
    }
    else
    {
        printf("String t not found in s.\n\n");
    }

    return 1;
}

// getsline: gets line of input
void getsline(char *s)
{
    while ((*s = getchar()) != EOF && (*s != '\n'))
    {
        s++;
    }

    *s = '\0';
}

// reverse: reverses string s in place
void reverse(char *s)
{
    char aux;
    char *p = s;

    // Get to end of s, before '\0'
    while (*++s);

    s--;

    // Interchange characters
    while (p < s)
    {
        aux = *s;
        *s-- = *p;
        *p++ = aux;
    }
}

// atoi: converts string of characters into integer
int atoi(char *s)
{
    int n, sign;

    for ( ; isspace(*s); s++);

    sign = (*s == '-') ? -1 : 1;

    if (*s == '+' || *s == '-')
    {
        s++;
    }

    for (n = 0; isdigit(*s); s++)
    {
        n = 10 * n + (*s - '0');
    }

    return sign * n;
}

// strindex: return index of t in s, -1 if none
int strindex(char *s, char *t)
{
    char *t_copy = t, *s_copy = s;
    int index = 0;

    while (*s)
    {
        while (*s_copy++ == *t_copy++ && *t_copy);

        if (!*t_copy)
        {
            return index;
        }

        t_copy = t;
        
        s_copy = ++s;

        index++;
    }

    return -1;
}

/*
// getop: get next operator or numeric operand (for RPC)
int getop(char *s)
{
    int i, c;

    while((s[0] = c = getch()) == ' ' || c == '\t');

    s[1] = '\0';

    if (!isdigit(c) && c != '.')
    {
        return c;
    }

    i = 0;

    if (isdigit(c))
    {
        while (isdigit(s[++i] = c = getch()));
    }

    if (c == '.')
    {
        while (isdigit(s[++i] = c = getch()));
    }
    
    s[i] = '\0';

    if (c != EOF)
    {
        ungetch(c);
    }

    return 0;
}
*/