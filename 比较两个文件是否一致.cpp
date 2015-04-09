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
char a[100010][1000];
char b[100010][1000];
int main()
{
	freopen("out.txt","r",stdin);
	int i,l1=0;
	while (gets(a[l1])) l1++;
	freopen("out1.txt","r",stdin);
	int l2=0;
	while (gets(b[l2])) l2++;
	int l=max(l2,l1);
	for (i=0;i<l;i++)
		if (strcmp(a[i],b[i])!=0)
		{
			printf("%d\n",i+1);
			return 0;
		}
	printf("Yes\n");
	return 0;
}
