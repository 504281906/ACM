#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
	int n,i;
	while (~scanf("%d",&n))
	{
		int ans=0;
		int k=sqrt(n);
		for (i=0;i<=k;i++)
		{
			int s=n-i*i;
			if (s==sqrt(s*1.0)*sqrt(s*1.0)) 
			if (i!=0)
				ans+=4;
		}
		printf("%d\n",ans);
	}
	return 0;
}
