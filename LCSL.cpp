#include <bits/stdc++.h>
using namespace std;
#define max(a,b) a>b?a:b
#define min(a,b) a>b?b:a
int dp[10010][10010];
char s1[10010],s2[10010];
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
			if (s1[i-1]==s2[j-1])
				dp[i][j]=dp[i-1][j-1]+1;
			else
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	return dp[l1][l2];
}
int LCS(int l1,int l2)
{
	int i,j;
	int l=min(l1,l2);
	l++;
	while (l--)
	{
		for (i=0;i<=l1-l;i++)
		{
			char s[10010];
			//memset(s,NULL,sizeof(s));
			strncpy(s,s1+i,l);
			s[l]='\0';
			char *p;
			p=strstr(s2,s);
			if (p!=NULL)
			{
				strncpy(s,p,l);
				cout<<s<<endl;
				return 1;
			}
		}
		for (i=0;i<=l2-l;i++)
		{
			char s[10010];
			//memset(s,NULL,sizeof(s));
			strncpy(s,s2+i,l);
			s[l]='\0';
			char *p=strstr(s1,s);
			if (p!=NULL)
			{
				strncpy(s,p,l);
				cout<<s<<endl;
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
	while (~scanf("%s %s",&s1,&s2))
	{
		int l1=strlen(s1);
		int l2=strlen(s2);
		cout<<LCSL(l1,l2)<<endl;
		if (LCS(l1,l2)==0)
			printf("Can't find\n");
	}
	return 0;
}
