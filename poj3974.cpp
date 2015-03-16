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
char s[1000010],c[2000020];
int d[2000020];
int main()
{
	int cas=1;
	while (~scanf("%s",&s) && s[0]!='E')
	{
		int i,j=0;
		int l=strlen(s);
		for (i=0;i<l;i++)
		{
			c[j++]='#';
			c[j++]=s[i];
		}
		c[j++]='#';
		c[j]='\0';
		l=strlen(c);
		int ans=0,mx=0,id;
		memset(d,0,sizeof(d));
		for (i=0;i<l;i++)
		{
			if (mx>i)
				d[i]=min(d[2*id-i],mx-i);
			else 
				d[i]=1;
			while (i-d[i]>=0 && i+d[i]<l && c[i-d[i]]==c[i+d[i]]) d[i]++;
			if (d[i]+i>mx)
			{
				mx=d[i]+i;
				id=i;
			}
			ans=max(ans,d[i]);
		}
		printf("Case %d: ",cas++);
		cout<<ans-1<<endl;
	}
	return 0;
}
