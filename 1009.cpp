#include <stdio.h>
int main()
{
 	int i,j,m,n,t1;
 	double s,max,a[1001],t;
 	int h[1001],f[1001];
 	while (scanf("%d%d",&m,&n)!=EOF)
 	{
     max=0;s=0;
     if (n==0) printf("0.000\n");
     else
 	 if (m!=-1 && n!=-1)
 	 {
       for (i=1;i<=n;i++)
        {
         scanf("%d%d",&h[i],&f[i]);
         a[i]=h[i]*1.0000/f[i];
		 }  
       if (m==0) 
       {
        for (i=1;i<=n;i++)
 		    if (f[i]==0) max+=h[i];		  
         printf("%.3lf\n",max);
	   }
	   else 
	   {
	   for (i=1;i<n;i++)
	   {
	    for (j=i;j<=n;j++)
		 if (a[i]<a[j])
		  {
		   	t=a[i];a[i]=a[j];a[j]=t;
	   		t1=h[i];h[i]=h[j];h[j]=t1;
            t1=f[i];f[i]=f[j];f[j]=t1;		   
	   	  }
	   }	
	   i=1;
	   do
	   {
	   	 max+=h[i];
		 s+=f[i];
		 i++;  
	   }
	   while (s+f[i]<m);
	    max+=h[i]*(m-s)*1.0000/f[i];
		printf("%.3lf\n",max);	
		}	 	 
 	 }
 	 else break;
    }
 	 return 0;
}
