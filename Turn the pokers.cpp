#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
#include <map>
#include <stack>
#include <list>
#include <vector>
using namespace std;
#define LL __int64
int const N=100000+10;
LL const p=1000000009;
//#define DEBUG
int ss[100010];
LL Pow(LL a,LL b,LL mod)  
{  
    LL ans=1;  
    while(b)  
    {  
        if(b&1)
            ans=(ans*a)%mod;   
        b>>=1;  
        a=(a*a)%mod;   
    }  
    return ans;  
}  
LL C(LL n,LL m)  
{  
    if(n<m)  
        return 0;  
    LL ans=1;  
    for(int i=1;i<=m;i++)  
    {
        ans=ans*(((n-m+i)%p)*ss[i])%p;  
    }
    return ans;  
}  
LL Lucas(LL n,LL m)  
{  
    if(m==0)  
        return 1;  
    return (Lucas(n/p,m/p)*C(n%p,m%p))%p;  
}
int main()
{
	int n,m,i,j,k,x,k1;
	for (i=1;i<=100000;i++)
		ss[i]=Pow(i,p-2,p)%p;
	while (scanf("%d%d",&n,&m)==2)
	{
		vector<int>vt[N];
	//	vt[0].erase();
		vt[0].push_back(m);
		for (i=1;i<=n;i++)
		{
			int l=vt[i-1].size();
			scanf("%d",&x);
			for (j=0;j<l;j++)
				for (k=0;k<=min(vt[i-1][j],x);k++)
				{
					if (m-vt[i-1][j]>=x-k)
					{
						int	up=vt[i-1][j]-k+(x-k);
						if (find(vt[i].begin(),vt[i].end(),up)==vt[i].end())
							vt[i].push_back(up);
					}
				}
		}
		LL ans=0;
		for (i = 0; i <vt[n].size(); i++) 
		{
				ans += C(m, vt[n][i]);
				ans %= p;
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
