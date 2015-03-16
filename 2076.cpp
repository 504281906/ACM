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
        second = 3600 * h + 60 * m + s;  // �������
        angleh = second / 120.0;  // ʱ��ÿ����1/120��
        anglem = second / 10.0;  // ����ÿ����1/10��
        theta = anglem - angleh;
        while (theta > 360)
            theta -= 360;
        if (theta > 180)
            theta = 360 - theta;
        printf("%d\n", (int)theta);
    }
    return 0;
}
