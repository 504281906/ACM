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
char s[110050];
char c[310050];
int d[310050];
int main()
{
	while (~scanf("%s",&s))
	{
		//cout<<s<<endl;
		int l=strlen(s);
		//cout<<s.length()<<endl;
		int i,j=0;
		for (i=0;i<l;i++)
		{
			c[j++]='#';
			c[j++]=s[i];
		}
		c[-1]='!';
		c[j]='#';
		c[++j]='\0';
		l=strlen(c);
		int ans=0;
		int id,mx=0;
		memset(d,0,sizeof(d));
		for (i=0;i<l;i++)
		{
			if (mx>i)
				d[i]=min(d[2*id-i],mx-i);
			else
				d[i]=1;
			while (c[i-d[i]]==c[i+d[i]]) d[i]++;
			if (i+d[i]>mx)
			{
				mx=d[i]+i;
				id=i;
			}
			ans=max(ans,d[i]);
		}
		cout<<ans-1<<endl;
	}
	return 0;
}
