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
#define LL __int64
#define EPS 1e-8
#define M 0x7fffffff
using namespace std;
int f[10000],ans;
void go(int a,int m,int b)
{
	int i,k,j;
	int l1=m-a+1;
	int l2=b-m;
	int L[l1+5];
	int R[l2+5];
	for (i=1;i<=l1;i++)
		L[i]=f[a+i-1];
	L[i]=M;
	for (i=1;i<=l2;i++)
		R[i]=f[m+i];
	R[i]=M;
	i=1;j=1;
	for (k=a;k<=b;k++)
		if (L[i]<R[j])
			f[k]=L[i++];
		else
		{
			f[k]=R[j++];
			ans+=l1-i+1;
		}
}
void two(int a,int b)
{
	if (a<b)
	{
		int m=(a+b)/2;
		two(a,m);
		two(m+1,b);
		go(a,m,b);
	}
	return;
}
int main()
{
	int n;
	while (~scanf("%d",&n))
	{
		for (int i=1;i<=n;i++)
			scanf("%d",&f[i]);
		ans=0;
		two(1,n);
		cout<<ans<<endl;
		for (int i=1;i<=n;i++)
			printf("%d ",f[i]) ;
		cout<<endl;
	}
	return 0;
}
