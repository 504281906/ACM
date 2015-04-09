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
char c[1000010];
char s[3000100];
int d[3000100];
int main()
{
	int T;
	scanf("%d",&T);
	getchar();
	while (T--)
	{
		scanf("%s",&c);
		int l=strlen(c);
		int i,j=0;
		for (i=0;i<l;i++)
		{
			s[j++]='#';
			s[j++]=c[i];
		}
		s[j++]='#';
		s[j]='\0';
		memset(d,0,sizeof(d));
		int ans=0;
		int mx=0,id=0;
		l=strlen(s);
		for (i=0;i<l;i++)
		{
			if (mx>i)
				d[i]=min(d[id*2-i],mx-i);
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
		cout<<ans-1<<endl;
	}
	return 0;
}
