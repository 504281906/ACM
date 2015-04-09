#include <stdio.h>
const int k[15]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
	int T,x,y,z;
	scanf("%d",&T);
	for (int i=1;i<=T;i++)
	{
		int t=0,a,b,f=0;
		scanf("%d%d%d",&x,&y,&z);
		if ((z % 400==0) || ((z % 100!=0)&&(z % 4 == 0)))
			f=1;
		for (int j=x;j<=12;j+=x)
		{
			double r=x*y*1.0/j;
			if ( ( (r-(int)r<1e-15) ||(r-(int)r>0.999999999)) && (( ((int)r<=k[j]) &&(j!=2) ) || ((j==2) && ((int)r<=k[j]+f))))
			{
				t++;
				if (t==1)
				{
					a=j;
					b=r;
				}
				else break;
			}
		}
		if (t==1) 
			printf("Case #%d£º%d/%02d/%02d\n",i,z,a,b);
		else if (t==0) printf("Case #%d£º-1\n",i);
		else printf("Case #%d£º1\n",i);
	}
	return 0;
}
