#include <stdio.h>
int main()
{
 	int i,j,n,m;
 	while (scanf("%d%d",&n,&m)!=EOF)
 	{
	 	  for (i=1;i<=m+2;i++)
	 	  {
	 	   for (j=1;j<=n+2;j++)
	 	    {
			  if (i==1&&j==1 || i==1&&j==n+2 || i==m+2&&j==1 || i==m+2&&j==n+2) printf("+");
			  else 
			   	 if (i==1||i==m+2) printf("-");  
			   	 else  
		   	     if (j==1||j==n+2) printf("|");	
				 else 
				 if (i!=1||i!=m+2) printf("\ "); 
  			}
  			printf("\n");
		}
			printf("\n");
  	}
  	return 0;
}
