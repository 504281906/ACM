#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
using namespace std;
const int MAXN = 1000000 + 11;
char s[MAXN];
char p[MAXN];
int next[MAXN];
void getnext(char *pat)
{  
    memset(next, 0, sizeof(next));
    int i = 0;  
    int j = -1;  
    int len = strlen(pat);  
    next[0] = -1;  
    while (i < len)  
    {
        if (j == -1 || pat[j] == pat[i])
        {
            i++;
            j++;
            next[i] = j;
        }
        else  
        {
            j = next[j];
        }
    }
}
void print()
{
    int len = strlen(s);
    for (int i = 0; i <= len; i++)
        printf("next[%d] = %d\n", i, next[i]);
}
int KMP(char *str, char *pat)  
{  
    int j = 0;
    int i = 0;  
    int len_str = strlen(str);  
    int len_pat = strlen(pat);  
    int num = 0;  
    while (i < len_str)
    {
        if (j == -1 || pat[j] == str[i])  
        {  
            i++; 
            j++;  
        }  
        else  
            j = next[j];  
        if (j == len_pat)  
        {  
            num++;  
            j = next[j];  
        }
    }  
    return num;  
}
int main()
{
    int N;
    while (scanf("%d", &N) != EOF)
    {
        for (int i = 0; i < N; i++)
        {
            scanf("%s", s);
            getnext(s);
            int len = strlen(s);
            int ans = 0;
            for (int i = 0; i < len / 3; i++)
                if (s[i] == s[len - 1])
                {
                    int nn = len - 1;
                    while (next[nn] != i && next[nn] != -1)
                        nn = next[nn];
                    if (next[nn] == i)
                    {
                        for (int k = i + 1 + i ; k < len - 1 - i; k++)
                        {
                            int kk = k;
                            while (next[kk] != i && next[kk] != -1)
                                kk = next[kk];
                            if (next[kk] == i)
                                ans = i + 1;
                        }
                    }
                }
            printf("%d\n", ans);
        }
	}
	return 0;
}
