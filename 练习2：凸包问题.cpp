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
struct point 
{
	int x,y;
}p[1010],f[1010];
#define ling 0.00000001
#define pi acos(-1)
double dis(point a,point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double pd(point a,point b,point c)
{
	return (a.x-c.x)*(b.y-c.y)-(b.x-c.x)*(a.y-c.y);
}
bool cmp(point a,point b)
{
	double k=pd(a,b,p[0]);
	if (k<-ling)
		return false;
	if (fabs(k)<=ling && dis(a,p[0])-dis(b,p[0])>ling)
		return false;
	return true;
}
int main()
{
	int i,n,m;
	while (~scanf("%d%d",&n,&m))
	{
		memset(f,0,sizeof(f));
		memset(p,0,sizeof(f));
		point a;
		int k;
		for (i=0;i<n;i++)
		{
			scanf("%d%d",&p[i].x,&p[i].y);
			if (i==0) k=0;
			else 
			{
				if (p[k].y>p[i].y)
					k=i;
				else if (p[k].y==p[i].y && p[k].x>p[i].x)
					k=i;
			}
		}
		point t=p[0];
		p[0]=p[k];
		p[k]=t;
		sort(p+1,p+n,cmp);
		cout<<endl;
		for (i=0;i<n;i++)
			printf("%d %d\n",p[i].x,p[i].y);
		f[0]=p[n-1];
		f[1]=p[0];
		int j=1,l=1;
		while (l<n)
		{
			double h=pd(f[j-1],f[j],p[l]);
			if (h >= ling)
			{
				j++;
				f[j]=p[l];
				l++;
			}
			else j--;
		}
		cout<<endl;
		for (i=1;i<=j;i++)
			printf("%d %d\n",f[i].x,f[i].y);
		double s=0;
		for (i=1;i<=j;i++)
			s+=dis(f[i-1],f[i]);
		s+=dis(f[j],f[0]);
		cout<<s<<endl;
		s+=2*pi*m+0.5;
		//cout<<pi<<endl;
		printf("%d\n",(int)s);
	}
	return 0;
}
