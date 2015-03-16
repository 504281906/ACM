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
#include <ctime>
#define LL __int64
#define eps 1e-8
using namespace std;
int x,y,q;
void exgcd(int a,int b)
{
	if (b==0)
	{
		x=1;
		y=0;
		q=a;
		return;
	}
	else
	{
		exgcd(b,a%b);
		int t=x;
		x=y;
		y=t-a/b*y;
	}
	return;
}
int main()
{
	int a,b,c;
	while (~scanf("%d%d%d",&a,&b,&c))
	{
		exgcd(a,b);
		cout<<q<<endl;
		printf("%d * %d + %d * %d = %d\n",a,x,b,y,c);
	}
	return 0;
}

