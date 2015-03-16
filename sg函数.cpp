#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int sg(int s,int c)
{
	int k;
	k=sqrt(s);
	while (k*k+k>=s)
		k--;
	if (c>k)
		return s-c;
	else 
		return sg(k,c);
} 
int main()
{
	int t=0,n,s,c;
	while (~scanf("%d",&n) && n)
	{
		int m=0,i;
		for (i=0;i<n;i++)
		{
			scanf("%d%d",&s,&c);
			if (s==0 || c==0 || s==c)
				continue;
			m^=sg(s,c);
		}
		printf("Case %d:\n",++t);
		if (m==0)
			printf("No\n");
		else 
			printf("Yes\n");
	}
	return 0;
}

