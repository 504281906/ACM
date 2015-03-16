#include <cstdio>
#include <algorithm>
#include <iostream>
#include <map> 
using namespace std;
int a[1000010],b[1000010];
int main()
{
	int n,k;
	while (~scanf("%d",&n))
	{
		int f=0; 
		map<int,int> mm;
		map<int,int>::iterator l;
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&k);
			mm[k]++;
			if (mm[k]==(n+1)/2 && f==0)
			{
				printf("%d\n",k);
				f=1;
			}
		} 
	}
	return 0;
}
