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
#define M 0x7fffffff
long long ans;
int f[100000];
void merge(int begin,int m,int end)
{
	int k1=m-begin+1;
	int k2=end-m;
	int L[k1+5];
	int R[k2+5];
	int i,j,k;
	for (i=1;i<=k1;i++)
		L[i]=f[begin+i-1];
	for (i=1;i<=k2;i++)
		R[i]=f[m+i];
	L[k1+1]=M;
	R[k2+1]=M;
	i=1;j=1;
	for (k=begin;k<=end;k++)
	{
		if (L[i]<=R[j])
			f[k]=L[i++];
		else
		{
			f[k]=R[j++];
			ans+=k1-i+1;
		}
	}
}
void two(int a,int b)
{
	if (a<b)
	{
		int m=(a+b)/2;
		two(a,m);
		two(m+1,b);
		merge(a,m,b);
	}
}
int main()
{
	int n,i;
	while (~scanf("%d",&n))
	{
		for (i=1;i<=n;i++)
			scanf("%d",&f[i]);
		ans=0;
		two(1,n);
		printf("%lld\n",ans);
		/*for (i=1;i<=n;i++)
			printf("%d ",f[i]);
		cout<<endl;
		cout<<M<<endl;*/
	}
	return 0;
}
