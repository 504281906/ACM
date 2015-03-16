#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
long long n,ans;
int i,j,k;
int f[100],a[100];
void DFS(int x,int s,int c)
{
	if (c==0)
	{
		long long t=pow(n,1.0/s);
		if (pow(t,s*1.00)>n) t--;
		t--;
		if (t>0)
			ans+=t*(i&1?1:-1);
		return;
	}
	if (x>k) return;
	if (f[x]*s<60) DFS(x+1,f[x]*s,c-1);
	DFS(x+1,s,c);
}
int main()
{
	memset(a,0,sizeof(a));
	memset(f,0,sizeof(f));
	k=0;
	for (i=2;i<60;i++)
	{
		if (!a[i])
			f[++k]=i;
		for (j=1;f[j]!=0 && (n=i*f[j])<=60;j++)
		{
			a[n]=1;
			if (i % f[j]==0) break;
		}
	}
	for (i=1;i<=k;i++)
		if (f[i]>=60) break;
	k=i-1;
	while (scanf("%I64d",&n)==1)
	{
		ans=0;
		for (i=1;i<=3;i++)
			DFS(1,1,i);
		printf("%I64d\n",ans+1);
	}
	return 0;
}
