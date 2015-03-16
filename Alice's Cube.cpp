#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int k1=0,k2=0,flag,h;
int b[20];
int a[20][5]={{0},{9,2,3,5},{10,4,6,1},{11,4,7,1},{12,3,8,2},{13,6,7,1},{14,5,8,2},{15,5,8,3},{16,6,7,4},
				  {1,10,11,13},{2,9,12,14},{3,9,12,15},{4,10,11,16},{5,9,14,15},{6,13,10,16},{7,11,13,16},{8,12,14,15}};
int DFS(int t)
{
	int i,j;
	if (t>3) return 1;
	if (k1==0 && k2==8)
	{
		flag=1;
		if (h>t) h=t;
		return 1;
	}
	for (i=1;i<=8;i++)
	{
		if (b[i]==1)
		{
			for (j=0;j<4;j++)
			{
				if (b[a[i][j]]==0)
				{
				int k3=k1,k4=k2;
				b[i]=(b[i]+1) % 2;
				b[a[i][j]]=(b[a[i][j]]+1) % 2;
				if (i<=8)
				{
					if (b[i]==1) k1++;
					else k1--;
				}
				else
				{
					if (b[i]==1) k2++;
					else k2--;
				}
				if (a[i][j]<=8)
				{
					if (b[a[i][j]]==1) k1++;
					else k1--;
				}
				else 
				{
					if (b[a[i][j]]==1) k2++;
					else k2--;
				}
				t++;
				DFS(t);
				t--;
				b[i]=(b[i]+1) % 2;
				b[a[i][j]]=(b[a[i][j]]+1) % 2;
				k1=k3;k2=k4;
				}
			}
		}
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	int k=1;
	while (T--)
	{
		int i;
		k1=0;k2=0;
		for (i=1;i<=16;i++)
		{
			scanf("%d",&b[i]);
			if (i<=8) k1+=b[i];
			else k2+=b[i];
		}
		flag=0;
		h=5;
		printf("Case #%d: ",k++);
		if (k1+k2==8)
		DFS(0);
		if (flag==0) printf("more\n");
		else printf("%d\n",h);
	}
	return 0;
}
