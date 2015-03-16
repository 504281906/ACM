#include <stdio.h>
#include <string.h>
int main()
{
    char s[100001];
    int a[26],i;
    while (gets(s))
    {
        memset(a,0, sizeof(a));
        for (i =0;s[i]!='\0';++i)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
                ++a[s[i] - 'a'];
        }
        for (i = 0; i < 26; ++i)
            printf("%c:%d\n", 'a' + i, a[i]);
        printf("\n");
    }
    return 0;
}
