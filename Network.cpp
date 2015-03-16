#include<stdio.h>
#include<stdlib.h>
struct point
{
    int x,y,lenth;
}map[15008];
int flag[1008];
int cmp(const void *a,const void *b)
{
    return (* (point *)a).lenth-(* (point *)b).lenth;
}
int father(int x)
{
    if(x==flag[x])
        return x;
    flag[x]=father(flag[x]);
    return flag[x];
}
int main()
{
    int m,n,i,k,fa,fb,max=0;
    int a[15008],b[15008];
    while(~scanf("%d%d",&n,&m))
    {
        for(i=0;i<m;i++)
            scanf("%d%d%d",&map[i].x,&map[i].y,&map[i].lenth);
        for(i=0;i<=n;i++)
            flag[i]=i;
        qsort(map,m,sizeof(map[0]),cmp);
        /*for(i=0;i<m;i++)
            scanf("%d %d %d\n",map[i].x,map[i].y,map[i].lenth);*/
        k=0;
        for(i=0;i<m;i++)
        {
            fa=father(map[i].x);
            fb=father(map[i].y);
            if(fa!=fb)
			{
                if(fa>fb)
                    flag[fa]=fb;
                else 
					flag[fb]=fa;
                a[k]=map[i].x;
                b[k]=map[i].y;
                k++;
                if(max<map[i].lenth)
                    max=map[i].lenth;
            }
        }
        printf("%d\n",max);
        printf("%d\n",k);
        for(i=0;i<k;i++)
            printf("%d %d\n",a[i],b[i]);
    }
    return 0;
}
