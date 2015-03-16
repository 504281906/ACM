#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>

#define ll __int64

using namespace std;

const int maxn = 1000005;

ll phi[maxn], a, b, p, n;
ll mat1[2][2], mat2[2][2], mat3[2][2];

void init_phi(int n)  // 求欧拉函数 
{
    int i, j;
    for (i = 1; i <= n; i++)
        phi[i] = i;
    for (i = 2; i <= n; i += 2)
        phi[i] /= 2;
    for (i = 3; i <= n; i += 2) 
	{
        if (i == phi[i]) 
		{
            for (j = i; j <= n; j += i)
                phi[j] = phi[j] / i * (i - 1);
        }
    }
}

void mul(ll mat1[2][2], ll mat2[2][2]) 
{
    int i, j, k;
    memset(mat3, 0, sizeof(mat3));
    for (i = 0; i < 2; i++) 
	{
        for (j = 0; j < 2; j++) 
		{
            for (k = 0; k < 2; k++)
                mat3[i][j] += mat1[i][k] * mat2[k][j];
            if (mat3[i][j] >= phi[p] + phi[p])
                mat3[i][j] = mat3[i][j] % phi[p] + phi[p];
        }
    }
    memcpy(mat1, mat3, sizeof(mat3));
}

void fab(ll m) 
{
    mat1[0][0] = mat1[1][1] = 1;
    mat1[1][0] = mat1[0][1] = 0;
    mat2[0][0] = mat2[0][1] = mat2[1][0] = 1;
    mat2[1][1] = 0;
    while (m) 
	{
        if (m & 1) mul(mat1, mat2);
        mul(mat2, mat2);
        m >>= 1;
    }
}

ll pow_mod(ll n, ll k, ll p)   // 快速幂 
{
    ll r = 1;
    while (k) 
	{
        if (k & 1) r = r * n % p;
        n = n * n % p;
        k >>= 1;
    }
    return r;
}

void Solve() 
{
    fab(n - 2);
    printf("%I64d\n", pow_mod(a, mat1[0][1], p) * pow_mod(b, mat1[0][0], p) % p);
}

int main() 
{
    int t, cas = 1;
    init_phi(1000000);
    for (scanf("%d", &t); t--; ) 
	{
        scanf("%I64d %I64d %I64d %I64d", &a, &b, &p, &n);
        printf("Case #%d: ", cas++);
        if (n == 1) printf("%I64d\n", a % p);
        else if (n == 2) printf("%I64d\n", b % p);
        else Solve();
    }
    return 0;
}
