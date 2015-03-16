#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int a[55][110];
int main()
{
	int i,j,n,t=1,k;
	while (~scanf("%d",&n) && n)
	{
		int flag=1;
		for (i=1;i<=n;i++)
		{
			getchar();
			int f=1;
			char c;
			for (j=1;j<=2*i-1;j++)
			{
				scanf("%c",&a[i][j]);
				if (j==1) {c=a[i][j];continue;}
				if (a[i][j]!=c)
				{
					if (f) 
					{
						f=0;
						c=a[i][j];
					}
					else
						flag=0;
				}
			}
		}
		printf("Puzzle %d\n",t++);
		if (flag) 
		{
			printf("Parts can be separated\n");continue;
		}
		else 
		{
			flag=1;
			for (i=1;i<=n;i++)
			{
				int f=1;
				char c=a[i][2*i-1];
				for (j=i+1;j<=n;j++)
				{
					for (k=i*2;k>=(i-1)*2+1;k--)
					if (c!=a[j][k])
					{
						if (f)
						{
							f=0;
							c=a[j][k];
						}
						else
							flag=0;
					}
				}
			}
			if (flag) 
			{
				printf("Parts can be separated\n");continue;
			}
			else
			{
				flag=1;
				for (i=1;i<=n;i++)
				{
					int f=1;
					char c=a[i][1];
					for (j=i+1;j<=n;j++)
					{
						for (k=(j*2-1)-i*2+1;k<=(j*2-1)-(i-1)*2;k++)
						if (c!=a[j][k])
						{
							if (f)
							{
								f=0;
								c=a[j][k];
							}
							else
								flag=0;
						}
					}
				}
				if (flag) 
				{
					printf("Parts can be separated\n");continue;
				}
				else printf("Parts cannot be separated\n");
			}
		}
	}
	return 0;
} 
