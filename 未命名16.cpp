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
#define ling 1e-10
using namespace std;
struct point 
{
	int x,y,pos,flag;
};
struct node
{
	int x,y,z,pos,flag;
}f[510];
int ans[510];
point pp[510],p[510];
int sp,n;
double fff(point a,point b,point c)  
{  
    return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);  
}  
double dis(point a,point b)  
{  
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));  
}  
int cmp(point a,point b)  
{  
    double k=fff(p[0],a,b);  
    if (k<-ling)  
        return 0;  
    if (fabs(k)<=ling && dis(p[0],a)-dis(p[0],b)>ling)
        return 0;
    return 1;  
}
int ff(int n)
{
	int i,j=0;
	point k=p[0];
	for (i=1;i<n;i++)
	{
		if (k.y>p[i].y)
		{
			k=p[i];
			j=i;
		}
		else 
		if (k.y==p[i].y && k.x>p[i].x)
		{
			k.x=p[i].x;
			j=i;
		}
	}
	point t;
	t=p[0];
	p[0]=p[j];
	p[j]=t;
	sort(p+1,p+n,cmp);
	pp[0]=p[n-1];
	pp[1]=p[0];
    sp=1;
	int l=1;
	while (l<=n-1)
	{
		double d=fff(pp[sp],pp[sp-1],p[l]);
		if( d < ling)
		{
			sp++;
			pp[sp]=p[l];
			l++;
		}
		else sp--;
	}
}
int main()
{
	int cas=1,i,m;
//	freopen("outt.txt","w",stdout);
	while (~scanf("%d",&m) && m)
	{
		int max=-1;
		for (i=1;i<=m;i++)
		{
			scanf("%d%d%d",&f[i].x,&f[i].y,&f[i].z);
			f[i].pos=i;f[i].flag=0;ans[i]=0;
			if (max<f[i].z)	max=f[i].z;
		}
		printf("Case #%d: ",cas++);
		if (max==0)
		{
			for (i=1;i<=m;i++)
				printf("0");
			cout<<endl;
			continue;
		}
		n=0;
		map<int,int>mp;
		mp.clear();
		memset(pp,0,sizeof(pp));
		for (i=1;i<=m;i++)
			if (max==f[i].z)
			{
				if (mp.find(f[i].x*10000+f[i].y) ==mp.end())
				{
					p[n].x=f[i].x;
					p[n].y=f[i].y;
					p[n].pos=f[i].pos;
					p[n].flag=1;
					mp[f[i].x*10000+f[i].y]=n;
					//vis[f[i].x][f[i].y]=1;
					n++;
				}
				else p[mp[f[i].x*10000+f[i].y]].flag=0;
			}
		if (n>3)
		{
			ff(n);
			for (i=0;i<=n;i++)
				//if (fff(pp[i-1],pp[i],pp[i+1])==0 && i!=sp && i!=1) continue;
				ans[pp[i].pos]=pp[i].flag;
			n=n-2;
			while (n--)
			{
				ans[p[n].pos]=p[n].flag;
				n--;
			}
		}
		else
		{
			for (i=0;i<n;i++)
				ans[p[i].pos]=p[i].flag;
		}
		for (i=1;i<=m;i++)
				printf("%d",ans[i]);
			cout<<endl;
	}
	return 0;
}
