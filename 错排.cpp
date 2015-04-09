#include <stdio.h>
int main()
{
    int i,j,n;
    __int64 cmn[28][28];
    __int64 cuo[28];
    __int64 sum;
    cmn[0][0]=1;
    for(i=1;i<=26;i++)
    {
        cmn[i][0]=1;
        cmn[i][i]=1;
        for(j=1;j<i;j++)
            cmn[i][j]=cmn[i-1][j]+cmn[i-1][j-1];
    }
    cuo[0]=1;
    cuo[1]=0;
    cuo[2]=1;
    for(i=3;i<=26;i++)
        cuo[i]=(i-1)*(cuo[i-2]+cuo[i-1]);
    while(EOF!=scanf("%d",&n)&&n)
    {
        sum=0;
        for(i=0;i<=n/2;i++)
            sum+=(cuo[i]*cmn[n][i]);
        printf("%I64d\n",sum);
    }
    return 0;
}
