#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef __int64 ll;
const int Size = 16;
ll mod = 10000007.;

struct Matrix {
    ll m[Size][Size];
} I, A, B, T;

Matrix Mul(Matrix a, Matrix b) {
    Matrix c;
    for(int i = 0; i < Size; i++) {
        for(int j = 0; j < Size; j++) {
            c.m[i][j] = 0;
            for(int k = 0; k < Size; k++) {
                c.m[i][j] += a.m[i][k]*b.m[k][j];
                c.m[i][j] %= mod;
            }
        }
    }
    return c;
}
Matrix fpow(int n) {
    Matrix a = A, b = I;
    while(n) {
        if(n&1) b = Mul(b, a);
        n >>= 1;
        a = Mul(a, a);
    }
    return b;
}
int main() {
    int i, j, k, n, m;
    while(scanf("%d %d", &n, &m) != EOF) {
        memset(I.m, 0, sizeof(I.m));
        memset(A.m, 0, sizeof(A.m));
        memset(B.m, 0, sizeof(B.m));

        for(i = 0; i < n+2; i ++)
        {
            I.m[i][i] = 1;
        }

        for(i = 0; i < n; i ++)
        {
            cin >> B.m[0][i];
        }
        B.m[0][n] = 233;
        B.m[0][n+1] = 3;
        

        for(i = 0; i <= n; i ++)
        {
            for(j = 0; j < n; j ++)
            {
                if(j >= i || i == n)
                {
                    A.m[i][j] = 1;
                }
            }
        }
        A.m[n][n] = 10;
        A.m[n+1][n] = 1;
        A.m[n+1][n+1] = 1;

        T = fpow(m);
        T = Mul(B, T);
        cout << T.m[0][n-1] << endl;
    }
    return 0;
}
