#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
	int n; 
	int a[10]={1,2,2,3,5,5,7,7,8,9};
	int h=unique(a,a+10)-a;
	for (int i=0;i<h;i++)
		printf("%d ",a[i]);
	while(~scanf("%d",&n))
	{
		int k=lower_bound(a,a+h,n)-a;
		cout<<k<<endl;
	}
}
