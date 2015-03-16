#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N=300010;

int     n,m,res,f[N],g[N];

struct jilu 
{
    int x,y,z;
}p[N];

bool cmp(const jilu A,const jilu B)
{
    return A.z<B.z;
}

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++)
        scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].z);

    sort(p+1,p+1+m,cmp);

    for (int i=1,j;i<=m;i=j)
    {
        j=i+1;
        while (j<=m && p[i].z==p[j].z)
            j++;
        for (int k=i;k<j;k++)
            g[p[k].y]=max(g[p[k].y],f[p[k].x]+1);
        for (int k=i;k<j;k++)
            f[p[k].y]=g[p[k].y];
    }
    res=0;
    for (int i=1;i<=n;i++)
        res=max(res,f[i]);
    cout << res << endl;
}
