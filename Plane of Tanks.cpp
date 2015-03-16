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
struct node
{
	string s;
	int c;
}f[1010];
int cmp(node a,node b)
{
	return a.c<b.c;
}
int main()
{
	int n,k,i,j;
	string s;
	scanf("%d",&n);
	map<string,int>mp;
	int t=0;
	while (n--)
	{
		cin>>s>>k;
		if (mp[s]==0)
		{
			++t;
			f[t].s=s;
			f[t].c=k;
			mp[s]=t;
		}
		else
		{
			if (f[mp[s]].c<k)
				f[mp[s]].c=k;
		}
	}
	//sort(f+1,f+1+t,cmp);
	cout<<t<<endl;
	for (i=1;i<=t;i++)
	{
		int a=0,b=0;
		for (j=1;j<=t;j++)
		{
		//	if (i==j) continue;
			if (f[i].c<f[j].c) a++;
			if (f[i].c>=f[j].c) b++;
		}
		double gg=a*1.0/t;
		double gg1=b*1.0/t;
		if (gg>0.5) cout<<f[i].s<<" "<<"noob"<<endl;
		else if (gg<=0.01) cout<<f[i].s<<" "<<"pro"<<endl;
		else if (gg<=0.1 && gg1>0.01) cout<<f[i].s<<" "<<"hardcore"<<endl;
		else if (gg<=0.2 && gg1>0.1) cout<<f[i].s<<" "<<"average"<<endl;
		else if (gg<=0.5 && gg1>0.2) cout<<f[i].s<<" "<<"random"<<endl;
	}
	return 0;
}
