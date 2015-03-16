#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int main()
{
	int n;
	const int size=5;
	typedef vector <int> v;
	v a(size);
	a[0]=1;
	a[1]=3;
	a[2]=4;
	a[3]=6;
	a[4]=8;
	v::iterator it;
	for (it=a.begin();it!=a.end();it++)
		cout<<*it<<" ";
	cout<<endl;
	while (~scanf("%d",&n))
	{
		int k=lower_bound(a.begin(),a.end(),n)-a.begin();
		cout<<k<<endl;
	}
	return 0;
}
