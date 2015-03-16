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
int main()
{
	int l,i,ans;
	string s1,s2,s3;
	while (~scanf("%d",&l) && l)
	{
		getchar();
		scanf("%s",&s1);
		scanf("%s",&s2);
		scanf("%s",&s3);
	/*	string s=s1+s2;
		cout<<s<<endl;
		ans=0;
		map<string,int>mp;
		mp[s3]=1;
		
		
		while (mp[s]==0)
		{
			string ss="";
			for (i=0;i<l;i++)
				ss+=s[l+i]+s[i];
			s=ss;
			cout<<s<<endl;
		}*/
		if (s1==s3) cout<<ans<<endl;
		else cout<<-1<<endl;
	} 
	return 0;
}
