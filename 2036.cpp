#include<stdio.h>
int main()
{
    int n, x[100], y[100];
    int i, j, t;
    float sum = 0;
    while(scanf("%d",&n)&&n!=0)
    {
           for(i=0;i<n;i++)
              scanf("%d%d", &x[i], &y[i] );
           sum=0;
           x[n]=x[0];  
           y[n]=y[0];
           for(i=0;i<n;i++)
           {
             sum+=x[i]*y[i+1]-y[i]*x[i+1];
           }
           printf( "%.1f\n", sum/2.0 );
    }
}
