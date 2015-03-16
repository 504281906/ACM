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
#include <ctime>
#define LL __int64
#define eps 1e-8
#define maxn 320010
using namespace std;
int c[maxn+10];
int ans[maxn+10];
int lowbit(int x)
{
	return x&(-x);
}
void add(int i)
{
	while (i<maxn)
	{
		c[i]++;
		i+=lowbit(i);
	}
}
int sum(int i)
{
	int k=0;
	while (i>0)
	{
		k+=c[i];
		i-=lowbit(i);
	}
	return k;
}
int n,i,x,y;
int main()
{
	cin>>n;
	for (i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		x++;
		ans[sum(x)]++;
		add(x);
	}
	for (i=0;i<n;i++)
		cout<<ans[i]<<endl;
	return 0;
}
