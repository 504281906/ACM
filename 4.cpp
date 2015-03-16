#include <stdio.h>
int main()
{
	int a[3][3]={2,3,4,5,6,7,8,9,10};
	int *p;
	for (p=(int*)a;p<a[0]+9;p++)
	printf("%d ",*p);
	return 0;
}
