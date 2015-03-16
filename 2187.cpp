#include <stdio.h>
int main()
{
	int t,i,m,n,j,p;
	double s;
	int a[1001],b[1001],c[1001];
	scanf("%d",&t);
	while (t--)
	{
		int k;
		scanf("%d%d",&p,&m);
		for (i=1;i<=m;i++)
		 scanf("%d%d",&a[i],&b[i]);
		for (i=1;i<m;i++)
		 for (j=i+1;j<=m;j++)
		  if (a[i]>a[j]) 
		  {
			k=a[i];
			a[i]=a[j];
			a[j]=k;
			k=b[i];
			b[i]=b[j];
			b[j]=k;		
		  }
		for (i=1;i<=m;i++)
		 c[i]=a[i]*b[i];
		i=1;s=0;
		while (p>c[i])
		{
			s+=b[i];
			p-=c[i];
			i++;
		}
		if (p!=0) s+=p*1.000/a[i];
		printf("%.2lf\n",s);
	}
	return 0;
}
