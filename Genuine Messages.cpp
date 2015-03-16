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
int main()
{
	int T,i,a[30];
	scanf("%d",&T);
	getchar();
	while (T--)
	{
		gets(s);
		int l=strlen(s);
		memset(a,0,sizeof(a));
		int f=0;
		for (i=0;i<l;)
		{
			int c=s[i]-'A';
			a[c]++;
			i++;
			if (a[c]==3)
			{
				if (s[i]==(c+'A')) 
				{
					i++;
					a[c]=0;
				}
				else
				{
					f=1;
					break;
				}
			}
		}
		if (f) puts("FAKE");
		else puts("OK");
	}
	return 0;
}
