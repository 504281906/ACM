#include <stdio.h>
int main()
{
    int n,i,j,x[21];
    __int64 m,f[30]={0},t;
    for(i=1;i<21;i++) 
    {
        f[i]=(i-1)*f[i-1]+1;  //ÿ�����еĸ�����ÿ��������).
    }
    while(scanf("%d%I64d",&n,&m)!=EOF)
    {
        for(i=0;i<=n;i++) 
        {
            x[i]=i;    //����
        }
        while(n-- && m)
        {
            t=m/f[n+1]+(m%f[n+1]?1:0);  //�ҳ���m������λ����һ�顣
            printf("%d",x[t]);         //�ǵڼ������һ�����־��Ǽ���
            for(i=t;i<=n;x[i]=x[i+1],i++);    
            {
                m-=(t-1)*f[n+1]+1;
            }
            putchar(m?' ':'\n');
        }                                     
    }
    return 0;
}
