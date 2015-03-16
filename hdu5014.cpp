#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int N;
int A[100010];
int mp[100010];
int main()
{
    while(scanf("%d",&N)!=EOF)
    {
        for(int i=0;i<=N;i++)
        {
            scanf("%d",&A[i]);
        }
        int k=0;while((1<<k)<=N)k++;k--;
        int u = N;
        long long sum = 0;
        mp[0] = 0;
        for(;k>=0;k--)
        {
            if((1<<k)<=u)
            {
                int l,r;
                l = (1<<k)-1;
                for(int r=(1<<k);r<=u;r++)
                {
                    mp[r] = l;
                    mp[l] = r;
                    sum += 2*(r^l);
                    l--;
                }
                u = l;
            }
        }
        printf("%I64d\n",sum);
        for(int i=0;i<N;i++)
        {
            printf("%d ",mp[A[i]]);
        }
        printf("%d\n",mp[A[N]]);
    }
    return 0;
}
