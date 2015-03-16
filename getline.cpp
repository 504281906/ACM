#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
	string s;
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while (getline(cin,s)!=NULL && s!="")
	{
		cout<<s<<endl;
	}
	return 0;
}
