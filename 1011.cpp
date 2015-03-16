#include <stdio.h>
#include <algorithm>
#include <string.h>
struct node 
{
	int x,y;
}a[110];
struct node1
{
	int x,y;
}b[110];
int n,m,max;
int vist[110];
int cmp(node1 a,node1 b)
{
	if (a.x==b.x)
		return a.y<b.y;
	return a.x<b.x;
}
void DFS(int k,int d,int s,int f)
{
	if (max<f) max=f;
	for (int i=k;i<n-1;i++)
	{
		if ((b[i].x==d) && (s>=((a[i+1].x+19)/20)) &&(!vist[i+1]))
		{
			s-=(a[i+1].x+19)/20;
			f+=a[i+1].y;
			vist[i+1]=1;
			DFS(k+1,b[i].y,s,f);
			f-=a[i+1].y;
			vist[i+1]=0;
			s+=(a[i+1].x+19)/20; 
		}
		if (b[i].x>d) return;
	}
}
int main()
{
	while (~scanf("%d%d",&n,&m) && (n+m>0))
	{
		memset(vist,0,sizeof(vist));
		for (int i=1;i<=n;i++)
			scanf("%d%d",&a[i].x,&a[i].y);
		for (int i=0;i<n-1;i++)
		{
			scanf("%d%d",&b[i].x,&b[i].y);
			if (b[i].x>b[i].y)
			{
				int t=b[i].x;
				b[i].x=b[i].y;
				b[i].y=t;
			}
		}
		max=0;
		std::sort(b,b+n-1,cmp);
		if (m>=(a[1].x+19)/20)
		{ 
			m-=(a[1].x+19)/20; 
			vist[1]=1;
			DFS(0,1,m,a[1].y);
			printf("%d\n",max);
		}
		else printf("0\n");
	}
	return 0;
}
