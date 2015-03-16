#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int f[100010],vis[100010];
int find(int n)
{
	if (n!=f[n]) f[n]=find(f[n]);
	return f[n];
}
int main()
{
	while (1)
	{
		int i,a,b,flag=1,ff=1;
		for (i=1;i<=100000;i++)
			f[i]=i;
		memset(vis,0,sizeof(vis));
		while (scanf("%d%d",&a,&b) && (a+b))
		{
			ff=0;
			if ((-1==a)&&(-1==b)) return 0;
			vis[a]=1;
			vis[b]=1;
			if (find(a)==find(b) && (a!=b)) flag=0;
			a=find(a);
			b=find(b);
			if (a>b)
			{
				a=a+b;
				b=a-b;
				a=a-b;
			}
			f[a]=b;
		}
		if (flag) 
		{
			int k=0;
			for (i=1;i<=100000;i++)
			if (vis[i] && find(i)==i)
				k++;
			if (k==1 || ff) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
		else cout<<"No"<<endl;
	}
}
