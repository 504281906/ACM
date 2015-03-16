#include <bits/stdc++.h>
using namespace std;
#define max(a,b) a>b?a:b
int dp[10010][10010];
char s1[10010][10010];
int LCSL(int l1,int l2)
{
	int i,j;
	int l=max(l1,l2);
	for (i=1;i<=l;i++)
	{
		dp[0][i]=0;
		dp[i][0]=0;
	}
	for (i=1;i<=l1;i++)
		for (j=1;j<=l2;j++)
		{
			if (s1[i]==s2[j])
				dp[i][j]=dp[i-1][j-1]+1;
			else
				dp[i][j]=max(dp[i-1][j],dp[i][j]);
		}
	return dp[l1][l2];
}
int main()
{
	while (~scanf("%s %s",&s1,&s2))
	{
		int l1=strlen(s1);
		int l2=strlen(s2);
		cout<<LCSL(l1,l2)<<endl;
	}
	return 0;
}
