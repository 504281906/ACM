#include<stdio.h>
int main()
{
    int i,sum=0;
    for(i=1000;i<=9999;i++)
    {
        if(i%2==0)
        {
            int iQian,iBai,iShi,iGe;
            iQian=i/1000;
            iBai=i/100-iQian*10;
            iShi=i/10%10;
            iGe=i%10;
            if((iQian+iBai+iShi+iGe)==30) sum+=i;
        }
    }
    printf("%d",sum);
    return 0;
}
