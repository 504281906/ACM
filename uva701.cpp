#include <cmath>
#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	int n;
	while (~scanf("%d",&n))
	{
		int m=n,k=0;
		while (m) 
		{
			k++;
			m/=10;
		}
		double a,b,c;
		a=log(n*1.0)/log(2.0);
		b=log((n+1)*1.0)/log(2.0);
		c=log(10.0)/log(2.0);
		while (++k)
		{
			double a1,b1;
			a1=a+k*c;
			b1=b+k*c;
			if (ceil(a1)<=floor(b1) && ceil(a1)>3)
			{
				int x=ceil(a1);
				cout<<x<<endl;
				break;
			}
			else 
			if (k==1000000)
			{
				printf("no power of 2\n");
				break;
			}
		}
	}
	return 0;
}
