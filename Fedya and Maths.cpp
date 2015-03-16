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
char s[100010];
int a[5][6]={{},{1,2,4,3},{1,3,4,2},{1,4}};
int main()
{
	int i;
	gets(s);
	int l=strlen(s);
	int k=0;
	for (i=0;i<l;i++)
	{
		int x=k*10+s[i]-'0';
		k=x%4;
	}
	int ans=1;
	ans+=a[1][k];
	ans+=a[2][k];
	if ((s[l-1]-'0') %2==1) ans+=4;
	else ans++;
	cout<<(ans%5)<<endl;
	return 0;
}
