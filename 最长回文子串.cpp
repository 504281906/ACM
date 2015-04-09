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
char c[1500000],s[1500000];
int d[3500000];
int main()
{
	int T;
	scanf("%d",&T);
	getchar();
	while (T--)
	{
		scanf("%s",&c);
		int i,j=0;
		int l=strlen(c);
		for (i=0;i<l;i++)
		{
			s[j++]='#';
			s[j++]=c[i];
		}
		s[j++]='#';
		s[j]='\0';
		memset(d,0,sizeof(d));
		int ans=0,mx=0,id;
		l=strlen(s);
		for (i=0;i<l;i++)
		{
			if (mx>i)
				d[i]=min(d[2*id-i],mx-i);
			else
				d[i]=1;
			while (i-d[i]>=0 && i+d[i]<l && s[i-d[i]]==s[i+d[i]]) d[i]++;
			if (d[i]+i>mx)
			{
				mx=d[i]+i;
				id=i;
			}
			ans=max(ans,d[i]);
		}
		printf("%d\n",ans-1);
	}
	return 0;
}
