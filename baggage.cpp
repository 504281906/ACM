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
using namespace std;
int a[1000];
int n,i;
int main()
{
	while (~scanf("%d",&n))
	{
		memset(a,0,sizeof(a));
		for (i=1;i<=2*n;i++)
			if (i%2) a[i]=2;
				else a[i]=1;
		int begin=-1;
		int end=2*n-2;
		int gg=0,ff=0;
		int t=0;
		while (end>n && begin<n)
		{
			while (!(a[end]==1 && a[end+1]==2 && a[end+2]!=2) && end>n) end--;
			if (end<=n) 
			{gg=1;break;}
			printf("%d to %d\n",end,begin);
			t++;
			a[begin]=1;a[begin+1]=2;
			while (!(a[begin]==2 && a[begin-1]!=2 && a[begin+1]==1) && begin<n) begin++;
			if (begin>=n) {
				ff=1;break;}
			printf("%d to %d\n",begin,end);
			t++;
			a[end]=2;a[end+1]=1;
		}
		if (ff==1)
		{
			while (!(a[begin]==2 && a[begin-1]==2 && a[begin+1]==1)) begin--;
			printf("%d to %d\n",begin,end);
			t++;
			a[end]=2;a[end+1]=1;
		}
		if (gg==1)
		{
			while (!(a[end]==1 && a[end+1]==2 && a[end+2]==2)) end--;
			printf("%d to %d\n",end,begin);
			t++;
			a[begin]=1;a[begin+1]=2;
		}
		int k=-3;
		end=2*n-1;
		begin=0;
		while (end>n && begin<n)
		{
			while (!(a[end]==1 && a[end+1]==1)&&end>n) end--;
			if (end<=n) break;
			printf("%d to %d\n",end,k);
			t++;
			if (t>=n) break;
			k-=2;
			while (!(a[begin]==2 && a[begin+1]==2)&&begin<n) begin++;
			if (begin>=n) break;
			printf("%d to %d\n",begin,end);
			t++;
			if (t>=n) break;
			begin++;
			end--;
		}
	}
	return 0;
}
