#include<stdio.h>
#include<string.h>
int main()
{
	long int num[10000];
	int i,j,l,t,k,min,n,c,p;
	char a[10000];
	while(scanf("%s",&a)!=EOF)
	{
    l=strlen(a);
	j=0;c=0,p=0;
	num[0]=0;
    for(i=0;i<l;i++)
    {
        if(a[i]!='5')
        {   
             c=c*10+(a[i]-'0');
             if(a[i+1]=='\0')
             {
                 num[j]=c;
                 j++;
                 break;
             }
             p=1;
		}
        else
            if(p==1)
			{    num[j]=c;
                 c=0;
                 j++;
                 p--;
			}
        }
	n=j-1;
    for (i=0;i<n;i++)
     for (j=i+1;j<=n;j++)
      if (num[i]>num[j]) 
      {t=num[i];num[i]=num[j];num[j]=t;}
	for(i=0;i<n;i++)
		printf("%ld ",num[i]);
   	printf("%ld\n",num[n]);
	}
	return 0;
}
