#include <cstdio>
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
map< int, int > mp;
int find(int x)
{
	int a,b,n;
	char s[10];
	sprintf(s,"%d",x);
	n=strlen(s);
	for (int i=0; i<n; i++)
		for (int j=i+1; j<n; j++)
		if (s[i] > s[j])
		{
			char t=s[i];
			s[i]=s[j];
			s[j]=t;
		}
	sscanf(s,"%d",&b);
	for (int i=0; i<n/2; i++)
	{
		char t=s[i];
		s[i]=s[n-i-1];
		s[n-i-1]=t;
	}
	sscanf(s,"%d",&a);
	return a-b;
}
int main()
{
#ifdef DEBUG
	freopen("cin.txt", "r", stdin);
	freopen("cout.txt", "w", stdout);
#endif
	int x;
	while (~scanf("%d",&x))
	{
		printf("%d",x);
		int f=1;
		mp.clear();
		while (1)
		{
			int k=find(x);
			if (mp[k]==1) break;
			else 
			{
				printf("->%d",k);
				mp[k]=1;
				x=k;
				f++;
			}
		}
		printf("\n%d\n",f);
	}
	return 0;
}
