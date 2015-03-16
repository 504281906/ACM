
#include<iostream>
using namespace std;
__int64 F[13]={0};
int C(__int64 n,__int64 m)
{
	__int64 sum1=1,sum2 =1;
	for(__int64 i=n;i>=n-m+1;--i)
		sum1*=i;
	for(__int64 i=1;i<=m;++i)
		sum2*=i;
	return sum1/sum2;
}
int main()
{
	F[1]=0;
	F[2]=1;
	for(__int64 i=3;i<13;++i)
		F[i]=(F[i-1]+F[i-2])*(i-1);
	__int64 n, m;
	__int64 sum;
	while(cin>>n,n)
	{
		sum=1;
		m=n/2;
		for(__int64 i=2;i<=m;++i)
			sum=C(n,i)*F[i]+sum;
		cout<<sum<<endl;
	}
	return 0;
}
