#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#define ling 1e-8
int Fabds(double d)
{
	if(fabs(d)<ling) return 0;
	else return d>0?1:-1;
}
struct point
{
	double x,y;
	bool operator == (const point &p)  
    {  
        return Fabds(x-p.x)==0 && Fabds(y-p.y)==0;  
    }  
}p[1010];
int da,ds;
point pp[1010];
point pn[1010];
double dis(point a,point b)
{
	return sqrt( (a.x-b.x)*(a.x-b.x)*1.0+(a.y-b.y)*(a.y-b.y) );
}
double fff(point a,point b,point c)
{
	return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}
bool cmp(point a,point b)
{
	double k=fff(p[0],a,b);
	if (Fabds(k)>0) return 1;
	if (Fabds(k)<0 || (Fabds(k)==0 && Fabds(dis(p[0],a)-dis(p[0],b))>0 ) ) return 0;
	return 1;
}
bool line(point a,point b,point c)
{
	double min_x=min(a.x,b.x);  
    double min_y=min(a.y,b.y);  
    double max_x=max(a.x,b.x);  
    double max_y=max(a.y,b.y);  
    if(c.x>=min_x&&c.x<=max_x&&c.y>=min_y&&c.y<=max_y)  
        return true;  
   	return false;  

}
void ff(int n)
{
	int i,j=0;
	point k;
	for (i=1;i<n;i++)
		if ( (p[j].y>p[i].y) || ( (p[j].y==p[i].y) && (p[j].x>p[i].x) ) )
			j=i;
	k=p[0];
	p[0]=p[j];
	p[j]=k;
	sort(p+1,p+n,cmp);
	da=1;
	for (i=2;i<n;i++)
		if (Fabds( fff(p[i],p[i-1],p[0]) ))
			p[da++]=p[i-1];
	p[da++]=p[n-1];
	int l=2;
	ds=1;
	pp[0]=p[0];
	pp[1]=p[1];
	for (l=2;l<da;l++)
	{
		while (ds>=1 && Fabds( fff(pp[ds],pp[ds-1],p[l]))>=0 )
		{
			if (ds==0) break;
			ds--;
		}
		pp[++ds]=p[l];
	}
}
int main()
{
	int T,n;
	scanf("%d",&T);
	while (T--)
	{
		int i,j;
		bool flag=false;
		scanf("%d",&n);
		for (i=0;i<n;i++)
		{
			scanf("%lf%lf",&p[i].x,&p[i].y);
			pn[i]=p[i];
		}
		if (n<6)
		{
			cout<<"NO"<<endl;
			continue;
		}
		for (i=2;i<n;i++)
			if ( Fabds( fff(p[0],p[1],p[i]) )!=0 )
			{
				flag=true;
				break;
			}
		if (!flag) 
		{
			cout<<"NO"<<endl;
			continue;
		}
		ff(n);
		for (i=0;i<=ds;i++)
		{
			flag=false;
			for (j=0;j<n;j++)
				if (!(pn[j]==pp[i]) && !(pn[j]==pp[(i+1)%(ds+1)]))
					if (line( pp[i],pp[(i+1)%(ds+1)],pn[j] ))
					{
						flag=true;
						break;
					}
			if (!flag) break; 
		}
		printf("%s\n",flag?"YES":"NO");
	}	
	return 0;
}
