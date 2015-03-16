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
int n,m,a;
int pd(int n,int m)
{
	long long s=1;
	for (int i=1;i<=m;i++)
	{	
		s=s*n;
		if (s>=a) return 1;
	}
	return 0;	
}
int f;
int DFS(int n,int m,int t)
{
	int f1,f2,h1,h2;
	h1=pd(n+1,m);
	h2=pd(n,m+1);
	if (h1 && h2) 
	{
		if (t==1) return 1;
		else return 0;
	}
	if (h1) 
	{
		if (t==1) f1=1;
		else f1=0;
	}
	else f1=DFS(n+1,m,(t+1)%2);
	if (h2)
	{
		if (t==1) f2=1;
		else f2=0;
	}
	else f2=DFS(n,m+1,(t+1)%2);
	if (t==0)
	if (f1+f2) return 1;
	else return 0;
	if (t==1)
	{
		if (f1+f2==2) return 1;
		else return 0;
	}
}
int main()
{
	while (~scanf("%d%d%d",&n,&m,&a))
	{
	if (n==1) 
	{
		int tt=0,flag=0;
		while (pd(2,m)==0 && !pd(n,m+1))
		{
				if (DFS(2,m,0)==0) 
				{
					if (tt==0)
						printf("win\n");
					else printf("lose\n");
					flag=1;
					break;
				}
				else m++;
				tt=(tt+1)%2;
		}
		if (flag==0) printf("draw\n");
	}
	else
    {
    	if (DFS(n,m,0)) printf("win\n");
		else printf("lose\n");
	}
	}
	return 0;
}
