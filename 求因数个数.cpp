#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int dr[1001], num[1001];  //dr[i]是i的因子个数，num[i] = i
int d[500], di = 0;
bool p[1001];

bool cmp(const int& a, const int& b)
{
    if(dr[a] != dr[b]) return dr[a] < dr[b];
    return  a > b;
}

void Init_Prime()
{
    memset(p, 0, sizeof(p));
    p[1] = 1;
    for(int i = 2; i < 1001; i++)
    {
        if(!p[i])
        {
            d[di++] = i;
            for(int j = 2; j * i < 1001; j++)
                p[i*j] = 1;
        }
    }
    //for(int i = 0; i < di; i++) cout << d[i] << ' ';
    return ;
}

void Cal(int x)
{
    int t = x;
    int sum = 1, cnt;
    for(int i = 0; d[i] <= t / 2 && i < di; i++)
    {
        cnt = 0;
        while(x % d[i] == 0)
        {
            cnt++;
            x /= d[i];
        }
        sum *= (cnt + 1);
    }
    if(!p[t]) sum *= 2;
    dr[t] = sum;
    return ;
}

int main()
{
    int t, n, ca = 1;
    scanf("%d", &t);
    Init_Prime();
    for(int i = 1; i < 1001; i++)
    {
        num[i] = i;
        Cal(i);
    }
    //for(int i = 1; i < 30; i++) cout << i << ' ' << dr[i] << endl;
    sort(num + 1, num + 1001, cmp);
    while(t--)
    {
        scanf("%d", &n);
        printf("Case %d: %d\n", ca++, num[n]);
    }
    return 0;
}
