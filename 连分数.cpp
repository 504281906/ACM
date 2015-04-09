#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
#define ling 1e-8
int main()
{
	double s;
	int a[1000];
	//»òÕßscanf("%d%d",&a,&b); Áîs=a*1.0/(b*1.0); 
	while (scanf("%lf",&s)==1)  
	{
		int i=0;
		while (fabs(s)>ling)
		{
			a[i++]=(int)s;
			s=1/(s-(int)s);
		}
		for (int j=0;j<i-1;j++)
			cout<<a[j]<<" ";
		cout<<endl;
	}
	return 0;
}
