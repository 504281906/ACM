#include<bits/stdc++.h>
using namespace std;
int main()
{
	map<int,string> m;
	map<int,string> ::iterator it;
	for (int i=1;i<=5;i++)
	{
		string s;
		cin>>s;
		m.insert(make_pair(i,s));
	}
	it=m.find(6);
	//for (it=m.begin();it!=m.end();it++)
	if (it==m.end()) printf("WRING\n");
	else
	cout<<(*it).second<<endl;;
	return 0;
}
