#include <stdio.h>
int main()
{
 	long i,j,k1,t,k,max,n;
 	int a[100001],b[100001];
    scanf("%d",&t);
 	k=0;k1=t;
 	while (t--)
 	{
	 	 scanf("%d",&n);
          for (i=0;i<n;i++)
           scanf("%d",&a[i]);
          max=b[0]=a[0];j=0;
          for (i=1;i<n;i++)
          {
		   	  if (b[i-1]<0)
		   	   b[i]=a[i];
	   	      else 
	   	       b[i]=b[i-1]+a[i];
   	          if (max<b[i])
   	           {
  	 		     max=b[i];
		  		 j=i;
	           }
  	  	  }
  	  	  if (max<0)
  	  	   i=j-1;
  	  	  else
            for(i=j;i>=0;i--)
                if(b[i]<0)
                    break;
        printf("Case %d:\n",++k);
        printf("%d %d %d\n",max,i+2,j+1);
        if (k!=k1) printf("\n");
  	}
  	return 0;
}
