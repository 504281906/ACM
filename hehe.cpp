#include <stdio.h>
#include <math.h>
#include <iostream>
#include <cstdarg>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <list>
#include <vector>
#include <map>
#define LL long long
#define M(a) memset(a, 0, sizeof(a))
using namespace std;

void Clean(int count, ...)
{
    va_list arg_ptr;
    va_start (arg_ptr, count);
    for (int i = 0; i < count; i++)
        M(va_arg(arg_ptr, int*));
    va_end(arg_ptr);
}
int buf[10089];

void Pre()
{
    buf[0] = 1;
    buf[1] = 2;
    for (int i = 2; i <= 10087; i++)
    {
        buf[i] = (buf[i - 1] + buf[i - 2]) % 10007;

    }
    return ;
}

int main()
{
    char hehe[10099];
    Clean(2, buf, hehe);
    Pre();
    int T;
    scanf("%d", &T);
    for (int cnt = 1; cnt <= T; cnt++)
    {
        scanf("%s", hehe);
        printf("Case %d: ", cnt);
        int res = 1;
        int tmp = 0;
        for (int i = 0; i < strlen(hehe); i++)
        {
            if (hehe[i] == 'h')
            {
                while (hehe[i] == 'h' && i < strlen(hehe))
                {
                    if (hehe[i + 1] == 'e' && hehe[i + 2] == 'h' && hehe[i + 3] == 'e')
                        tmp += 1;
                    else
                    {
                        res *= buf[tmp];
                        res %= 10007;
                        tmp = 0;
                        break;
                    }
                    i += 2;
                }
            }
        }
        res *= buf[tmp];
        res %= 10007;
        printf("%d\n", res);
    }
    return 0;
}

