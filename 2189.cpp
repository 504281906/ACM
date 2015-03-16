#include <stdio.h>            
int main ()
{
    int i,j,k=0,t,n;
    int a[155]={0};        
	int b[155];  
    for (i=2;i<155;i++)
    {
        if (a[i]==0)
        {
            b[k++]=i;
            for (j=i*i;j<155;j+=i)
            {
                a[j]=1;
            }
        }
    }
    for (i=0;i<155;i++) a[i]=0;
    a[0]=1;
    for (i=0;i<k;i++)
    {
        for (j=0;j+b[i]<155;j++)
        {
            a[j+b[i]]+=a[j];
        }
    }
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&n);
        printf("%d\n",a[n]);
    }
    return 0;
}
