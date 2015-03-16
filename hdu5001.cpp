#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int test, n, m;
vector<int> c[55];
double a[55], f[55][55];

inline void ff(int n){
     double w[n + 1][n + 1];
     memset(w, 0, sizeof(w));
     for (int i = 1; i <= n; i++)
          for (int k = 1; k <= n; k++)
               for (int j = 1; j <= n; j++)
                    w[i][j] += f[i][k] * f[k][j];
     for (int i = 1; i <= n; i++)
          for (int j = 1; j <= n; j++) f[i][j] = w[i][j];
}

inline void af(int n){
     double w[n + 1];
     memset(w, 0, sizeof(w));
     for (int i = 1; i <= n; i++)
          for (int j = 1; j <= n; j++)
               w[i] += a[j] * f[j][i];
     for (int i = 1; i <= n; i++) a[i] = w[i];
}

int main(){
    // freopen("1005.in", "r", stdin);    
    // freopen("1005.out", "w", stdout);
     scanf("%d", &test);
     for (;test--;)
     {
          int step;
          scanf("%d%d%d", &n, &m, &step);
          for (int i = 1; i <= n; i++) c[i].clear();
          for (int i = 1; i <= m; i++) 
          {
               int x, y;
               scanf("%d%d", &x, &y);
               c[x].push_back(y);
               c[y].push_back(x);
          }
          for (int i = 1; i <= n; i++)
          {
               memset(f, 0, sizeof(f));
               for (int j = 1; j <= n; j++) a[j] = 1.0 / n;
               a[n + 1] = 0;
               for (int j = 1; j <= n; j++)
                    if (j != i) 
                    for (int k = 0; k < c[j].size(); k++)
                         f[j][c[j][k]] = 1.0 / c[j].size();
               f[i][n + 1] = 1.0; f[n + 1][n + 1] = 1.0;
             //  step = 0;
               for (int k = step + 1; k; k >>= 1, ff(n + 1))
                    if (k & 1) af(n + 1);
               printf("%.10f\n", 1.0 - a[n + 1]);
          }       
     }
}
