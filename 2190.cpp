#include <cstdio>
int main()
{
    int T,dp[35],i;
    dp[1]=1;dp[2]=3;
    for(i=3;i<=30;i++)
       dp[i]=dp[i-1]+dp[i-2]*2;
       //dp[i-1]���Ƕ�1��ȫ���ų�Ϊ1�׵ķ���
       //dp[i-2]�����ڳ�2�׷���һ��2�׵ķ��飬�����ڳ���2�׸պ���2�ַ��������Գ���2.
    scanf("%d",&T);
    while(T--)
    {
        int N;
        scanf("%d",&N);
        printf("%d\n",dp[N]);
    }
    return 0;
}

