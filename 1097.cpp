#include <stdio.h>
#include <string.h>
int main()
{
 	long a,b,i;
 	int f[1000];
 	while (scanf("%ld%ld",&a,&b)!=EOF)
 	{
	 	  if (b==0) 
	 	  printf("1\n");
	 	  else 
         {
	 	     memset(f,0,sizeof(f));f[1]=a%10;i=1;
	 	     while (1)
	 	      {
	   	        if (f[1]==f[i]*a%10) break; 
			     i++;
			    f[i]=f[i-1]*a%10;	
   		       }
             f[0]=f[i];
		     printf("%ld\n",f[b%(i)]);
		  }
    }
    return 0;
}
