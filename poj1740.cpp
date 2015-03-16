#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

bool f[1005];

int main()
{
    //freopen("t.txt", "r", stdin);
    int n;
    while (scanf("%d", &n), n)
    {
        memset(f, 0, sizeof(f));
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int a;
            scanf("%d", &a);
            if (f[a])
                ans--;
            else
                ans++;
            f[a] = !f[a];
        }
        if (ans)
            printf("1\n");
        else
            printf("0\n");
    }
    return 0;
}
