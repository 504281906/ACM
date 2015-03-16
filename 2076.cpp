#include <stdio.h>
int main()
{
    int n, h, m, s, second;
    double angleh, anglem, theta;
    scanf("%d", &n);
    while (n-- > 0)
    {
        scanf("%d%d%d", &h, &m, &s);
        h %= 12;
        second = 3600 * h + 60 * m + s;  // 换算成秒
        angleh = second / 120.0;  // 时针每秒走1/120度
        anglem = second / 10.0;  // 分针每秒走1/10度
        theta = anglem - angleh;
        while (theta > 360)
            theta -= 360;
        if (theta > 180)
            theta = 360 - theta;
        printf("%d\n", (int)theta);
    }
    return 0;
}
