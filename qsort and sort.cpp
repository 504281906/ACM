#include <cstdio>
//#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
int qcmp(const void *a,const void *b)
{
	int x=*(int *)a;
	int y=*(int *)b;
	if ( x > y )
		return 1;
	else 
		return 0;
}
int cmp(int a,int b)
{
	return a>b;
}
int main()
{
	int i,n=5;
	int a[10],b[10];
	for (i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	qsort(a,n,sizeof(a[0]),qcmp);
	sort(b,b+n,cmp);
	cout<<"qsort:";
	for (i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl<<"sort:";
	for (i=0;i<n;i++)
		cout<<b[i]<<" ";
	cout<<endl;
	return 0;
} 
