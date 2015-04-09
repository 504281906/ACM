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
char s[2000];
int k,ll,rr,maxx,pos,l,gg,i;
void go()
{
	while (ll>=0 && rr<=l)
	{
		if (s[ll]<'a' || s[ll]>'z')
		{
			ll--;
			continue;
		}
		if (s[rr]<'a' || s[rr]>'z')
		{
			rr++;
			continue;
		}
		if (s[ll]!=s[rr])
			gg+=2;
		if (gg>2*k) return;
		int ans=rr-ll+1;
		if (ans>maxx)
		{
			maxx=ans;
			pos=ll;
		}
		ll--;rr++;
	}
}
int main()
{
	int cas=1;
	while (~scanf("%d",&k))
	{
		getchar();
		gets(s+1);
		l=strlen(s+1);
		for (i=1;i<=l;i++)
			if (s[i]>='A' && s[i]<='Z')
				s[i]=s[i]-'A'+'a';
		maxx=0;
		pos=0;
		for (i=1;i<=l;i++)
		{
			gg=0;
			ll=rr=i;
			go();
			gg=0;
			ll=i;rr=i+1;
			go();
		}
		printf("Case %d: %d %d\n",cas++,maxx,pos);
	}
	return 0;
}
