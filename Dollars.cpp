#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
	double x;
	int i,j,k,l,n,m,o,p,q;
	while (~scanf("%lf",&x) && x)
	{
		x*=10;
		if (x<1) 
		{
			printf("%.2lf 1\n",x/10);
			continue;
		}
		int t=0;
		for (i=0;i<=x/500;i++)
		for (j=0;j<=(x-i*500)/200;j++)
		for (k=0;k<=(x-i*500-j*200)/100;k++)
		for (l=0;l<=(x-i*500-j*200-k*100)/50;l++)
		for (n=0;n<=(x-i*500-j*200-k*100-l*50)/20;n++)
		for (m=0;m<=(x-i*500-j*200-k*100-l*50-n*20)/10;m++)
		for (o=0;o<=(x-i*500-j*200-k*100-l*50-n*20-m*10)/5;o++)
		for (p=0;p<=(x-i*500-j*200-k*100-l*50-n*20-m*10-o*5)/2;p++)
		{    
			int y=x-i*500-j*200-k*100-l*50-n*20-m*10-o*5-p*2;
			t+=y+1;
		}		
		printf("%5.2lf%12d\n",x/10,t);		
	}
	return 0;
}
