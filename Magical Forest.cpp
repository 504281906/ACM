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
#define M 500009
using namespace std;
struct node
{
	int x,y,z;
}f[100010];
int h[100015],l[100015],w,cas,n,m,k,x,y,c;
int a[100010],b[100010];
string x1,y1;
int main()
{
	scanf("%d",&w);
	map<int,int>mp1,mp2;
	map<string,int>mz;
	for (cas=1;cas<=w;cas++)
	{
		scanf("%d%d%d",&n,&m,&k);
	 	printf("Case #%d:\n",cas);
		mp1.clear();
		mp2.clear();
		mz.clear();
		for (int i=1;i<=k;i++)
		{
			scanf("%d%d%d",&a[i],&b[i],&c);
			f[i].x=a[i];
			f[i].y=b[i];
			f[i].z=c;
		}
		sort(a+1,a+1+k);
		sort(b+1,b+1+k);
		a[0]=-1;b[0]=-1;
		int t1=1,t2=1;
		for (int i=1;i<=k;i++)
		{
			if (!mp1[a[i]])
			{
				h[t1]=a[i];
				mp1[a[i]]=t1;
				t1++;
			}
			if (!mp2[b[i]])
			{
				l[t2]=b[i];
				mp2[b[i]]=t2;
				t2++;
			}
		}
		for (int i=1;i<=k;i++)
		{
			int s1=mp1[f[i].x];
			int s2=mp2[f[i].y];
			char cc[100];
			sprintf(cc, "%d", h[s1]);
			x1=cc;
			sprintf(cc, "%d", l[s2]);
			y1=cc;
			x1=x1+"!"+y1;
		//cout<<x1<<" "<<c<<endl;
			mz[x1]=f[i].z;
		}
		scanf("%d",&k);
		while (k--)
		{
			scanf("%d%d%d",&c,&x,&y);
			if (c==1)
			{
				x=mp1[x];
				y=mp1[y];
				int t=h[x];
				h[x]=h[y];
				h[y]=t;
				
			}
			else if (c==2)
			{
				x=mp2[x];
				y=mp2[y];
				int t=l[x];
				l[x]=l[y];
				l[y]=t;
				
			}
			else
			{
				char cc[100];
				x=mp1[x];
				y=mp2[y];
				if (x + y)
				{
					sprintf(cc, "%d", h[x]);
					x1=cc;
			
					sprintf(cc, "%d", l[y]);
					y1=cc;
					x1=x1+"!"+y1;
				//	cout<<x1<<endl;
					printf("%d\n",mz[x1]);
				}
				else puts("0");
			}
		}
	}
	return 0;
}
