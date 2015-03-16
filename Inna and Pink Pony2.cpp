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
int main()
{
#ifdef DEBUG
	freopen("cin.txt", "r", stdin);
	freopen("cout.txt", "w", stdout);
#endif
	int n,m,i,j,a,b;
 	while (~scanf("%d%d%d%d%d%d",&n,&m,&i,&j,&a,&b))
	{
		int k=0x3fffffff;
		if ((i-1)>=a && (i-1)%a==0 && (j-1)>=b && (j-1)%b==0 && ( (i-1)/a+(j-1)/b )%2==0)
			k=min(k,max((i-1)/a,(j-1)/b));
		if ((i-1)>=a && (i-1)%a==0 && (m-j)>=b && (m-j)%b==0 && ( (i-1)/a+(m-j)/b )%2==0)
			k=min(k,max((i-1)/a,(m-j)/b));
		if ((n-i)>=a && (n-i)%a==0 && (m-j)>=b && (m-j)%b==0 && ( (n-i)/a+(m-j)/b )%2==0)
			k=min(k,max( (n-i)/a,(m-j)/b));
		if ((n-i)>=a && (n-i)%a==0 && (j-1)>=b && (j-1)%b==0 && ( (n-i)/a+(j-1)/b )%2==0)
			k=min(k,max( (n-i)/a,(j-1)/b));
		if (k==0x3fffffff) printf("Poor Inna and pony!\n");
			else printf("%d\n",k);
	}
	return 0;
}
