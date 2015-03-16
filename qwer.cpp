#include <iostream>  
#include <algorithm>  
#include <string.h>  
#include <stdio.h>  
using namespace std;  
const int MAXN = 11111;  
int h[MAXN], w[MAXN][2], s[2][MAXN];  
int main(){  
    int n, m, k, t=0;  
    while( EOF != scanf("%d%d%d", &n, &m, &k) ){  
        t++;  
        memset(h, 0, sizeof(h));  
        memset(w, 0, sizeof(w));  
        memset(s, 0, sizeof(s));  
        for(int i=0; i<n; i++)  
            scanf("%d", &h[i]);  
        w[0][0] = 1;  
        for(int i=0; i<m; i++){  
            scanf("%d%d", &w[i][1], &w[i+1][0]);  
            w[i+1][0]++;  
        }  
        sort(h, h+n);  
        for(int i=0; i<m; i++){  
            int l = lower_bound(h, h+n, w[i][0])-h;  
            int r = upper_bound(h, h+n, w[i][1])-h-1;  
            s[1][l]++;  
            s[0][r]--;  
        }  
        int now = 0, ans=0;  
        for(int i=0; i<n; i++){  
            now += s[1][i];  
            if( now>=k ) ans++;  
            now += s[0][i];  
        }  
        if( now==k )    ans++;  
        printf("Case %d: %d\n", t, ans);  
    }  
    return 0;  
}  
