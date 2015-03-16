#include<cstdio>
#include<cstring>
#include<map>
#include<vector>
#include<cmath>
#include<cstdlib>
#include<stack>
#include<queue>
#include <iomanip>
#include<iostream>
#include<algorithm>
using namespace std ;

const int N =20;
const int inf =999999999;

int n, m;
double lx[N], ly[N], w[N][N],f[N][1500];
int fx[N], fy[N],match[N];
double ans;

int dfs(int u)  
{  
     fx[u]=1;  
    for(int i = 1 ; i <= n ; i++)  
    {  
          if(!fy[i] && lx[u]+ly[i] == w[u][i])  
          {  
               fy[i]=1;  
               if(match[i]==-1 || dfs(match[i]))  
               {  
                      match[i]=u;  
                      return 1 ;  
               }  
              
          }  
    }   
    return 0;  
}

int KM()
{
		    for(int a=1;a<=m;a = a+n)
        	{
        		memset(match, -1, sizeof(match));
        		memset((ly),0,sizeof(ly)) ;
				for(int i= 1; i<= n; i++)
				{
					lx[i]= 0;
					for(int j= 1; j<= n; j++)
					{
						w[i][j] = f[i][a+j-1];
						lx[i]= max(lx[i], w[i][j]);
					}
				}

        	for(int k = 1 ; k <= n ; k++)
        	  {	
        		while(1)
        		{
        	   		 memset(fx,0,sizeof(fx)) ;  
                     memset(fy,0,sizeof(fy)) ;  
                     if(dfs(k))  break; 
        	    	  double d = inf ;  
                     for(int  i = 1 ; i <= n ; i++)  
                        if(fx[i])  
                          for(int j = 1 ; j <=n ;j++)  
                            if(!fy[j])  
                                d = min( d,lx[i]+ly[j]-w[i][j]) ;   
                  for(int i  = 1 ; i <= n ; i++)   if(fx[i])  lx[i] -= d ;   
                  for(int i = 1 ; i <= n ; i++ )  if(fy[i])  ly[i] += d ;  
                }
        	 }
        	for(int i =1; i <= n; i++)  
				ans += w[match[i]][i];
          }
      
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int tt= 1; tt<= T; tt++)
	{
	
    	scanf("%d %d",&n,&m);
		{
    		memset(f, 0, sizeof(f));
        	for(int i =1; i <= n; i++)
            	for(int j =1; j <= m; j++)
            		scanf("%lf",&f[i][j]);
       	 	ans= 0;
	        KM() ;
       		printf("Case #%d: %.5lf\n",tt,ans);
    	}
	}
    return 0;
}
