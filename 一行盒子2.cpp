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
#define LL long long
#define EPS 1e-8
using namespace std;
struct node
{
	int s;
	int l,r;
}L[100010];
int main()
{
	int n,m,i,cas=1;
	while (~scanf("%d%d",&n,&m))
	{
		L[0].r=1;
		for (i=1;i<=n;i++)
		{
			L[i].l=i-1;
			L[i].r=i+1;
			L[i].s=i;
		}
		/*while (L!=NULL)
		{
			cout<<L.s;
			L=L.next;
		}*/
		int ff=0;
		while (m--)
		{
			int k,x,y;
			scanf("%d",&k);
			if (k==4)
			{
				ff=ff^1;
				continue;
			}
			if (k==3)
			{
				scanf("%d%d",&x,&y);
				if (L[x].r!=y && L[x].l!=y)
				{
				L[L[x].l].r=y;
				L[L[x].r].l=y;
				L[L[y].l].r=x;
				L[L[y].r].l=x;
				int xx=L[x].l,yy=L[x].r;
				L[x].l=L[y].l;
				L[x].r=L[y].r;
				L[y].l=xx;
				L[y].r=yy;
				}
				else if (L[x].r==y)
				{
					L[L[x].l].r=y;
					L[L[y].r].l=x;
					L[y].l=L[x].l;
					L[x].r=L[y].r;
					L[y].r=x;
					L[x].l=y;
				}
				else 
				{
					int q=x;
					x=y;
					y=q;
					L[L[x].l].r=y;
					L[L[y].r].l=x;
					L[y].l=L[x].l;
					L[x].r=L[y].r;
					L[y].r=x;
					L[x].l=y;
				}
			}
			else
			if ((k==1 && ff==0) || (k==2 && ff==1))
			{
				scanf("%d%d",&x,&y);
				L[L[x].l].r=L[x].r;
				L[L[x].r].l=L[x].l;
				L[x].l=L[y].l;
				L[x].r=y;
				L[L[y].l].r=x;
				L[y].l=x;
			}
			else
			{
				scanf("%d%d",&x,&y);
				L[L[x].l].r=L[x].r;
				L[L[x].r].l=L[x].l;
				L[x].l=y;
				L[x].r=L[y].r;
				L[L[y].r].l=x;
				L[y].r=x;
			}
			/*L=head.next;
			while (L!=NULL)
			{
				cout<<L.s;
				L=L.next;
			}
			cout<<endl;*/
		}
		LL ans=0;
		if (ff==1 && n%2==0)
		{
			int tt=n/2;
			int kk=0;
			i=0;
			while (i<tt)
			{
				i++;
				kk=L[L[kk].r].r;
				ans+=kk;
			}
		}
		else
		{
			int tt=(n+1)/2;
			int kk=L[0].r;
			i=0;
			while (i<tt)
			{
				i++;
				ans+=kk;
				kk=L[L[kk].r].r;
			}
		}
		printf("Case %d: %lld\n",cas++,ans);
	}
	return 0;
}
