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
int f[4000010],x;
int main()
{
	freopen("in.txt","r",stdin);
	//freopen("out1.txt","w",stdout);
	int n,i,j;
	scanf("%d",&n);
	long long a=0,b=0; //a表示第一个数的位置，b表示末尾位置 
	memset(f,0,sizeof(f));
	for (i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if (x<0)
		{
			if (b>a)
			{
				printf("%d %d %d\n",f[a],a,b);
				a++;
			}
		}
		else if (x==0)
		{
			if (b-a<=n-i && b>a)
			{
				j=1;
				while(j<=b-a)
					f[b+j-1]=f[a+j-1],j++;
				b=b+b-a;
			}
		}
		else
		{
			a--;
			f[a]=x;
			if (a<=-14) printf(" %d",x);
		}
	}
	return 0;
}
