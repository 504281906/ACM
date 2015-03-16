#include <cstdio>
#include <cstring>
int dp[10099];
char s[10099];
void ff()
{
	dp[0]=1;
	dp[1]=1;
	for (int i=2;i<=10090;i++)
		dp[i]=(dp[i-1]+dp[i-2])%10007;
}
int main()
{
	int T,t;
	scanf("%d",&T);
	getchar();
	ff();
	for (int t=1;t<=T;t++)
	{
		gets(s);
		int l=strlen(s);
		dp[0]=1;
		int i,sum=1;
		for (i=0;i<l;i++)
			if (s[i]=='h' && s[i+1]=='e')
			{
				int j=i,k=0;
				while (j<l-1 && s[j]=='h' && s[j+1]=='e')
				{
					k++;
					j+=2;
				}
				sum=(sum*dp[k]) % 10007;
				i=j;
			}
		printf("Case %d: ",t);
		printf("%d\n",sum);
	}
	return 0;
} 
