#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
//lower_bound函数。取在(a,a+n)返回大于或等于val的第一个元素的位置，a必须是
//有序的。如果所有元素都小于val，则返回a+n的位置。 
int main()
{
	int n,i,m,a[100];
	scanf("%d",&n);
	for (i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	while (~scanf("%d",&m))
	{
		int k=lower_bound(a,a+n,m)-a;
		printf("%d\n",k);
	}
	return 0;
}
