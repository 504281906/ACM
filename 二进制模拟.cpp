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
int main()
{
	int n,i,j;
	int a[1000];
	while (~scanf("%d",&n))
	{
		int m=1<<n;
		cout<<m<<endl;
		for (i=1;i<=m;i++)
		{
			int k=0;
			for (j=0;j<n;j++)
			{
				a[j]=0;
				if (i & (1<<j))
				{
					a[j]=1;
					k++;
				}
			}
			for (j=0;j<n;j++)
				printf("%d ",a[j]);
			cout<<endl;
		}
	}
	return 0;
}
