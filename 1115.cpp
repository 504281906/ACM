#include <iostream>
using namespace std;
int main()
{
    int i,j,k,n,T;
    double sumx,sumy,suma;
    int x0,y0,x1,y1,x2,y2;
    double x,y,s;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        scanf("%d%d%d%d",&x0,&y0,&x1,&y1);
        sumx=sumy=suma=0;
        for(i=2;i<n;i++)
		{
            scanf("%d%d",&x2,&y2);
            x=x0+x1+x2;
            y=y0+y1+y2;
            s=x0*y1 + x1*y2
            + x2*y0 - x1*y0
            - x2*y1 - x0*y2;
            suma+=s;
            sumx+=s*x;
            sumy+=s*y;
            x1=x2;y1=y2;
        }
        printf("%.2lf %.2lf\n",sumx/suma/3,sumy/suma/3);
    }
    return 0;
}

