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
#define LL long long
const LL M=1e9+7;
char s[100010];
LL xiaofeima(LL m)
{
	int l=strlen(s);
	LL ans=0;
	for (int i=0;i<l;i++)
		ans=(ans*10+s[i]-'0') %m;
	return ans;
}
LL ksm(LL a,LL b)
{
	LL ans=1;
	while (b)
	{
		if (b % 2==1)
			ans=ans*a%M;
		a=a*a%M;
		b>>=1;
	}	
	return ans;
}
int main()
{
	while (gets(s))
	{
		LL k=xiaofeima(M-1);
		//cout<<k<<endl;
		cout<<ksm(2,k-1)<<endl;
	}
	return 0;
}
