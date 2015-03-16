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
typedef struct node
{
	int s;
	struct node *next;
}*List;
List L;
int main()
{
	int n,m,i,cas=1;
	while (~scanf("%d%d",&n,&m))
	{
		List head=new node;
		head->s=0;
		head->next=NULL;
		L=head;
		List end=new node;
		List kkk;
		for (i=1;i<=n;i++)
		{
			node *p;
        	p=(node *)malloc(sizeof(node));
			p->s=i;
			if ((n+2) / 2==i) 
			{
				kkk=L;
				end=p;
			}
			L->next=p;
			L=p;
		}
		L->next=NULL;
		/*while (L!=NULL)
		{
			cout<<L->s;
			L=L->next;
		}*/
		int ff=0;
		while (m--)
		{
			int k,x,y;
			List pr=head,pr1,pr2,nx,ny;
			L=head->next;
			List prr=kkk;
			List L1=end;
			scanf("%d",&k);
			if (k==4)
			{
				ff=ff^1;
				continue;
			}
			if (k==3)
			{
				int x1=1,y1=1;
				scanf("%d%d",&x,&y);
				int h=0;
				while (h!=2)
				{
					if (x1 && L->s==x)
					{
						nx=L;
						h++;
						x1=0;
					}
					else if (y1 && L->s==y)
					{
						y1=0;
						ny=L;
						h++;
					}
					if (x1 && L1->s==x)
					{
						x1=0;
						nx=L1;
						h++;
					}
					else if (y1 && L1->s==y)
					{
						y1=0;
						ny=L1;
						h++;
					}
					pr=L;
					L=L->next;	
					prr=L1;
					L1=L1->next;
				}
				int t=nx->s;
				nx->s=ny->s;
				ny->s=t;
				//continue;
			}
			else
			if ((k==1 && ff==0) || (k==2 && ff==1))
			{
				int x1=1,y1=1;
				scanf("%d%d",&x,&y);
				int h=0;
				while (h!=2)
				{
					if (x1 && L->s==x)
					{
						x1=0;
						nx=L;
						h++;
						pr1=pr;
					}
					else if (y1 && L->s==y)
					{
						y1=0;
						ny=L;
						h++;
						pr2=pr;
					}
					if (x1 && L1->s==x)
					{
						x1=0;
						nx=L1;
						h++;
						pr1=prr;
					}
					else if (y1 && L1->s==y)
					{
						y1=0;
						ny=L1;
						h++;
						pr2=prr;
					}
					pr=L;
					L=L->next;
					prr=L1;
					L1=L1->next;
				}
				if (nx->next!=ny)
				{
					pr1->next=nx->next;
					nx->next=pr2->next;
					pr2->next=nx;
				}
			}
			else
			{
				int x1=1,y1=1;
				scanf("%d%d",&x,&y);
				int h=0;
				while (h!=2)
				{
					if (x1 && L->s==x)
					{
						x1=0;
						nx=L;
						h++;
						pr1=pr;
					}
					else if (y1 && L->s==y)
					{
						y1=0;
						ny=L;
						h++;
						pr2=pr;
					}
					if (x1 && L1->s==x)
					{
						x1=0;
						nx=L1;
						h++;
						pr1=prr;
					}
					else if (y1 && L1->s==y)
					{
						y1=0;
						ny=L1;
						h++;
						pr2=prr;
					}
					pr=L;
					L=L->next;
					prr=L1;
					L1=L1->next;
				}
				pr1->next=nx->next;
				nx->next=ny->next;
				ny->next=nx;
			}
			/*L=head->next;
			while (L!=NULL)
			{
				cout<<L->s;
				L=L->next;
			}
			cout<<endl;*/
		}
		if (ff==1 && n%2==0)
			L=head;
		else
			L=head->next;
		LL ans=0;
		while (L!=NULL)
		{
			ans+=L->s;
			if (L->next==NULL || L->next->next==NULL) break;
			L=L->next->next;
		}
		printf("Case %d: %lld\n",cas++,ans);
	/*	L=head;
		while (L!=NULL)
		{
			List gg=L;
			L=L->next;
			free(gg);
		}*/
	}
	return 0;
}
