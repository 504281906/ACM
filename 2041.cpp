#include<stdio.h>
int main()
{
    int i,j,n,m,a[40];
    while(scanf("%d",&n)!=EOF)
    {a[0]=1;
     a[1]=2;
     for(i=0;i<n;i++)
      {scanf("%d",&m);
        if(m-1==1){printf("1\n");continue;}
        if(m-1==2){printf("2\n");continue;}
       for(j=2;j<m-1;j++)
       {
        a[j]=a[j-1]+a[j-2];
       }
       printf("%d\n",a[m-2]);
      }
    }
    return 0;
}
