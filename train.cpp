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
	int i=1;
	int *a=&i;
	int *b=&i;
	char *c=(char*)2358856;
	(*c)='Y';
	(*a)++;
	a++;
	//*(int*)2358856=1;
	printf("%c\n",*(char*)2358856);
	printf("%d %c\n",c,*c);
	printf("%d %d %d %d\n",a,b,*a,*b);
	return 0;
}

