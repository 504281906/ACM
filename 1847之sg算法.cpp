#include<cstdio>
#include<algorithm>
#include <cstring>
using namespace std;
#define N 1000+10
int arr[11],sg[N];
int pre()//把1000以内的所有的可能一次拿的牌都算出来！ 
{
    arr[0]=1;
    for(int i=1;i<=10;i++) arr[i]=arr[i-1]*2;
    return 0;
}
int mex(int x)//这是求解改点的sg值的算法函数（采用记忆化搜索） 
{
    if(sg[x]!=-1) return sg[x];
    bool vis[N];
    memset(vis,false,sizeof(vis));
    for(int i=0;i<10;i++)
    {
        int temp=x-arr[i];
        if(temp<0) break;
        sg[temp]=mex(temp);
        vis[sg[temp]]=true;
    }
    for(int i=0;;i++)
        if(!vis[i])
        {
            sg[x]=i; break;
		}
    return sg[x];
}
int main()
{
    int num;
    pre();
    while(scanf("%d",&num)!=EOF)
    {
        memset(sg,-1,sizeof(sg));
        if(mex(num)) printf("Kiki\n");  
        else printf("Cici\n"); 
    }
    return 0;
}
