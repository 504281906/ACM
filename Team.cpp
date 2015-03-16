#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
#include <map>
#include <stack>
#include <list>
#include <vector>
using namespace std;
//#define DEBUG
int main()
{
#ifdef DEBUG
	freopen("cin.txt", "r", stdin);
	freopen("cout.txt", "w", stdout);
#endif
	int n,m,i;
	while (~scanf("%d%d",&n,&m))
	{
		int a,b;
		if (n-m==1 || n==m)
		{
			while (n>0)
			{
				printf("0");
				n--;
				if (m>0)
				printf("1");
				m--;
			}
			printf("\n");
		}
		else
		{
		if ((m/2)-n>2) 
			{printf("-1\n");continue;}
		else
		{
			int k=m/n;
			if (k*n<=m && k==2)
			{
			while (n>0 || m>0)
			{
				if (m>=2) 
				{
					printf("11");
					m-=2;
				}
				else 
				{
					printf("1"); 
					m--;
				}
				if(n>0)
				{
					printf("0");
					n--;
				}
			}
			printf("\n");
			}
			else
			if (k*n>m && k==2)
			{
			while (n>0 || m>0)
			{
				if (n>=1)
				{
					printf("0");
					n--;
				}
				if (m>=2) 
				{
					printf("11");
					m-=2;
				}
				else
				if (m>=1)
				{
					printf("1"); 
					m--;
				}
				
			}
			printf("\n");
			}
			else
			if (k*n<=m && k==1)
			{
			while (n>0 || m>0)
			{
				if (m>=1) 
				{
					printf("1");
					m-=1;
				}
				if(n>0)
				{
					printf("0");
					n--;
				}
			}
			printf("\n");
			}
			else
			if (k*n>m && k==1)
			{
			while (n>0 || m>0)
			{
				if (n>=1)
				{
					printf("0");
					n--;
				}
				if (m>=1) 
				{
					printf("1");
					m-=1;
				}
			}
			printf("\n");
			}
		}
	}
	}
	return 0;
}
