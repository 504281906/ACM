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
const int a=23,b=28,c=33;
int main()
{
#ifdef DEBUG
	freopen("cin.txt", "r", stdin);
	freopen("cout.txt", "w", stdout);
#endif
	int x,z,y,d,i,cas=1;
	while (~scanf("%d%d%d%d",&x,&y,&z,&d) && x!=-1)
	{
		long long a1,b1,c1;
		for (i=1;;i++)
			if (b*c*i % a==1)
			{
				a1=b*c*i;
				break;
			}
		for (i=1;;i++)
			if (a*c*i % b==1)
			{
				b1=a*c*i;
				break;
			}
		for (i=1;;i++)
			if (a*b*i % c==1)
			{
				c1=a*b*i;
				break;
			}
		 int k=a*b*c;
		 int s=(a1*x+b1*y+c1*z-d+k) % k;
		 if (s==0) s=k;
		 printf("Case %d: the next triple peak occurs in %d days.\n",cas++,s);	
	}
	return 0;
}
