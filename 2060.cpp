#include <iostream>
using namespace std;
int main()
{
	int T,i,n,a,b;
	cin>>T;
	int f[10]={0,7,6,5,4,3,2};
	while (T--)
	{
		cin>>n>>a>>b;
		int s=a;
		while (n>6)
		{
			s+=8;
			n--;
		}
		for (i=1;i<=n;i++)
			s+=f[i];
		if (s>=b) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
