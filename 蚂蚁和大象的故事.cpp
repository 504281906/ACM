#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <stack>
using namespace std;
int a[1000010];
int b[1000010];
int main()
{
	int n,i;
	while (~scanf("%d",&n))
	{
		for (i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			b[i]=0;
		}
		stack <int>q;
		stack <int>q1;
		q1.push(0);
		q.push(a[0]);
		int t=0;
		for (i=1;i<n;i++)
		{
			int k=q.top();
			if (a[i]>k)
				while (!q.empty() && q.top()<a[i])
				{
					b[q1.top()]=a[i];
					q1.pop();
					q.pop();
				}
			q1.push(i);
			q.push(a[i]);
		}
		for (i=0;i<n;i++)
			printf("%d\n",b[i]);
	} 
	return 0;
}
