#include<stdio.h>
int main()
{
	int n,i,g,l,t,j;
	while(~scanf("%d%d",&n,&i)){
	{
		if(n<i){
			l=i;
			i=n;
			n=l;
		}
		for(g=n*i;g>i;g--){
			if(g%n==0&&g%i==0)
			t=g;
		}
		printf("%d",t);
	}}
	return 0;
} 
