#include <stdio.h>
#include <math.h>
int main()
{
    double i;
    while (scanf("%lf",&i)!=EOF)
    printf("%.2lf\n",fabs(i));
    return 0;       
}
