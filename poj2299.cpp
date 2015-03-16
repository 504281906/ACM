#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#define M 0x3fffffff
__int64 ans;
int a[500010];
void ff(int *a,int begin,int mid,int end)
{
	int i;
	int l1=mid-begin+1;
	int l2=end-mid;
	//int L[l1+2],R[l2+2];
	int* L=new int[l1+2];
	int* R=new int[l2+2];
	for (i=1;i<=l1;i++)
		L[i]=a[begin+i-1];
	for (i=1;i<=l2;i++)
		R[i]=a[mid+i];
	L[l1+1]=M;
	R[l2+1]=M;
	int k1=1,k2=1;
	for (i=begin;i<=end;i++)
	{
		if (L[k1]<=R[k2])
			a[i]=L[k1++];
		else
		{
			ans+=l1-k1+1;
			a[i]=R[k2++];
		}
	}
	delete L;
	delete R;
}
void f(int *a,int begin,int end)
{
	if (begin < end)
	{
		int mid=(begin+end)/2;
		f(a,begin,mid);
		f(a,mid+1,end);
		ff(a,begin,mid,end);
	}
}
int main()
{
	int i,n;
	while (~scanf("%d",&n) && n)
	{
		for (i=0;i<n;i++)
			scanf("%d",&a[i]);
		ans=0;
		f(a,0,n-1);
		printf("%I64d\n",ans);
		/*for (i=0;i<n;i++)
			printf("%d ",a[i]);
		cout<<endl;*/
	}
	return 0;
}
