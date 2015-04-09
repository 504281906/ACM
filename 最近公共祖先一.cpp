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
int n,i;
string a,b;
map<string ,string>mp;
void find(string a,string b)
{
	string c[110];
	int k=0;
	while (1)
	{
		c[k++]=a;
		if (mp[a]=="\0") break;
		a=mp[a];
	}
	int flag;
	while(1)
	{
		flag=0;
		for (i=0;i<k;i++)
			if (b==c[i])
			{
				flag=1;
				break;
			}
		if (flag) break;
		if (mp[b]=="\0") break;
		b=mp[b];
	}
	if (flag) cout<<b<<endl;
	else cout<<"-1"<<endl; 
}
int main()
{
	mp.clear();
	scanf("%d",&n);
	while (n--)
	{
		cin>>a>>b;
		mp[b]=a;
	}
	scanf("%d",&n);
	while (n--)
	{
		cin>>a>>b;
		find(a,b);
	}
	return 0;
}
