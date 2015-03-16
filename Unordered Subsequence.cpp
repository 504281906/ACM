#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
	int n,i,k,max,min;
	while (~scanf("%d",&n))
	{
		int f1=0,f2=0,ff=0;
		int pos1,pos2;
		for (i=1;i<=n;i++)
		{
			scanf("%d",&k);
			if (i==1) 
			{
				max=k;
				min=k;
			}
			else 
			if (ff==0)
			{
				if (k>max)
				{
					if (f2==0)
					{
						max=k;
						pos1=i;
						f1++;
					}
					else
					{
						pos2=i;
						ff=1;	
					}
				}
				if (k<min)
				{
					if (f1==0)
					{
						min=k;
						pos1=i;
						f2++;
					}
					else
					{
						pos2=i;
						ff=1;
					}
				}
				if ((k>min && f2) || (k<max && f1))
				{
					pos2=i;
					ff=1;
				}
			}
		}
		if (ff)
		printf("3\n1 %d %d\n",pos1,pos2);
		else 
		printf("0\n");
	} 
	return 0;
}

