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
#include <cstdlib>
#include <ctime>
using namespace std;
int n=10,m=100000;
#define DEBUG
double random()
{
	return (double)rand();
}
int random(int m)
{
	return (int)(random() * (m-1)+0.5);
}
int main()
{
#ifdef DEBUG
	freopen("cin.txt", "r", stdin);
	freopen("cout.txt", "w", stdout);
#endif
	srand(time(NULL));
	printf("%d %d\n",n,m);
	for (int i=0;i<m;i++)
	{
		if (rand() % 2==0) printf("A");else printf("B");
		int x,y;
		for (;;)
		{
			x=random(n)+1;
			y=random(n)+1;
			if (x!=y) break;
		}
		printf(" %d %d\n",x,y);
	}
	return 0;
}

