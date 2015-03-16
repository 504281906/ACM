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
int f[100010];
char s1[20],s2[20];
int find(int x)
{
	if (x==f[x]) return f[x];
	else return f[x]=find(f[x]);
}
int main()
{
	int T,k,i;
	scanf("%d",&T);
	map<string,int>mp;
	int t=1,a,b;
	for (i=1;i<=100010;i++)
		f[i]=i;
	while (T--)
	{
		scanf("%d %s %s",&k,&s1,&s2);
		if (mp[s1]==0) mp[s1]=t++;
		if (mp[s2]==0) mp[s2]=t++;
		if (k==0)
		{
			a=find(mp[s1]);
			b=find(mp[s2]);
			if (a!=b) f[a]=b;
		}
		else
		{
			a=find(mp[s1]);
			b=find(mp[s2]);
			if (a==b) cout<<"yes"<<endl;
			else cout<<"no"<<endl;
		}
	}
	return 0;
}
