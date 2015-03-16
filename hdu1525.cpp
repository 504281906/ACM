#include <iostream>
#include <cstdio>
using namespace std;
long long gcd(long long n,long long m)
{
	if (m==0) return n;
	else return gcd(m,n%m);
}
int pd(long long n,long long m)
{
	if (m==1) return 1;
	if (n-m==1 && m) return 0;
	if (n>=2*m-1) return 1;
	return !pd(m,n % m); 
}
int main()
{
	long long n,m;
	while (~scanf("%lld%lld",&n,&m) && (n+m))
	{
		if (n<m)
		{
			n+=m;
			m=n-m;
			n=n-m;
		}
		long long k=gcd(n,m);
		n/=k;
		m/=k;
		if(pd(n,m))
            cout<<"Stan wins"<<endl;
        else
            cout<<"Ollie wins"<<endl;
	}
	return 0;
}
