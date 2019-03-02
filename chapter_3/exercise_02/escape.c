// Birth of escape() and unescape()

#include <stdio.h>

#define MAXLEN 100

void escape(char s[], char t[]);
void unescape(char s[], char t[]);

int main(void)
{
    char t[MAXLEN] = "I really love:\n\tchocolate;\n\tmilkshakes.\n";
    char s[MAXLEN];
    char s2[MAXLEN];

    printf("t: %s\n", t);

    escape(s, t);
    printf("s: %s\n", s);

    unescape(s2, s);
    printf("s2: %s\n", s2);

    return 0;
}

void escape(char s[], char t[])
{
    int i, j;

    j = 0;
    for (i = 0; t[i] != '\0'; i++)
    {
        switch (t[i])
        {
            case '\a':
                s[j++] = '\\';
                s[j++] = 'a';
            break;

            case '\b':
                s[j++] = '\\';
                s[j++] = 'b';
            break;
                
            case '\e':
                s[j++] = '\\';
                s[j++] = 'e';
            break;
                
            case '\f':
                s[j++] = '\\';
                s[j++] = 'f';
            break;

            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
            break;

            case '\r':
                s[j++] = '\\';
                s[j++] = 'r';
            break;
                
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
            break;
                
            case '\v':
                s[j++] = '\\';
                s[j++] = 'v';
            break;

            case '\\':
                s[j++] = '\\';
                s[j++] = '\\';
            break;

            case '\'':
                s[j++] = '\\';
                s[j++] = '\'';
            break;
                
            case '\"':
                s[j++] = '\\';
                s[j++] = '\"';
            break;
                
            case '\?':
                s[j++] = '\\';
                s[j++] = '?';
            break;

            default:
                s[j++] = t[i];
            break;
        }
    }

    s[j] = t[i];
}

void unescape (char s[], char t[])
{
    int i, j;

    j = 0;
    for (i = 0; t[i] != '\0'; i++)
    {
        switch (t[i])
        {
            case '\\':
                switch (t[++i])
                {
                    case 'a':
                        s[j++] = '\a';
                    break;

                    case 'b':
                        s[j++] = '\b';
                    break;
                        
                    case 'e':
                        s[j++] = '\e';
                    break;
                        
                    case 'f':
                        s[j++] = '\f';
                    break;

                    case 'n':
                        s[j++] = '\n';
                    break;

                    case 'r':
                        s[j++] = '\r';
                    break;
                        
                    case 't':
                        s[j++] = '\t';
                    break;
                        
                    case 'v':
                        s[j++] = '\v';
                    break;

                    case '\\':
                        s[j++] = '\\';
                    break;

                    case '\'':
                        s[j++] = '\'';
                    break;
                        
                    case '\"':
                        s[j++] = '\"';
                    break;
                        
                    case '?':
                        s[j++] = '\?';
                    break;

                    default:
                        s[j++] = t[i - 1];
                        s[j++] = t[i];
                    break;
                }
            break;

            default:
                s[j++] = t[i];
            break;

        }
    }

    s[j] = t[i];
}