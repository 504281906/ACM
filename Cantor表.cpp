#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
	int i,n;
	while(~scanf("%d",&n))
	{
		i=1;
		while (n>i)
		{
			n-=i;
			i++;
		}
		if (i % 2==0) 
			printf("%d/%d\n",n,i-n+1);
		else 
			printf("%d/%d\n",i-n+1,n);
	}
	return 0;
}
