#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
double dis[510][510];
int vist[510];
struct node 
{
    int x,y;
}p[510];
double map(node a,node b)
{
    return ( sqrt( (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y) ) );
}
int cmp(void const *a,void const *b)
{
    return (*(double *)a)<(*(double *)b);
}
int main()
{
    int t,n,m,i,j;
    double a[510];
    scanf("%d",&t);
    while (t--)
    {
        double s=0;
        scanf("%d%d",&m,&n);
        for (i=1;i<=n;i++)
            scanf("%d%d",&p[i].x,&p[i].y);
        for (i=1;i<n;i++)
            for (j=i+1;j<=n;j++)
                dis[i][j]=dis[j][i]=map(p[i],p[j]); 
        /*for (i=1;i<=n;i++)
        {
            for (j=1;j<=n;j++)
                printf("%lf ",dis[i][j]);
                printf("\n");
        }*/
        memset(vist,0,sizeof(vist));
        vist[1]=1;
        int T=n-1;
        int num=0;
        while (T--)
        {
            int pos;
            double m=10010;
            for (i=2;i<=n;i++)
                if (!vist[i] && dis[1][i]<m)
                {
                    pos=i;
                    m=dis[1][i];
                }
            vist[pos]=1;
            a[num++]=m;
            for (i=2;i<=n;i++)
                if (!vist[i]&& dis[pos][i]<dis[1][i])
                    dis[1][i]=dis[pos][i];
        }
        qsort(a,num,sizeof(a[0]),cmp);
        printf("%0.2lf\n",a[m-1]);
    }
    return 0;    
}
