#include <ctype.h>
#include <stdio.h>
int main(void)
{
    int n, d, i;
    char s[64];
    scanf("%d", &n);
    while (n--)
    {
        gets(s);
        if (s[0]!='_'&&!isalpha(s[0]))
        {
            puts("no");
            continue;
        }
        for (d =i=1;s[i];i++)
        {
            if (!isalnum(s[i])&&s[i] != '_')
            {
                d = 0;
                break;
            }
        }
        puts(d?"yes":"no");
    }
   return 0;
}
