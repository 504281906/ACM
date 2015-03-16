#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
long long a[50010];
int main()
{
	int n,i;
	map<long long,int>m;
	map<long long,int>::iterator it;
	while (~scanf("%d",&n))
	{
		m.clear();
		for (i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			m[a[i]-i]++;
		}
		int s=0;
		long long k;
		for(it=m.begin();it!=m.end();it++)
			if ((*it).second>s) 
			{
				s=(*it).second;
				k=(*it).first;
			}
		printf("%d\n",n-s);
		printf("%lld",k+1);
		for (i=2;i<=n;i++)
			printf(" %lld",k+i);
		printf("\n");
	}
	return 0;
} 
