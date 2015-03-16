#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
using namespace std;
typedef long long ll;
typedef double R;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i, s, t) for(i = (s); i < (t); i++)
#define RFOR(i, s, t) for(i = (s)-1; i >= (t); i--)

const int MAXN = 20;

R p[MAXN][MAXN];
int h[MAXN][MAXN];

R pr[MAXN][MAXN][MAXN];
R esum[MAXN][MAXN][MAXN];

int main(){
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    while(true){
        int n, m;
        int i, j, k, x, y;

        if(!(cin>>m>>n))
            break;

        for(i = 0; i < m; i++)
            cin>>p[i][1];
        for(i = 0; i < m; i++){
            p[i][0] = 1.;
            for(j = 2; j <= n; j++)
                p[i][j] = p[i][j-1]*p[i][1];
        }
        for(i = 0; i < m; i++)
            for(j = 0; j < n; j++)
                cin>>h[i][j];

        R ans = 0.;
        for(i = 1; i < n; i++){
            memset(pr, 0, sizeof pr);
            memset(esum, 0, sizeof esum);
            pr[0][0][0] = 1.;
            for(j = 0; j < m; j++){
                for(k = 0; k < m; k++)
                    for(x = 0; x < m; x++){
                        pr[j+1][k][x] += pr[j][k][x] * (1-p[j][i-1]);
                        esum[j+1][k][x] += esum[j][k][x] * (1-p[j][i-1]);
                    }
                for(k = 0; k < m; k++)
                    for(x = 0; x < m; x++){
                        pr[j+1][k+1][x] += pr[j][k][x] * (p[j][i-1]-p[j][i]);
                        esum[j+1][k+1][x] += esum[j][k][x] * (p[j][i-1]-p[j][i]);
                    }
                for(k = 0; k < m; k++)
                    for(x = 0; x < m; x++){
                        pr[j+1][k+1][x+1] += pr[j][k][x] * (p[j][i]);
                        esum[j+1][k+1][x+1] += esum[j][k][x] * (p[j][i]) + h[j][i] * pr[j][k][x] * (p[j][i]);
                    }
            }
            for(k = 1; k <= m; k++)
                for(x = 0; x <= m; x++)
                    ans += esum[m][k][x] + esum[m][k][x] * x / k;
        }

        for(i = 0; i < m; i++)
            ans += h[i][0];

        cout<<fixed<<setprecision(10)<<ans<<endl;
    }
    return 0;
}
