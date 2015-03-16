#include <cstdio>
#include <iostream>
#include <cstring>
#include <map>
using namespace std;
int main()
{
	map<__int64,int>mp;
	__int64 a=2,b=3,c;
	mp[a]=1;
	mp[b]=1;
	while (a+b<=0x7fffffff)
	{
		mp[a+b]=1;
		__int64 t=a;
		a=b;
		b=t+b;
	}
	while (scanf("%I64d",&c) && c)
		if (mp[c]==1) printf("Second win\n");
		else printf("First win\n");
	return 0;
}
