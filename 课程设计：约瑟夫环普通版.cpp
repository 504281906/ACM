#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int a[1000],b[1000],n,m,i;
int main()
{
	printf("请输入人数：");
	scanf("%d",&n);
	printf("请输入每个人的密码：");
	for (i=1;i<=n;i++)
		scanf("%d",&a[i]);
	printf("请输入初始密码：");
	scanf("%d",&m);
	int k=n;
	int pos=0;
	while (k)
	{
		int t=0;
		while (t!=m)
		{
			pos=(pos+1)%(n+1);
			if (pos==0) pos++;
			if (a[pos]) t++;
		}
		b[n-k]=pos;
		m=a[pos];
		a[pos]=0;
		k--;
	}
	printf("所有人出列顺序是：");
	for (i=0;i<n;i++)
		printf("%d ",b[i]);
	cout<<endl;
	return 0;
}
