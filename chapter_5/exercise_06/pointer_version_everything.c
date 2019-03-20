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

    // Testing getop()

    printf("Please type an operand/operator for getop: ");
    int type = getop(s);

    printf("getop type is: %i\n", type);

    printf("s after getop is equal to \"%s\"\n", s);

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

#define NUMBER 0

// getop: get next operator or numeric operand (for RPC)
int getop(char *s)
{
    int c;

    // Skip whitespace
    while((*s = c = getchar()) == ' ' || c == '\t');

    *(s + 1) = '\0';

    // Not a number
    if (!isdigit(c) && c != '.')
    {
        return c;
    }

    // Collect integer part
    if (isdigit(c))
    {
        while (isdigit(*++s = c = getchar()));
    }

    // Collect fractional part
    if (c == '.')
    {
        while (isdigit(*++s = c = getchar()));
    }

    // Push character back to input
    if (c != EOF)
    {
        ungetc(c, stdin);
    }
    
    *s = '\0';

    return NUMBER;
}