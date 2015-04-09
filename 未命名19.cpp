#include <iostream>
#include <cstdio>
using namespace std;

#define INF 1<<30
#define N 501
int c[N][N], closest[N], lowcost[N];
bool visited[N];

void prim(int n)
{
    int i, j, k, min, max;
    for(i = 1; i <= n; i++)
    {
        lowcost[i] = c[1][i];
        closest[i] = 1;
        visited[i] = false;
    }
    visited[1] = true; max = 0;
    for(i = 2; i <= n; i++)
    {
        min = INF;
        k = -1;
        for(j = 2; j <= n; j++)
        {
            if((!visited[j]) && (min > lowcost[j]))
            {
                min = lowcost[j];
                k = j;
            }
        }
        if(-1 == k) break;
        if(max < min) max = min;
        visited[k] = true;
        for(j = 2; j <= n; j++)
        {
            if((!visited[j]) && (c[k][j] < lowcost[j]))
            {
                lowcost[j] = c[k][j];
                closest[j] = k;
            }
        }
    }
    printf("%d\n", max);
}

int main()
{
    int i, j, n, T;
    for(scanf("%d", &T); T > 0; T--)
    {
        scanf("%d", &n);
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
                scanf("%d", &c[i][j]);
        }
        prim(n);
    }
    return 0;
}

