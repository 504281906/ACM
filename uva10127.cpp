#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main()
{
	int n;
	while (~scanf("%d",&n))
	{
		int m=n,t=0,x=0;
		while (m)
		{
			x=x*10+1;
			m/=10;
			t++;
		}
		while (x % n)
		{
			t++;
			x%=n;
			x=x*10+1;
		}
		printf("%d\n",t);
	}
	return 0;
}
