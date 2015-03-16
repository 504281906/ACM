#include <cstdio>
#include <iostream>
using namespace std;
struct node 
{
	int day;
	int ps;
	int num;
}f[1010];
int n;
void ff()
{
	node t;
	int flag=1;
	long long k1,k2;
	for (int i=1;i<=n,flag==1;i++)
	{
		flag=0;
		for (int j=1;j<n;j++)
		{
			k1=f[j+1].day*f[j].ps;
			k2=f[j].day*f[j+1].ps;
			if (k1<k2)
			{
				t=f[j];
				f[j]=f[j+1];
				f[j+1]=t;
				flag=1;
			}
		}
	}
	return;
} 
int main()
{
	int T; 
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
		{
			scanf("%d%d",&f[i].day,&f[i].ps);
			f[i].num=i;
		}
		ff();
		cout<<f[1].num;
		for (int i=2;i<=n;i++)
			printf(" %d",f[i].num);
		printf("\n");
		if (T) printf("\n");
	}
}
