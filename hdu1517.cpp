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
//#define DEBUG
int a[10000000];
int main()
{
	a[1]=1;
	a[2]=9;
	LL s=9;
	LL t=3;
	LL n;
	int f=0,i;
	while (s<=4294967295)
	{
		if (f==0) s*=2;
		else s*=9;
		f=!f;
		a[t++]=s;
	}
	while (~scanf("%I64d",&n))
	{
		int pos=t;
		for (i=1;i<t;i++)
		{
			if (n<=a[i])
			{
				pos=i;
				break;
			}
		}
		if (pos % 2==0) printf("Stan wins.\n");
		else printf("Ollie wins.\n");
	}
	return 0;
}

