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
int main()
{
#ifdef DEBUG
	freopen("cin.txt", "r", stdin);
	freopen("cout.txt", "w", stdout);
#endif
	int n,i;
	char s[60];
	scanf("%d",&n);
	getchar();
	scanf("%s",&s);
	__int64 k=1;
	__int64 a=0;
	for (i=0;i<strlen(s);i++)
	{
		if (s[i]=='B') a+=k;
		k*=2;
	}
	printf("%I64d\n",a);
	return 0;
}
