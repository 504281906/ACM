#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 1010;

int num[55][1010], dp[55][1100], time[55][1100], sum[55][1100];
int n, T;

struct node{
    int t, c;
    bool operator < (const node &tmp)const{
        return (t<tmp.t)||(t==tmp.t&&c>tmp.c);        
    }
}p[55];

int main()
{
    int T, t;
    scanf("%d", &t);
    while( t-- )
	{
        scanf("%d%d", &T, &n);
        for(int i = 1; i <= n; i++)
            scanf("%d", &p[i].t);
        for(int i = 1; i <= n; i++)
            scanf("%d", &p[i].c);
        sort( p+1, p+n+1 );
        memset( dp, 0, sizeof(dp));
        memset( num, 0, sizeof(num));
        memset( sum, 0, sizeof(sum));    
        for(int i = 1; i <= n; i++)
		{
            for(int j = 0; j <= T; j++)
			{
                dp[i][j] = dp[i-1][j]; 
				num[i][j] = num[i-1][j];
                sum[i][j] = sum[i-1][j];    
                if( j >= p[i].t )
				{
                    if( dp[i][j] <= (dp[i-1][j-p[i].t]+p[i].c) )
					{
                        if( dp[i][j] < dp[i-1][j-p[i].t]+p[i].c )
						{
                            dp[i][j] = dp[i-1][j-p[i].t]+p[i].c;
                            num[i][j] = num[i-1][j-p[i].t]+1;
                            sum[i][j] = sum[i-1][j-p[i].t] + j;      
                        }
                        else if( num[i][j] <= num[i-1][j-p[i].t]+1 )
						{
                             if( num[i][j] < num[i-1][j-p[i].t]+1 )
							 {    
                                num[i][j] = num[i-1][j-p[i].t]+1;
                                sum[i][j] = sum[i-1][j-p[i].t] + j;    
                             }    
                             else if( sum[i][j] > sum[i-1][j-p[i].t] + j )
                                 sum[i][j] = sum[i-1][j-p[i].t] + j;
                        }    
                    }
                }    
            }
        }
        int pc = 0, pn = 0, pt = 0;
        for(int i = 0; i <= T; i++)
		{
            if( pc < dp[n][i] )
			{
                pc = dp[n][i];pn = num[n][i];pt = sum[n][i];
            }    
            else if( pc == dp[n][i] )
			{
                if( pn < num[n][i] )
                    pn = num[n][i], pt = sum[n][i];    
                else if( pt > sum[n][i] )
                    pt = sum[n][i];
            }        
        }
        printf("%d %d %d\n", pc, pn, pt );    
    }
    return 0;
}
