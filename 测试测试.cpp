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
char c[110];
string s;
string go(int a,int b)
{
	string ss;
	int i,k=0;
	for (i=a;i<=b;i++)
		ss+=s[i];
	//for (i=0;i<k;i++)
	//		printf("%c",ss[i]);
	//cout<<ss<<k<<endl;
	return ss;
}
int main()
{
	int T,i,j,h;
	scanf("%d",&T);
	while (T--)
	{
		int gg=0;
		memset(c,0,sizeof(c));
		scanf("%s",&c);
		int l=strlen(c);
		s='0';
		for (i=0;i<l;i++)
			if ((c[i]>='A' && c[i]<='Z') || (c[i]>='a' && c[i]<='z'))
				s+=c[i];
		l=s.length()-1;
		/*for (i=1;i<=l;i++)
			printf("%c",s[i]);*/
		for (i=1;i<=(l-2)/3;i++)
		{
			for (j=1;j<=l-3*i;j++)
			{
				string A1=go(1,i);
				string B1=go(i+1,i+j);
				string A2=go(i+j+1,2*i+j);
				string B2=go(2*i+j+1,2*(i+j));
				//cout<<A1<<" "<<B1<<endl;
				//cout<<A2<<" "<<B2<<endl;
				if (A1==B1 || A1!=A2 || B1!=B2) continue;
				if (l==i*3+2*j)
				{
					string A3=go(2*(i+j)+1,l);
					if (A1==A3) gg=1;
					//cout<<A1<<" "<<B1<<endl;
					//cout<<A2<<" "<<B2<<endl;
					//cout<<A3<<endl;
				}
				else 
				{
					if (l-3*(i+j)<=0) continue;
					string B3=go(l-j+1,l);
					string A3=go(l-j-i+1,l-j);
					string C=go(2*(i+j)+1,l-i-j);
					if (C!=A1 && C!=B1 && A1==A3 && B1==B3) gg=1;
				}
				if (gg) break;
			}
			if (gg) break;
		}
		if (gg) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
