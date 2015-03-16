#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>

#define snuke(it,x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); ++ it)

const int N = 200 + 5;
const int INF = 0x3f3f3f3f;
std::vector<int> edges[N];
int dp[N][2],aim,col[N],value[N][2],degree[N],n;
bool vis[N];

void dfs(int u) {
    if (vis[u]) return ;
    vis[u] = true;
    snuke(it,edges[u]) 
        dfs(*it);
    dp[u][0] = dp[u][1] = -1;
    if (col[u] == -1) {
        dp[u][0] = value[u][0];
        dp[u][1] = value[u][1];
    } else {
        int c = col[u];
        snuke(it,edges[u]) {
            int v = *it;
            if (dp[u][c] < dp[v][c]) {
                dp[u][0] = dp[v][0];
                dp[u][1] = dp[v][1];
            }
        }
    }
}

void hehe(int u) {
    if (vis[u]) return ;
    vis[u] = true;
    snuke(it,edges[u]) 
        hehe(*it);
    dp[u][0] = dp[u][1] = -1;
    if (col[u] == -1) {
        dp[u][0] = value[u][0];
        dp[u][1] = value[u][1];
    } else if (col[u] == 0) {
        snuke(it,edges[u]) {
            int v = *it;
            if (dp[u][0] < dp[v][0])
                dp[u][0] = dp[v][0];
        }
    } else {
        int t = -1;
        dp[u][0] = INF;
        snuke(it,edges[u]) {
            int v = *it;
            if (dp[v][0] == aim) 
                t = aim;
            dp[u][0] = std::min(dp[u][0],dp[v][0]);
        }
        dp[u][0] = std::max(dp[u][0],t);
    }
}

int main() {
    int cas;
    scanf("%d",&cas);
    while (cas--) {
        scanf("%d",&n);
        for (int i = 0; i < n; ++ i) {
            edges[i].clear();
            degree[i] = 0;
        }
        for (int i = 0; i < n; ++ i) {
            int m;
            scanf("%d",&m);
            if (m == 0) {
                scanf("%d%d",&value[i][0],&value[i][1]);
                col[i] = -1;
            } else {
                for (int j = 0; j < m; ++ j) {
                    int x;
                    scanf("%d",&x); x --;
                    edges[i].push_back(x);
                    degree[x] ++;
                }
                char str[13];
                scanf("%s",str);
                col[i] = str[0]=='X';
            }
        }
        int root;
        for (int i = 0; i < n; ++ i) {
            if (degree[i] == 0) {
                root = i;
                break;
            }
        }
        memset(vis,0,sizeof(vis));
        dfs(root);
        printf("%d ",dp[root][1]);
        int answer = -1;
        for (int i = 0; i < n; ++ i) {
            if (col[i]==-1 && answer < value[i][1]) {
                aim = value[i][0];
                memset(vis,0,sizeof(vis));
                hehe(root);
                if (dp[root][0] == aim) {
                    answer = value[i][1];
                }
            }
        }
        printf("%d\n",answer);
    }
    return 0;
}
