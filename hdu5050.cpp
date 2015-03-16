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
string s1,s2;
int pd(string a,string b)
{
	int l1=a.length();
	int l2=b.length();
	if (l1<l2) return 1;
	if (l1>l2) return 0;
	for (int i=0;i<l1;i++)
	{
		if (s1[i]>s2[i]) return 0;
		if (s1[i]<s2[i]) return 1;
	}	
}
void go(string a,string b)
{
	int l=b.length();
	int l1=a.length()-1;
	for (int i=l-1;i>=0;i--)
	{
		a[l1]='0'+a[l1]-b[i];
	//	cout<<a<<"@"<<i<<endl;
		if (a[l1]=='/')
		{
			//cout<<"@@@"<<endl;
			int j=l1;
			while (a[j]=='/')
			{
				a[j]='1';
				a[j-1]='0'+a[j-1]-b[i];
				j--;
			}
		}
		l1--;
	}
	int i=0;
	while (a[i]=='0') i++;
	//cout<<a<<endl;
	a.assign(a,i,a.length()-i);
	//cout<<a<<"*"<<b<<endl;
	int g=pd(a,b);
	if (g==0)
	{
		s1=a;
		s2=b;
	}
	else
	{
		s1=b;
		s2=a;
	}
}
int main()
{
	int l1,l2,T,cas=1;
	scanf("%d",&T);
	while (T--)
	{
		getchar();
		cin>>s1>>s2;
		l1=s1.length();
		l2=s2.length();
		//cout<<s1<<" "<<s2<<endl;
		while (s1!=s2 && s2!="" && s1!="")
		{
			int f=pd(s1,s2);
			if (f) go(s2,s1);
			else go(s1,s2);
			//cout<<s1<<" "<<s2<<endl;
		}
		printf("Case #%d: ",cas++);
		cout<<s1<<endl;
	}
	return 0;
}
