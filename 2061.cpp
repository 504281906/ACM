#include <cstdio>
#include <iostream>
using namespace std;
struct node
{
	char s[100];
	double a,b;
}f[110];
#define ling 1e-10
int main()
{
	int T,i,j,n;
	scanf("%d",&T);
	while (T--)
	{
		cin>>n;
		int ff=1;
		double s=0,s1=0;
		for (i=1;i<=n;i++)
		{
			cin>>f[i].s>>f[i].a>>f[i].b;
			s+=f[i].a*f[i].b;
			s1+=f[i].a;
			if (f[i].b<60) ff=0;
		}
		if (ff)
			printf("%.2lf\n",s/s1);
		else
			cout<<"Sorry!"<<endl;
		if (T) printf("\n");
	}
	return 0;
}
