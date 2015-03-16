#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=310;
const int m=1000000000;
typedef long long LL;
char s[maxn];
int d[maxn][maxn];
int dp(int i,int j)
{
	if (i==j) return 1;
	if (s[i]!=s[j]) return 0;
	int& ans=d[i][j];
	if (ans>=0)  return ans;
	ans=0;
	for (int k=i+2;k<=j;k++)
		ans=(ans+(LL)dp(i+1,k-1)*(LL)dp(k,j)) % m;
	return ans;
}
int main()
{
	while (~scanf("%s",s))
	{
		memset(d,-1,sizeof(d));
		printf("%d\n",dp(0,strlen(s)-1));
	}
	return 0;
}
