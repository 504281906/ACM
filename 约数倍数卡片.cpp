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
#define pi acos(-1)
using namespace std;
int main(){
	char s[10010];
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	gets(s);
	int l=strlen(s),i=0;
	t1=0;
	while(i<l)
	{
		int k=0;
		while (s[i]!=' ' && i<l)
		{
			k=k*10+s[i]-'0';
			i++;
		}
		a[t1++]=k;
		i++;
	}
	gets(s);
	l=strlen(s);
	int t=0;
	i=0;
	while (i<l)
	{
		int k=0;
		while (s[i]!=' ' && i<l)
		{
			k=k*10+s[i]-'0';
			i++;
		}
		b[t++]=k;
		i++;
	}
	sort(b,b+t,cmp);
	memset(g,0,sizeof(g));
	sort(a,a+t1,cmp);
	memset(vis,0,sizeof(vis));
	for (i=0;i<t1;i++)
		if (!vis[i])
		{
			int f=1;
			for (j=i+1;j<t1;j++)
				if (a[i] % a[j]==0 || a[j] % a[i]==0){
					vis[i]=1;
					vis[j]=1;
					f=0;
					break;
				}
			if (f) g[i]=1;  // 1ÊÇ±ØÊ¤µã 
		}
	return 0;
}

