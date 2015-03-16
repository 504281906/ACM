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
#define EPS 1e-8
using namespace std;
LL m,a,b,s,t,p;
map<int,int>mb;
map<int,int>ma;
LL KSM(LL a,LL b)
{
	LL s=1,k=a;
	while (b!=0)
	{
		if (b&1) s=s*k%p;
		k=k*k%p;
		b>>=1;
	}
	return s;
}
int main()
{
	while (~scanf("%I64d %I64d %I64d %I64d %I64d %I64d",&m,&a,&b,&s,&t,&p) && m)
	{
		ma.clear();
		mb.clear();
		LL bb=KSM(bb,s-1);
		int k=1;
		LL aa=m%p;
		while (1)
		{
			if (mb[bb] || k>(t-s+1))
				break;
			mb[bb]=1;
			bb=bb*b%p;
			k++;
		}
		int ans;
		k=0;
		while (1)
		{
			if (mb[aa]==1)
			{
				ans=k;
				break;
			}
			if (ma[aa]==1 || (k>t-s+1))
			{
				ans=-1;
				break;
			}
			ma[aa]=1;
			aa=aa*a%p;
			k++;
		}
		if (ans==-1) printf("impossible\n");
		else printf("%d\n",ans);
	}
	return 0;
}
