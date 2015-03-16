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
int a[40][40],b[40][40];
int main()
{
	int n,i,j;
	while (~scanf("%d",&n) && n)
	{
		for (i=1;i<=n;i++)
			for (j=1;j<=n;j++)
				scanf("%d",&a[i][j]);
		for (i=1;i<=n;i++)
			for (j=1;j<=n;j++)
				scanf("%d",&b[i][j]);
		int max=0,s=0,s1=0,s2=0,s3=0;
		for (i=1;i<=n;i++)
			for (j=1;j<=n;j++)
			{
				if (a[i][j]==b[i][j]) s++;
				if (a[i][j]==b[n-j+1][i]) s1++;
				if (a[i][j]==b[n-i+1][n-j+1]) s2++;
				if (a[i][j]==b[n-j+1][n-i+1]) s3++;	
			}
		if (max<s) max=s;
		if (max<s1) max=s1;
		if (max<s2) max=s2;
		if (max<s3) max=s3;
		cout<<s3<<endl;
	}
	return 0;
}
