#include<stdio.h>
void main()
{
	int max(int x,int y,int z);
	int a,b,c,d;
	printf("\ninput a , b , c :");
	scanf("%d%d%d",&a,&b,&c);
	d=max(a,b,c);
	printf("max=%d\n",d);
}
int max(int x,int y,int z)
{
	int w;
	w=0;
	if(w<x)w=x;
	if(w<y)w=y;
	if(w<z)w=z;
	return w;
}