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
int x,y,gcd;
void exgcd(int a,int b)
{
	if (!b)
	{
		x=1;
		y=0;
		gcd=a;
		return;
	}
	exgcd(b,a % b);
	int t=x;
	x=y;
	y=t-a/b*y;
}
int main()
{
	int a,b;
	while (~scanf("%d%d",&a,&b))
	{
		exgcd(a,b);
		cout<<x<<" "<<y<<endl;
		while (x<0)
			x=x+b;
		while (y<0)
			y=y+a;
		//cout<<x<<" "<<y<<endl;
	}
	return 0;
}

