#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
#include <map>
#include <stack>
#include <list>
#include <vector>
using namespace std;
#define LL __int64
int a[10];
int dp(int x)
{
    if (x>31) return 0;
    for (int i=1;i<7;i++)
    {
    	if (a[i] && i+x<=31)
    	{
    		a[i]--;
    		if (dp(i+x)==0)
    		{
    			a[i]++;
    			return 1;
    		}
    		a[i]++;
    	}
    }
    return 0;
}
char s[50];
int main()
{
    int l,i;
    while (~scanf("%s",&s))
	{
		getchar();
        int l=strlen(s);
        for (i=1;i<=6;i++)
            a[i]=4;
        int ans=0;
        for (i=0;i<l;i++)
        {
            int k=s[i]-'0';
            ans+=k;
            a[k]--;
        }
        ans=dp(ans);
        printf("%s",s);
        if (ans) printf(" %c\n",'A'+(l&1));
        else printf(" %c\n",'A'+((l+1)&1));
    }
    return 0;
}
