#include <stdio.h>
int main()
{
    __int64 n,sum;//为啥一定要__int64 ???;long还不够长??
    while(scanf("%I64d",&n)==1)
    {
         n%=10000; //题目中没讲只取输入的n的后四位!!题意不清!!                
         sum=(n*(n+1)/2)*(n*(n+1)/2)%10000;//化简公式
         printf("%04I64d\n",sum);                    
    }
    
    return 0;
}
