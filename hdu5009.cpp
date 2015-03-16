#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

#define newnode ++wmt

const int maxn=50010;

int n,wmt,last[maxn],f[maxn],root[maxn],y[maxn],x[maxn],w[maxn],cnt[300][maxn],front[300],num[300];

bool cmp(int a,int b)
{
    return y[a]<y[b];
}

int main()
{
    while (~scanf("%d",&n))
    {
        y[0]=-1;
        for (int a=1;a<=n;a++)
        {
            scanf("%d",&y[a]);
            if (y[a]==y[a-1])
            {
                n--;
                a--;
            }
        }
        for (int a=1;a<=n;a++)
            x[a]=a;
        sort(x+1,x+n+1,cmp);
       // for (int a=1;a<=n;a++)
        //	printf("%d ",y[x[a]]);
        //puts("");
        int cx=0;
        for (int a=1;a<=n;a++)
            if (y[x[a]]==y[x[a-1]]) w[a]=cx;
            else w[a]=++cx;
        
        for (int a=1;a<=n;a++)
            y[x[a]]=w[a];    //离散化y数组 
                             //Cx离散化后颜色的个数
		 
        int size=0;
        for (;size*size<=n;size++);
        	if ((long long)cx*cx>n) size=10;
        size=min(size,cx);
        
        for (int a=1;a<=size;a++)
        {
            front[a]=num[a]=0;
            for (int b=1;b<=cx;b++)
                cnt[a][b]=0;
        }
        for (int a=1;a<=n;a++)
        {
            f[a]=f[a-1]+1;
            for (int b=1;b<=size;b++)
            {
                cnt[b][y[a]]++;
                if (cnt[b][y[a]]==1)
                {
                    num[b]++;
                    if (num[b]>b)
                    {
                        for (;;)
                        {
                            cnt[b][y[front[b]++]]--;
                            if (cnt[b][y[front[b]-1]]==0) break;
                        }
                        num[b]--;
                    }
                }
                f[a]=min(f[a],f[front[b]-1]+b*b);
            }
        }
        printf("%d\n",f[n]);
    }

    return 0;
}
