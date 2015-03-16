#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#define LL __int64
#define EPS 1e-8
using namespace std;
struct node
{
	int sum,k;
	node (int a,int b):sum(a),k(b){}
	bool operator <(node a)const
	{
		return sum>a.sum;
	}
};
int a[800][900],n;
void add(int *a,int *b)
{
	priority_queue<node>q;
	for (int i=0;i<n;i++)
		q.push(node(a[i]+b[0],0));
	for (int i=0;i<n;i++)
	{
		node s=q.top();
		q.pop();
		a[i]=s.sum;
		s.sum=s.sum-b[s.k]+b[++s.k];
		q.push(s);
	}
}
int main()
{
	int i,j;
	while (~scanf("%d",&n))
	{
		for (i=0;i<n;i++)
		{
			for (j=0;j<n;j++)
				scanf("%d",&a[i][j]);
			sort(a[i],a[i]+n);
		}
		for (i=1;i<n;i++)
			add(a[0],a[i]);
		for (i=0;i<n-1;i++)
			printf("%d ",a[0][i]);
		printf("%d\n",a[0][n-1]);
	}
	return 0;
}
