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
using namespace std;
char s[100];
int i,j,q;
int main()
{
	while (~scanf("%s",s))
	{
		int ans=-1;
		int l=strlen(s);
		for (i=l;i>=1;i--)
			s[i]=s[i-1];
		//cout<<s<<endl;
		for (i=1;i<=7;i++)
		{
			int a=0,b=0,c=0;
			if (i>l-2) break;
			if (s[1]=='0' && i!=1) break;
			for (q=1;q<=i;q++)
					a=a*10+(s[q]-'0');
			if (a>1000000) break;
			for (j=i+1;j<=i+7;j++)
			{
				if (j>l-1) break;
				if (l-j>7) continue;
				if (s[i+1]=='0' && j!=i+1) break;
				if (s[j+1]=='0' && l-j!=1) continue;
				b=0;c=0;
				for (q=i+1;q<=j;q++)
					b=b*10+(s[q]-'0');
				if (b>1000000) break;
				for (q=j+1;q<=l;q++)
					c=c*10+(s[q]-'0');
				if (c>1000000) continue;
				if (ans<a+b+c) ans=a+c+b;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
