#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int main()
{
	int a[100],i,n;
	scanf("%d",&n);
	for (i=0;i<n;i++)
		scanf("%d",&a[i]);
	//sort(a,a+n);
	sort(a,a+n);
	do
	{
		for (i=0;i<n;i++)
			printf("%d ",a[i]);
		printf("\n");
	}while (prev_permutation(a,a+n)); //next_premutation()
	return 0;
}
