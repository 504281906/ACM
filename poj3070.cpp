#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

class mat
{
    public:
    int nums[2][2];
    mat operator* (const mat &m)
    {
        mat temp;
        for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
        {
            temp.nums[i][j]=0;
            for(int k=0;k<2;k++)
                temp.nums[i][j]=(temp.nums[i][j]+(nums[i][k]*m.nums[k][j]))%10000;
        }
        return temp;
    }
    mat pow(int n,const mat &m)
    {
        if(n==1) return m;
        mat mp=pow(n/2,m);
        if(n%2==0) return mp*mp;
        else       return mp*mp*m;
    }
};
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF,n!=-1)
    {
        mat m;
        m.nums[0][0]=m.nums[0][1]=m.nums[1][0]=1;
        m.nums[1][1]=0;
        if(n<=2)
        {
            if(n==0)       printf("0");
            if(n==1||n==2) printf("1");
            printf("\n");
            continue;
        }
        mat mp=m.pow(n-2,m);
        m.nums[0][0]=m.nums[1][0]=1;
        m.nums[1][1]=m.nums[0][1]=0;
        mp=mp*m;

        printf("%d\n",mp.nums[0][0]);
    }
    return 0;
}
