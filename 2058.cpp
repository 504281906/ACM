#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n,m,i,l,t=1;
	while (~scanf("%d%d",&n,&m) && (n+m))
	{
		l=sqrt(2*m);
		for (i=l;i>=1;i--)
		{
			int k=2*m;
			if (k % i==0 && (k/i+1-i)%2==0 && (k/i+1-i)/2+i-1<=m)
			{
				k=(k/i+1-i)/2;
				printf("[%d,%d]\n",k,k+i-1);
				//if (i % 2==0) 
				//	printf("[%d,%d]\n",k-(i/2)+1,k+(i/2)-1);
				//else 
				//	printf("[%d,%d]\n",k-(i-1)/2,k+(i-1)/2);
			}
		}
		printf("\n");
	}
	return 0;
}
