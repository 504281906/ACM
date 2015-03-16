#include<cstdio>
#include<cstring>
#include <queue>
#include<iostream>
//#include <stdlib.h>
#include<algorithm>
using namespace std;
int n; 
int a[755][755];
struct node
{
	int sum,last;
	node (int a,int b):sum(a),last(b){} 
	bool operator <(const node a)const 
	{
		return sum>a.sum;
	} 
};
void ff(int *a,int *b)
{
	priority_queue<node>que;
	for (int i=0;i<n;i++)
		que.push(node(a[i]+b[0],0));
	for (int i=0;i<n;i++)
	{
		node k=que.top();
		que.pop();
		a[i]=k.sum;
		k.sum=k.sum-b[k.last]+b[++k.last];
		que.push(k); 
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
			ff(a[0],a[i]);
		for(int i=0;i<n;i++)
	    	printf("%d%c",a[0][i],i==n-1?'\n':' ');
	} 
	return 0;
} 
