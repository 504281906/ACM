#include <stdio.h>
int main()
{
	int i,n,v,s,t,j;
	int a[101],b[101];
	while (scanf("%d",&v)&&v)
	{
		s=0;
		scanf("%d",&n);
		for (i=1;i<=n;i++)
		scanf("%d%d",&a[i],&b[i]);
		for (i=1;i<n;i++)
		 for (j=i+1;j<=n;j++)
		  if (a[i]<a[j])
		  {
				t=a[i];
				a[i]=a[j];
				a[j]=t;
				t=b[i];
				b[i]=b[j];
				b[j]=t;
		  }
		 for (i=1; i<=n && v>0;i++)
		  {
			if (v>=b[i])
			{
				s+=a[i]*b[i];
				v-=b[i];
			}
			else 
			{
		     	s+=a[i]*v;
			    v=0;
		    }
		  }
		  printf("%d\n",s);
	}
	return 0;
}
