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
#define EPS 1e-8
using namespace std;
char s[10][100];
int a[20];
int main()
{
	int n,i,j;
	scanf("%d",&n);
	getchar();
	for (i=0;i<5;i++)
		gets(s[i]);
//	for (i=0;i<5;i++)
//		cout<<s[i]<<endl;
	memset(a,0,sizeof(a));
	for (i=1;i<=n;i++)
	{
		j=(i-1)*4;
		if (s[3][j]=='*') a[i]=2;
		else if (s[3][j+1]=='*') a[i]=1;
		else if (s[3][j+2]=='*') a[i]=3;
	}
	for (i=1;i<=n;i++)
		printf("%d",a[i]);
	cout<<endl;
	return 0;
}

