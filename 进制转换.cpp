#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
int main()
{
	int n,m;
	char s[100];
	while (~scanf("%d%d",&n,&m))
	{
		itoa(n,s,m);
		cout<<s<<endl;
	}
	return 0;
}
