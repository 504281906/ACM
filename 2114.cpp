#include <stdio.h>
int main()
{
    __int64 n,sum;//Ϊɶһ��Ҫ__int64 ???;long��������??
    while(scanf("%I64d",&n)==1)
    {
         n%=10000; //��Ŀ��û��ֻȡ�����n�ĺ���λ!!���ⲻ��!!                
         sum=(n*(n+1)/2)*(n*(n+1)/2)%10000;//����ʽ
         printf("%04I64d\n",sum);                    
    }
    
    return 0;
}
