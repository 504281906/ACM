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
#define LL __int64
#define EPS 1e-8
using namespace std;
int a[1100][1100];
int main()
{
	int n,d,i,j;
	LL k;
	scanf("%d%I64d%d",&n,&k,&d);
	int flag=0;
	LL p=k;
	for (i=1;i<=d;i++)
	{
		if (p>=n) 
		{
			flag=1;
			break;
		}
		p*=k;
	}
	if (flag==0)
	{
		puts("-1");
		return 0;
	}
	for (i=1;i<=n;i++)
	{
		if (i==1)
		{
			for (j=1;j<=d;j++)
				a[i][j]=1;
			continue;
		}
		for (j=1;j<=d;j++)
			a[i][j]=a[i-1][j];
		j--;
		a[i][j]++;
		while (a[i][j]>k)
		{
			a[i][j]-=k;
			a[i][j-1]++;
			j--;
		}
	}
	for (i=1;i<=d;i++)
	{
		for (j=1;j<=n;j++)
			printf("%d ",a[j][i]);
		cout<<endl;
	}
	return 0;
}
