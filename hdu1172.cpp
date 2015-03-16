#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
struct node
{
	int a,b,c;
}p[110];
int pd(int f,node x)
{
	int q[4],w[4];
	q[0]=f % 10;
	q[1]=f %100 /10;
	q[2]=f /100 %10;
	q[3]=f/1000;
	w[0]=x.a % 10;
	w[1]=x.a %100 /10;
	w[2]=x.a /100 %10;
	w[3]=x.a/1000;
	int b1=0,c1=0;
	for (int i=0;i<4;i++)
		if (q[i]==w[i]) c1++;
	int vis[4];
	memset(vis,0,sizeof(vis));
	for (int i=0;i<4;i++)
		for (int j=0;j<4;j++)
		if (q[i]==w[j] && !vis[j])
		{
			b1++;
			vis[j]=1;
			break;
		}
	if (b1==x.b && c1==x.c)return 1;
	else return 0;
}
int main()
{
	int n;
	while (~scanf("%d",&n) && n)
	{
		for (int i=1;i<=n;i++)
			scanf("%d%d%d",&p[i].a,&p[i].b,&p[i].c);
		int ans,s=0;
		for (int i=1000;i<=9999;i++)
		{
			int flag=1;
			for (int j=1;j<=n;j++)
			{
				flag=pd(i,p[j]);
				if (!flag) break;
			}
			if (flag) 
			{
				ans=i;
				s++;
			}
		}
		if (s==1) printf("%d\n",ans);
		else printf("Not sure\n");
	}
	return 0;
} 
