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
char s[100010];
int dp[200010][30];
int win[200010],lose[200010];
int main()
{
	int n,k,i,j,m,t;
	scanf("%d%d",&n,&k);
	getchar();
	m=0;
	memset(dp,0,sizeof(dp));
	for (i=0;i<n;i++)
	{
		gets(s);
		t=0;
		int l=strlen(s);
		for (j=0;j<l;j++)
		{
			int p=s[j]-'a';
			if (dp[t][p]==0)
				dp[t][p]=++m;
			t=dp[t][p];
		}
	}
	memset(win,0,sizeof(win));
	memset(lose,0,sizeof(lose));
	for (i=m;i>=0;i--)
	{
		int f=1;
		for (j=0;j<26;j++)
		if (dp[i][j])
		{
			f=0;
			break;
		}
		if (f)
		{
			win[i]=0;
			lose[i]=1;
			continue;
		}
		for (j=0;j<26;j++)
			if (dp[i][j])
			{
				if (!win[dp[i][j]])
					win[i]=1;
				if (!lose[dp[i][j]])
					lose[i]=1;
			}
	}
	if (!win[0])
		puts("Second");
	else if (lose[0])
		puts("First");
	else
	{
		// Ö»ÄÜÓ®¡£ 
		if (k % 2==1) puts("First");
		else puts("Second"); 
	}
	return 0;
}
