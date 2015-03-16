#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int a[100010],b[100010],vis[100010];
int h,f;
int ff(int wz,int x)
{
	if (f) return f;
	if (f==-1) return 0;
	if (a[wz-1]+a[wz+1]+x>b[wz]) {f=-1;return 0;}
	if (a[wz-1]!=-1 && a[wz+1]!=1 && a[wz-1]+a[wz+1]+x==b[wz]) {f=1;return f;}
	if (a[wz-1]!=-1 && a[wz+1]==-1)	
	{
		int t=a[wz];
		a[wz]=x;
		ff(wz+1,b[wz]-a[wz-1]-x);
		a[wz]=t;
		if (f) return f;
	}
	if (a[wz-1]==-1 && a[wz+1]!=-1)
	{
		int t=a[wz];
		a[wz]=x;
		ff(wz-1,b[wz]-a[wz+1]-x);
		a[wz]=t;
		if (f) return f;
	}
	if (a[wz-1]==-1 && a[wz+1]==-1)
	{
		for (int i=0;i<=b[wz]-x;i++)
		{
			f=0;
			int t=a[wz];
			a[wz]=x;
			ff(wz-1,i);
			if (f==-1) 
			{
				a[wz]=t;
				continue;
			}
			f=0;
			ff(wz+1,b[wz]-x-i);
			if (f) 
			{
				a[wz]=t;
				break;
			}
			a[wz]=t;
		}
	}
	return f;
}
int main()
{
	int q,n,i,m;
	while (~scanf("%d",&n))
	{
		for (i=0;i<n;i++)
			scanf("%d",&a[i]);
		a[-1]=0;a[n]=0;
		for (i=0;i<n;i++)
			scanf("%d",&b[i]);
		scanf("%d",&m);
		while (m--)
		{
			scanf("%d",&q);
			if (a[q]!=-1) cout<<a[q]<<endl;
			else
			{
				for (i=b[q];i>=0;i--)
				{
					f=0;
					h=ff(q,i);
					if (h==-1) continue;
					if (h) {cout<<i<<endl; break;}
				}
			}
		}
	}
	return 0;
}
