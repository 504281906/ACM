#include<stdio.h>
int main()
{
	int i,j,t,g,x,y;
while(~scanf("%d%d",&x,&y)){

	if(x<y){
		t=x;
		x=y;
		y=t;
	}
	g=1;
	for(i=y;i>1;i--){
		if(x%i==0&&y%i==0)
	break;
		
	}
	j=x*y/i;
	printf("%d\n",j);}
}
