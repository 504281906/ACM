#include <map>
#include <vector>
#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	map<int,string> m;
	map<const int,string> ::iterator it;
	for (int i=1;i<=5;i++)
	{
		string s;
		cin>>s;
		m.insert(make_pair(i,s));
	}
	for (it=m.begin();it!=m.end();it++)
	cout<<(*it).second<<endl;;
	return 0;
}
