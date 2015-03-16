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
#define LL __int64
int sg[1000010];
int getl(int x)
{
	for (int i=6;i>0;i--)
	{
		int k=pow(10,(i-1));
		if (x / k) return i;
	}
}
void findsg(int x)
{
	int i,j,l=getl(x);
	for (i=1;i<=l;i++)
	{
		int k=pow(10,(i-1));
		int q=x/k%10;
		int y=x;
		for (j=q;j<9;j++)
		{
			y+=k;
			sg[y]=1;
		}
	}
	int y=x,k=1;
	while (l<6)
	{
		y=y*10;
		for (i=0;i<k;i++)
			sg[y+i]=1;
		k=k*10;
		l++;
	}
}
char s[10];
int main()
{
	memset(sg,0,sizeof(sg));
	sg[0]=1;
	for (int i=1;i<1000000;i++)
		if (!sg[i]) findsg(i);
	while (gets(s))
	{
		if (s[0]=='0') puts("Yes");
		else
		{
			int k=atoi(s);
			//cout<<sg[k]<<endl;
			if (sg[k]) puts("Yes");
			else puts("No");
		}
	}
	return 0;
}
