#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
struct node 
{
	int id;
	int s,b;
}a[100010];
struct node1
{
	int id;
	int s;
}c[100010],c1[100010];
bool cmp(node x,node y)
{
	if (x.s==y.s)
		return x.b<y.b;
	return x.s<y.s;
}
bool cmp1(node x,node y)
{
	if (x.b==y.b)
		return x.s<y.s;
	return x.b<y.b;
}
int main()
{
	int T,n,i;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (i=1;i<=n;i++)
		{
			a[i].id=i;
			scanf("%d%d",&a[i].s,&a[i].b);
		}
		sort(a+1,a+n+1,cmp);
		c[1].s=a[1].b;
		c[1].id=a[1].id;
		int top=1;
		int k=1;
		for (i=2;i<=n;i++)
		{
			if (a[i].s>a[k].s)
			{
				if (a[i].b>c[top].s)
				{
					c[++top].s=a[i].b;
					k=i;
					c[top].id=a[i].id;
				}
				else
				{
					int low=1,high=top,mid;
					while (low<=high)
					{
						mid=(low+high)/2;
						if (a[i].b>c[mid].s)
							low=mid+1;
						else high=mid-1;
					}
						if (a[i].b<c[low].s)
						{
						c[low].id=a[i].id;
						c[low].s=a[i].b;
					}
				}
			}
		}
		sort(a+1,a+n+1,cmp1);
		c1[1].s=a[1].s;
		c1[1].id=a[1].id;
		int top1=1;
		k=1;
		for (i=2;i<=n;i++)
		{
			if (a[i].b>a[k].b)
			{
				if (a[i].s>c1[top1].s)
				{
					c1[++top1].s=a[i].s;
					k=i;
					c1[top1].id=a[i].id;
				}
				else
				{
					int low=1,high=top1,mid;
					while (low<=high)
					{
						mid=(low+high)/2;
						if (a[i].s>c1[mid].s)
							low=mid+1;
						else high=mid-1;
					}
						if (a[i].s<c1[low].s)
						{
						c1[low].id=a[i].id;
						c1[low].s=a[i].s;
						}
				}
			}
		}
		if (top>=top1)
		{
			cout<<top<<endl<<c[1].id;
			for (i=2;i<=top;i++)
				cout<<" "<<c[i].id;
		}
		else 
		{
			cout<<top1<<endl<<c1[1].id;
			for (i=2;i<=top1;i++)
				cout<<" "<<c1[i].id;
		}
		cout<<endl;
		if (T) cout<<endl;
	} 
	return 0;
}
