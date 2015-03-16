#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
int a[100];
int ff(int begin,int end); 
void f(int begin,int end)
{
	int p;
	if (end>begin)
	{
		p=ff(begin,end);
		f(begin,p-1);
		f(p+1,end);
	}
}
int ff(int begin,int end)
{
	int p=end;
	int t=begin;
	for (int i=begin;i<end;i++)
		if (a[i]<a[p])
		{
			swap(a[i],a[t]);
			t++;
		}
	swap(a[p],a[t]);
	return t;
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	f(1,n);
	for (int i=1;i<=n;i++)
	printf(i==1?"%d":" %d",a[i]);
	printf("\n");
}
