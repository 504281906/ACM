#include"stdio.h"
int main(void)
{
    int nian,yue,ri;
    int a[][13]={{0,31,28,31,30,31,30,31,31,30,31,30,31},{0,31,29,31,30,31,30,31,31,30,31,30,31}};
    while(scanf("%d/%d/%d",&nian,&yue,&ri)!=EOF)
    {
        int i,lea,sum=0;
     	lea=((nian%4==0 && nian%100!=0 || nian%400==0) &&yue>2);
            //sum=sum+1;
        for(i=0;i<yue;i++)
            sum=sum+a[lea][i];
        sum=sum+ri;
        printf("%d\n",sum);
    }
    return 0;
}

