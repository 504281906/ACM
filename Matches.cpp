#include <stdio.h>
long long num;
int a[10]={6,2,5,5,4,5,6,3,7,6};
void ff(int n,int k) //n=还剩n个火柴，k=第k位，last=上一个火柴数 
{
	for (int i=0;i<10;i++)
	if (((i==0 && k!=0)||(i!=0)) && n>=a[i] )
	{
		num++;
		ff(n-a[i],k+1); 
	}
}
int main()
{
	int n; 
	while (~scanf("%d",&n))
	{
		num=0;
		ff(n,0);
		printf("%lld\n",num); 
	}
	return 0;
}
