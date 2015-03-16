#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
struct node
{
	char s[100];
	int l;
}f[100];
bool cmp(node a,node b)
{
	int k=strcmp(a.s,b.s);
	if (k>0) return 0;
	else return 1;

}
int main()
{
	char s1[100];
	int n,m,i,g;
	double k;
	while (~scanf("%d%d%lf",&n,&m,&k))
	{
		int t=0;
		for (i=1;i<=n;i++)
		{
			getchar();
			scanf("%s %d",&s1,&g);
			if (g*k+0.001>=100)
			{
				t++;
				strcpy(f[t].s,s1);
				f[t].l=floor(g*k+0.001);
			}
		}
		for (i=1;i<=m;i++)
		{
			int flag=0;
			getchar();
			scanf("%s",&s1);
			for (int j=1;j<=t;j++)
				if (strcmp(s1,f[j].s)==0)
				{
					flag=1;
					break;
				}
			if (flag==0) 
			{
				strcpy(f[++t].s,s1);
				f[t].l=0;
			}
		}
		sort(f+1,f+1+t,cmp);
		printf("%d\n",t);
		for (i=1;i<=t;i++)
			printf("%s %d\n",f[i].s,f[i].l);
	}
	return 0;
}
