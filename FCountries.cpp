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
using namespace std;
struct node1
{
	int go,v;
};
struct node
{
	int t;
	node1 ff[100];
}f[100010];
int pd(int pos,int j)
{
	int i;
	for (i=1;i<=f[pos].t;i++)
		if (f[pos].ff[i].go==j)
			return i;
	return 0;
}
int main()
{
	int n,m,s,i,j,x,y,z;
	while (~scanf("%d",&n))
	{
		if (n==0) break;
		scanf("%d",&m);
		memset(f,0,sizeof(f));
		for (i=0;i<m;i++)
		{
			scanf("%d%d%d",&x,&y,&z);
			f[x].t++;f[x].ff[f[x].t].go=y;f[x].ff[f[x].t].v=z;
			f[y].t++;f[y].ff[f[y].t].go=x;f[y].ff[f[y].t].v=z;
		}
		while (1)
		{
			int pos=0;
			int flag=0;
			for (s=1;s<=n;s++)
			{
				int max=0x7777777f;
				for (i=1;i<=f[s].t;i++)
				if (max>f[s].ff[i].v)
				{
					max=f[s].ff[i].v;
					pos=f[s].ff[i].go;
				}
				if (pos==0) continue;
				//vis[s][pos]=0;
				for (i=1;i<=n;i++)
				{
					if (pos == i || i==s) continue;
					int k=pd(pos,i);  //后一段第几个 pos k  
					int k2=pd(s,i);   // s到i的第几个 s,k2 
				if (k2 && k /*vis[pos][i]*/ && (f[s].ff[k2].v>max+f[pos].ff[k].v) || (f[s].ff[k2].v==0 && k))
				{
					flag=1;
					if (f[s].ff[k2].v==0 && k)
					{
						f[s].t++;
						f[s].ff[f[s].t].go=i;
						f[s].ff[f[s].t].v=max+f[pos].ff[k].v;
					}
					else
						f[s].ff[k2].v=max+f[pos].ff[k].v;
				}
				}
			}
			if (flag==0) break;
		}
		int q;
		scanf("%d",&q);
		while (q--)
		{
			scanf("%d%d",&x,&y);
			int k=pd(x,y);
			if (k)	printf("%d\n",f[x].ff[k].v);
				else printf("-1\n");
		}
	}
	return 0;
}
