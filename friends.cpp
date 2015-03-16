#include <iostream>
#include <memory.h>
#include <cstdio>
using namespace std;
const int maxn = 101;
bool g[maxn][maxn];
int n, m, k;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d %d", &n, &m, &k);
		memset(g, 0, sizeof(g));
		int ans = 0;
		for(int i = 0; i < m; ++i){
			int u, v;
			scanf("%d %d", &u, &v);
			g[u][v] = g[v][u] = 1;
		}
		while(1){
			int t = 0;
			for(int i = 0; i < n; ++i){
				for(int j = 0; j < n; ++j){
					if(!g[i][j] && i != j){//还不是朋友
						int sum = 0;
						for(int k = 0; k < n; ++k){
							if(g[i][k] && g[j][k]){
								sum++;//累计共同朋友
							}
						}
						if(sum >= k){
							t++;
							g[i][j] = g[j][i] = 1;
						}
					}
				}
			}
			if(!t)break;
			ans += t;
		}
		printf("%d\n",ans);
	}
	return 0;
}
