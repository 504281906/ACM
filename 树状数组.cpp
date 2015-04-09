#include <stdio.h>
#include <stdlib.h>
#include <string.h>
__int64 s;
int m;
__int64 b[10050];
struct node 
{
    int x;
    int y;
};
node a[1000005];
int cmp(const void *a,const void *b)
{
    if (  ( *(node*)a ).x ==( * ( node* ) b ).x) 
        return ( * (node* ) a ).y-( *(node*) b ).y;
    return (*(node*)a).x-(*(node*)b).x;
}
int lowbit(int x)
{
    return x&(-x);
}
void inc(int x)
{
    while (x<=m)
    {
        b[x]+=1;
        x+=lowbit(x);
    }
}
__int64 sum(int x)
{
    __int64 sum=0;
    while (x>0)
    {
        sum+=b[x];
        x-=lowbit(x);
    }
    return sum;
}
int main()
{
    int T,i,n,k,t=1;
    scanf("%d",&T);
    while (T--)
    {
        s=0;
        memset(b,0,sizeof(b));
        memset(a,0,sizeof(a));
        scanf("%d%d%d",&n,&m,&k);
        for (i=0;i<k;i++)
        {
            scanf("%d%d",&a[i].x,&a[i].y);
        }
        qsort(a,k,sizeof(a[0]),cmp);
        for (i=0;i<k;i++)
        {
            s+=i-sum(a[i].y);
            inc(a[i].y);
        }
        printf("Test case %d: %I64d\n",t++,s);
    }
}
