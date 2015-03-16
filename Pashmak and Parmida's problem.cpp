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
using namespace std;
int a[1000010],l[1000010],r[1000010],f[1000010],n;
void update(int k,int x)
{
	while (k<=n)
	{
		f[k]+=x;
		k+=k&-k;
	}
	return;
}
LL add(int k)
{
	LL ans=0;
	while (k>0)
	{
		ans+=f[k];
		k-=k&-k;
	}
	return ans;
}
int main()
{
	int i;
	scanf("%d",&n);
	map<int,int>mp1,mp2;
	for (i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		mp1[a[i]]++;
		l[i]=mp1[a[i]];
	}
	for (i=n;i>0;i--)
	{
		mp2[a[i]]++;
		r[i]=mp2[a[i]];
		update(r[i],1);
	}
	LL ans=0;
	for (i=1;i<=n;i++)
	{
		update(r[i],-1);
		ans+=add(l[i]-1);
	}
	cout<<ans<<endl;
	return 0;
}

