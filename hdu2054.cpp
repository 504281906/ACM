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
#define LL __int64
#define EPS 1e-8
using namespace std;
void fff(string &a)
{
	int flag=0;
	string::iterator it;
	it=a.begin();
	while (*it == '0') a.erase(it);
	while (it!=a.end()) 
	{
		if (*it=='.') 
		{
			flag=1;
			break;
		}
		it++;
	}
	if (flag)
	{
		it=a.end()-1;
		while (*it=='0') a.erase(it--);
		if (*it=='.') a.erase(it);
	}
}
int main()
{
	string a,b;
	while (cin>>a>>b)
	{
		fff(a);
		fff(b);
		//cout<<a<<" "<<b<<endl;
		if (a==b) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
