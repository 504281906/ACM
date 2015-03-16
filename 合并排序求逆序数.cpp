#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#define M 0x7fffffff
int a[500010];
__int64 ans;
void fff(int *a,int begin,int mid,int end)
{
	int i,j;
	int k1=mid-begin+1;
	int k2=end-mid;
	int L[k1+5];
	int R[k2+5];
	for (i=1;i<=k1;i++)
		L[i]=a[begin+i-1];
	for (i=1;i<=k2;i++)
		R[i]=a[mid+i];
	L[k1+1]=M;
	R[k2+1]=M;
	i=1;j=1;
	for (int k=begin;k<=end;k++)
	{
		if (L[i]<=R[j])
			a[k]=L[i++];
		else 
		{
			a[k]=R[j++];
			ans+=k1-i+1;
		}
	}
}
void ff(int *a,int begin,int end)
{
	if (begin<end)
	{
		int t=(begin+end)/2;
		ff(a,begin,t);
		ff(a,t+1,end);
		fff(a,begin,t,end);
	}
}
int main()
{
	int n,i;
	while (~scanf("%d",&n) && n)
	{
		for (i=0;i<n;i++)
			scanf("%d",&a[i]);
		ans=0;
		ff(a,0,n-1);
		printf("%I64d\n",ans);
		//for (i=0;i<n;i++)
		//	printf("%d ",a[i]);
		//printf("\n");
	}
	return 0;
}
