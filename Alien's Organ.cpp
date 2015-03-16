#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;
typedef long long LL;
int main()
{
    LL n, t, i;
    double y, final, mul;
    cin >> t;
    while(t--) 
	{
        cin >> n >> y;
        final = 0.0;
        mul = 1;
        for(i = 1; i <= n; ++i) //P(1)~ P(n) 的情况
		{       
            mul *= (i*1.0);
            final += (pow(y, i) / mul * exp(-y));
        }
        final += exp(-y);           // P(0) 的情况
        printf("%.3lf\n", final);
    }
    return 0;
}
