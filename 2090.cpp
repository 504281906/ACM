#include<stdio.h>
main()
{
	double s,j,sum,d;
	char ch[100];
	sum=0.0;
	while(scanf("%s%lf%lf",ch,&s,&j)!=EOF){
	   	sum=sum+s*j; 
      	}
	   	printf("%.1lf\n",sum);
	   return 0;
 }
