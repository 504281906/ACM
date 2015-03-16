#include <iostream>
using namespace std;
int f[1010];
int find(int n)
{
	if (n!=f[n]) f[n]=find(f[n]);
	return f[n];
}
int main()
{
	int n,m;
	while (cin>>n>>m)
	{
		int i,s=0;
		for (i=0;i<n;i++)
			f[i]=i;
		for (i=0;i<m;i++)
		{
			int a,b;
			cin>>a>>b;
			a=find(a);
			b=find(b);
			if (a==b) s++;
			else f[b]=a;
		}
		cout<<s<<endl;
	} 
	return 0;
}
