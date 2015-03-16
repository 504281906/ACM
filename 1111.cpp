#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main()
{
	int n,m,i,x,y;
	while (~scanf("%d%d",&m,&n) && (n+m))
	{
		if (n*m%3!=0) {printf("0\n");continue;}
		x=0;y=0;
		for (i=1;i<=m/3;i++) //竖直的 
		{
			double s=1.0;
			int j=i + m - 3*i; 
			for (int k=1;k<=i;k++,j--)
				s*=(j*1.0/k);
			x+=s;
		}
		for (i=1;i<=n/3;i++) //竖直的 
		{
			double s1=1.0;
			int j=i + n - 3*i; 
			for (int k=1;k<=i;k++,j--)
				s1*=(j*1.0/k);
			y+=s1;
		}
		printf("%d\n",x*y+1);
	}
	return 0;
}
