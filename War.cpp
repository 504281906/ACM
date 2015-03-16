#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int f[20010];
int find(int x)
{
	return x==f[x]?x:f[x]=find(f[x]);
} 
int main()
{
	int n,k,a,b,i;
	while (~scanf("%d",&n))
	{
		for (i=0;i<=2*n;i++)
			f[i]=i;
		while (~scanf("%d%d%d",&k,&a,&b) && k)
		{
			int a1=find(a),a2=find(a+n);
			int b1=find(b),b2=find(b+n);
			switch(k)
			{
				case 1:{
					if (a1==b2 || a2==b1) cout<<"-1"<<endl;
					else 
					{
						f[a1]=b1;
						f[a2]=b2;
					}
					break;
				}
				case 2:{
					if (a1==b1) cout<<"-1"<<endl;
					else 
					{
						f[a1]=b2;
						f[a2]=b1;
					}
					break;
				}
				case 3:{
					if (a1==b1) cout<<"1"<<endl;
					else cout<<"0"<<endl;
					break;
				}
				case 4:{
					if (a1==b2 || a2==b1) cout<<"1"<<endl;
					else cout<<"0"<<endl;
					break;
				}
			}
		}
	}
	return 0;
}
