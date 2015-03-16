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
int pd(char a,char b)
{
	if ( (a=='(' && b==')') || (a=='[' && b==']'))
		return 1;
	return 0;
}
int dp[110][110];//从i位到j位最小长度 
int main()
{
	char s[110];
	int T,i,j,k;
	scanf("%d",&T);
	getchar();
	while (T--)
	{
		gets(s);
		int l=strlen(s);
		memset(dp,0,sizeof(dp));
		for (i=0;i<=l;i++)
			dp[i][i]=1;
		 for(i=2;i<=l;i++)
            for(j=i-1;j>=1;j--)
			{
                dp[j][i]=dp[j][i-1]+1;
                for(k=j;k<i;k++)
                    if(pd(s[k-1],s[i-1]))
                        dp[j][i]=min(dp[j][i],dp[j][k-1]+dp[k+1][i-1]);  
            }
        printf("%d\n",dp[1][l]);
	}
	return 0;
}
