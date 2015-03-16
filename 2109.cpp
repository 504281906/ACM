#include <stdio.h>
#include <stdlib.h>
int comp(const void *a,const void *b)
{
	return *(int*)a-*(int*)b;
}
int main()
{
	int n,s1,s2,t,i,j;
	int a[101],b[101];
 	while (scanf("%d",&n)&&n!=0)
 	{
		for (i=1;i<=n;i++)
		   scanf("%d",&a[i]);
		for (i=1;i<=n;i++)
		   scanf("%d",&b[i]);
		qsort(a,n,sizeof(int),comp);
		qsort(b,n,sizeof(int),comp);
		s1=0;s2=0;
		for (i=1;i<=n;i++)
		 if (a[i]-b[i]>0) s1+=2;  
		 else if (a[i]-b[i]<0) s2+=2;
		 else
		{
			s1++;s2++;
		 }
		printf("%d vs %d\n",s1,s2);
	}
	return 0;
}
