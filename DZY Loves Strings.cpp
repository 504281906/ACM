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
int a[30];
int cmp(int a,int b)
{
	return a>b;
}
int main()
{
	int max=0;
	char s[1100];
	int k,i;
	scanf("%s",&s);
	scanf("%d",&k);
	for (i=0;i<26;i++)
	{
		int t;
		scanf("%d",&t);
		a[i]=t;
		if (max<a[i]) max=a[i];
	}
	int l=strlen(s);
	long long ans=0;
	for (i=0;i<l;i++)
		ans+=(i+1)*a[s[i]-'a'];
	k=l+k;
	for (i=k;i>l;i--)
		ans+=i*max;
	cout<<ans<<endl;
	return 0;
}
