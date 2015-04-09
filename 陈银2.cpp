#include"stdio.h"
int main(void)
{
    int nian,yue,ri;
    int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    while(scanf("%d/%d/%d",&nian,&yue,&ri)!=EOF)
    {
        int i,sum=0;
        for(i=0;i<yue;i++)
            sum=sum+a[i];
        sum=sum+ri;
        if((nian%4==0&&nian%100!=0||nian%400==0)&&yue>2)
            sum=sum+1;
        printf("%d\n",sum);
    }
    return 0;
}
