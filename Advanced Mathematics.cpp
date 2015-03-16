#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
#include <map>
#include <stack>
#include <list>
#include <vector>
using namespace std;
int a,b,c,d;
int main()
{
	while (~scanf("%d%d%d%d",&a,&b,&c,&d))
	{
		a=3*a;
		b=2*b;
		int x=b*b-4*a*c;
		if (x<0)
		{
			double s=a+b+c;
			if (s<0)
				printf("(-inf, +inf)-\n");
			else
				printf("(-inf, +inf)+\n");
			continue;
		}
		else
		{
			double s1=(0-b+sqrt(x))/(2.0*a);
			double s2=(0-b-sqrt(x))/(2.0*a);
			if (s1>s2)
			{
				double t=s1;
				s1=s2;
				s2=t;
			}
			if (x==0)
			{
				a/=3;
				b/=2;
				double k1=a*pow((s1-1.1),3)+b*pow((s1-1.1),2)+c*(s1-1.1);
				double k2=a*pow(s1,3)+b*pow(s1,2)+c*s1;
				double k3=a*pow((s1+1.1),3)+b*pow((s1+1.1),2)+c*(s1+1.1);
				if ((k2-k1)*(k3-k2)>=0)
				{
					if (k3-k2>0)
						printf("(-inf, +inf)+");
					else
						printf("(-inf, +inf)-");
				}
				else
				{
					if (k2-k1>0)
						printf("(-inf, %.4lf)+ ",s1);
					else
						printf("(-inf, %.4lf)- ",s1);
					if (k3-k2>0)
						printf("(%.4lf, +inf)+",s1);
					else 
						printf("(%.4lf, +inf)-",s1);
				}
				cout<<endl;
			}
			else
			{
				a/=3;
				b/=2;
				double k1=a*pow((s1-1),3)+b*pow((s1-1),2)+c*(s1-1);
				double k2=a*pow(s1,3)+b*pow(s1,2)+c*s1;
				double k3=a*pow(s2,3)+b*pow(s2,2)+c*s2;
				double k4=a*pow((s2+1),3)+b*pow((s2+1),2)+c*(s2+1);
				if (k2-k1>0)
					printf("(-inf, %.4lf)+ ",s1);
				else
					printf("(-inf, %.4lf)- ",s1);
				if (k3-k2>0)
					printf("(%.4lf, %.4lf)+ ",s1,s2);
				else
					printf("(%.4lf, %.4lf)- ",s1,s2);
				if (k4-k3>0)
					printf("(%.4lf, +inf)+\n",s2);
				else 
					printf("(%.4lf, +inf)-\n",s2);	
			}
		}
	} 
	return 0;
}
