#include<stdio.h>
#include<math.h>
int shu(int n);
int main()
{
	int i,n,j,sum;
	while(scanf("%d",&n)!=EOF){
		if(n==0)
			break;
		sum=0;
		for(i=2;i<=n/2;i++){
			j=n-i;
		if(shu(i)&&shu(j)&&i<j)
			sum+=1;}
		printf("%d\n",sum);}
return 0;}
int shu(int n)
{
  int i;
for(i=2;i<=sqrt(n);i++)
if(n%i==0)
return 0;
return 1;}

