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
#define eps 1e-8
#define M 1000000007
using namespace std;
char s[1000100]; 
LL go(LL m)
{
	LL ans=0;
	int l=strlen(s);
	for (int i=0;i<l;i++)
		ans=(ans*10+s[i]-'0')%m;
	return ans;
}
LL ksm(LL a,LL b)
{
	LL ans=1;
	while (b)
	{
		if (b%2==1)
			ans=ans*a%M;
		a=a*a%M;
		b/=2;
	}
	return ans;
}
int main()
{
	while (gets(s))
	{
		LL k=go(M-1);
		printf("%I64d\n",ksm(2,k-1));
	}
	return 0;
}

