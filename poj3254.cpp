#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;    //1��ʾ��ţ��0��ʾûţ 
const int mod=100000000;
int n,m,l;
int sta[1<<15];
int dp[1<<15][15];      //dp[i][j]��i��״̬��j���ж����� 
int cas[15];
int ok(int x)
{
	if (x & (x<<1)) return 0;  //�жϵ�ǰx״̬�Ƿ����������Ƿ���Ϊ1�� 
	return 1;
}
void cls()
{
	l=0;
	for (int i=0;i<1<<m;i++)
		if (ok(i)) sta[++l]=i;
}
int pd(int x,int k)
{
	if(x & cas[k]) return 0;
	return 1;
}
int main()
{
	int i,j,k;
	scanf("%d%d",&n,&m);
	cls();
	for (i=1;i<=n;i++)
	{
		cas[i]=0;     //��ʾ��i�е���Щλ�ò��ܷ�(ţ) 
		for (j=1;j<=m;j++)
		{
			scanf("%d",&k);
			if (k==0) cas[i]+=1<<(m-j);
		}
	}
	memset(dp,0,sizeof(dp));
	for (i=1;i<=l;i++)         //l��ʾ���е�״̬����(Ҳ����˵û�����ڵ�ţ)
		if (pd(sta[i],1))
			dp[i][1]=1;
	for (i=2;i<=n;i++)
		for (j=1;j<=l;j++)    //��ʾ��i�е�j��״̬ 
		{
			if (!pd(sta[j],i)) continue;
			for (k=1;k<=l;k++)  //��ʾ��i-1�е�k��״̬ 
			{
				if (!pd(sta[k],i-1)) continue;
				if (sta[j] & sta[k]) continue;
				dp[j][i]=(dp[j][i]+dp[k][i-1]) % mod;
			}
		}
	int ans=0;
	for (i=1;i<=l;i++)
		ans=(ans+dp[i][n]) % mod;
	cout<<ans<<endl;
}
