#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
	int i,j,n;
	char c[2];
	int f=0;
	while (~scanf("%d %c %c",&n,&c[0],&c[1]))
	{
		if (f!=0) printf("\n");
		f=1;
		if (n==1) 
		{
			printf("%c\n",c[0]);
			continue;
		}
		if ( ((n+1)/2)%2 == 0 )
		{
			char t=c[0];
			c[0]=c[1];
			c[1]=t;
		}
		for (i=0;i<n;i++)
		{
			int k=0;
			if (i==0 || i==n-1)
			{
				printf(" ");
				for (j=1;j<n-1;j++)
				printf("%c",c[0]);
				printf(" \n");
			}
			else
			{
				int i1=min(i,n-i-1);
				for (j=0;j<i1;j++)
					printf("%c",c[j%2]);
				for (j=i1;j<n-i1;j++)
					printf("%c",c[i1%2]);
				for (j=n-i1;j<n;j++)
					printf("%c",c[j%2]);
				printf("\n");
			}
		}
		getchar();
	}
	return 0;
}

