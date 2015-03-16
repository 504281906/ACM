#include <iostream>
using namespace std;
long long ff(int n)
{
	long long s=1;
	if (n==0 || n==1)
		return 1;
	s*=n*ff(n-1);
	return s;
}
int main()
{
	int  n,k;
	while (cin>>n>>k)
	{
		long long s=ff(n);
		long long h=1;
		while (k--)
		{
			int a;
			cin>>a;
			h*=ff(a);
		}
		long long ss=s/h;
		cout<<ss<<endl;
	}
	return 0;
}
