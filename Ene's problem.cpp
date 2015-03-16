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
int main()
{
	while (~scanf("%I64d %I64d %I64d %I64d %I64d %I64d",&m,&a,&b,&s,&t,&p) && m)
	{
		ma.clear();
		mb.clear();
		LL k=1;
		LL bb=b%p;
		LL aa=m%p;
		while (1)
		{
			if (mb[bb] || k>t)
				break;
			mb[bb]=k++;
			bb=bb*b%p;
		}
		k--;
		int flag;
		if (t-s+1>=k) 
		{
			flag=1;
			s=1;
			t=k;
		}
		else
		if (k>=t || s>t)
		{
			flag=1;
			s=s%p;
			t=t%p;
		}
		else 
		{
			flag=0;
			int tt=t%p;
			t=s%p;
			s=tt;
		}
		k=0;
		int ans;
		while (1)
		{
			if (flag==1)
			{
				if (s<=mb[aa] && mb[aa]<=t)
				{
					ans=k;
					break;
				}
			}
			else
			{
				if (mb[aa]!=0 && (mb[aa]<s || mb[aa]>t))
				{
					ans=k;
					break;
				}
			}
			if (ma[aa])
			{
				ans=0;
				break;
			}
			ma[aa]=1;
			aa=aa*a%p;
			k++;
		}
		if (ans==0) printf("impossible\n");
		else printf("%d\n",ans);
	}
	return 0;
}
