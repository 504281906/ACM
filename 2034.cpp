#include <stdio.h>
int main()
{
    int i,j,s,t,n,m;
    int a[101],b[101],c[101];
    while (scanf("%d%d",&n,&m)!=EOF && n!=0 && m!=0)
    {
          s=0;
    for (i=1;i<=n;i++)
     {
        scanf("%d",&a[i]);
        c[i]=1;
     }
    for (i=1;i<=m;i++)
        scanf("%d",&b[i]);
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
            if (a[i]==b[j])  
             c[i]=0;
    for (i=1;i<=n;i++)
        s+=c[i];
    if (s==0) 
       printf("NULL ");
    else 
    {
         s=0;
    for (i=1;i<=n;i++)
        if (c[i]==1) 
         {
           s++;
           b[s]=a[i];
         }
    for (i=1;i<s;i++)
     for (j=i+1;j<=s;j++)
       if (b[j]<b[i]) 
       {t=b[i];b[i]=b[j];b[j]=t;}
       for (i=1;i<=s;i++)
        printf("%d ",b[i]);
        } 
    printf("\n");
    }
    return 0;
}
