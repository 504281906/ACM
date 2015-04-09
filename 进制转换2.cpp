#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
	int n,m,i;
	int a[1100];
	while (~scanf("%d%d",&n,&m))
	{
		int t=0;
		while (n)
		{
			a[t++]=n % m;
			n/=m;
		}
		t--;
		for (i=t;i>=0;i--)
		{
			if(a[i]>9)
				printf("%c",a[i]-10+'A');
			else 
				printf("%d",a[i]);
		}
		printf("\n");
	} 
	return 0;
}

