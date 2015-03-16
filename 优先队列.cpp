#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include<cstring>
using namespace std;
struct nn
{
	int x,y;
	nn (int a1,int b1):x(a1),y(b1){}
	bool operator <(const nn b) const
	{
		if (x==b.x)
		return y>b.y;
		else 
		return x>b.x;
	}
};
int main()
{
	int i,n,a[100],b[100];
	priority_queue<nn>q;
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
		q.push(nn(a[i],b[i]));
	}
	puts;
	for (i=0;i<n;i++)
	{
		a[i]=q.top().x;
		b[i]=q.top().y;
		q.pop();
		printf("%d %d\n",a[i],b[i]);
	}
	return 0;
}
