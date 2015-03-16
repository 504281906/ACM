#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int n,y,m,T,i;
int x[1010],k[1010];
struct node
{
	int id;
	int h;
	double s;
}f[1010];
bool cmp(node a,node b)
{
	if (a.s==b.s) return a.h<b.h;
	return (a.s-b.s>1e-8);
}
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		//memset(k,0,sizeof(k));
		scanf("%d%d%d",&n,&m,&y);
		int n1=n,m1=m;
		for (i=1;i<=n;i++)
		{
			scanf("%d",&x[i]);
			f[i].id=i;
			f[i].h=x[i];
			k[i]=(int)(m*x[i]*1.0/y);
			f[i].s=double(m*x[i]*1.0/y-(int)(m*x[i]*1.0/y));
			m1-=k[i];
		}
		sort(f+1,f+1+n,cmp);
		for (i=1;i<=n1;i++)
		{
			if (m1==0) break;
			k[f[i].id]++;
			m1--;
		}
		printf("%d",k[1]);
		for (i=2;i<=n;i++)
			printf(" %d",k[i]);
		printf("\n");
		if (T) printf("\n");
	}
	return 0;
}
