# include<stdio.h>
# include<math.h>
# include<string.h>
# define eps 1e-8
# define N 66
# define V 3600
int m,K;
int L[V],R[V];
int D[V],U[V];
int C[V];
int S[N],H[N];
int ak,size;
int dis(int x1,int y1,int x2,int y2)
{
    return abs(x1-x2)+abs(y1-y2);
}
void Link(int r,int c)
{
    S[c]++;C[size]=c;
    U[size]=U[c];D[U[c]]=size;
    D[size]=c;U[c]=size;
    if(H[r]==-1) H[r]=L[size]=R[size]=size;
    else
    {
        L[size]=L[H[r]];R[L[H[r]]]=size;
        R[size]=H[r];L[H[r]]=size;
    }
    size++;
}
void remove(int c)
{
    int i;
    for(i=D[c];i!=c;i=D[i])
        L[R[i]]=L[i],R[L[i]]=R[i];
}
void resume(int c)
{
    int i;
    for(i=U[c];i!=c;i=U[i])
        L[R[i]]=R[L[i]]=i;
}
int h()
{
    int i,j,k,count=0;
    bool visit[N];
    memset(visit,0,sizeof(visit));
    for(i=R[0];i;i=R[i])
    {
        if(visit[i]) continue;
        count++;
        visit[i]=1;
        for(j=D[i];j!=i;j=D[j])
        {
            for(k=R[j];k!=j;k=R[k])
                visit[C[k]]=1;
        }
    }
    return count;
}
void Dance(int k)
{
    int i,j,c,Min,ans;
    ans=h();
    if(k+ans>K || k+ans>=ak) return;
    if(!R[0])
    {
        if(k<ak) ak=k;
        return;
    }
    for(Min=N,i=R[0];i;i=R[i])
        if(S[i]<Min) Min=S[i],c=i;
    for(i=D[c];i!=c;i=D[i])
    {
        remove(i);
        for(j=R[i];j!=i;j=R[j])
            remove(j);
        Dance(k+1);
        for(j=L[i];j!=i;j=L[j])
            resume(j);
        resume(i);
    }
    return;
}
int main()
{
    int i,j,ncase;
    int x1[N],y1[N];
    int left,right,ans,mid;
    scanf("%d",&ncase);
    int cas=1;
    while(ncase--)
    {
    	int max=0;
        scanf("%d%d",&m,&K);
        /*for(i=1;i<=n;i++)
            scanf("%lf%lf",&x[i],&y[i]);*/
        for(i=1;i<=m;i++)
        {
            scanf("%d%d",&x1[i],&y1[i]);
            for (j=1;j<i;j++)
            {
            	if (max<dis(x1[i],y1[i],x1[j],y1[j]))
					max=dis(x1[i],y1[i],x1[j],y1[j]);
            }
    	}
        left=0;
        right=max;
        ans=right;
        while(right>=left)
        {
            for(i=0;i<=m;i++)
            {
                S[i]=0;
                U[i]=D[i]=i;
                L[i+1]=i;R[i]=i+1;
            }R[m]=0;
            memset(H,-1,sizeof(H));
            size=m+1;
            mid=(left+right)/2;
            for(i=1;i<=m;i++)
            {
                for(j=1;j<=m;j++)
                    if(mid>=dis(x1[i],y1[i],x1[j],y1[j]))  Link(i,j);
            }
            ak=N;
            Dance(0);
            if(ak<=K) {ans=mid<ans?mid:ans;right=mid-1;}
            else left=mid+1;
        }
        printf("Case #%d: %d\n",cas++,ans);
    }
    return 0;
}
