#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <ctime>
using namespace std;
struct node
{
	__int64 a[10][10];
	node operator *(const node k2)
	{
		node p;
		memset(p.a,0,sizeof(p.a));
		for (int i=0;i<2;i++)
		for (int j=0;j<2;j++)
			for (int k=0;k<2;k++)
				p.a[i][j]+=a[i][k]*k2.a[k][j];
		return p;	
	}
}d1,d2;
int i,j,k,n;
void ksm(int n)
{
	while (n)
	{
		if (n & 1)
			d2=d2*d1;
		n>>=1;
		d1=d1*d1;
	}
	return ;
}
int main()
{	
	srand(time(NULL));
	while (scanf("%d",&n))
	{
		for (i=0;i<2;i++)
			for (j=0;j<2;j++)
			{
				d1.a[i][j]=1;
				d2.a[i][j]=0;
			}
		d1.a[1][1]=0;
		d2.a[0][0]=d2.a[1][1]=d2.a[2][2]=1;
		ksm(n);
		cout<<d2.a[0][0]<<endl;
	}
}
