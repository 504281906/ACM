#include <iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#define pi acos(-1)
#define eps 10e-8
using namespace std;
int main(){
	int T;
	double r,R,x1,y1,x2,y2;
	scanf("%d",&T);
	int cas=1;
	while (T--){
		scanf("%lf%lf",&r,&R);
		scanf("%lf%lf",&x1,&y1);
		scanf("%lf%lf",&x2,&y2);
		printf("Case #%d: ",cas++);
		double d=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
		double r1=R+R;  //外圆相交面积
		double r2=r+R;  // 外圆与内圆相交面积 
		double r3=r+r;
		double s1,s,s2;
		if (d>=r1) s=0;
		else if (d<=eps) {
			printf("%.6lf\n",R*R*pi-r*r*pi);
			continue;
		}
		else{
			double t=d/2;
			double t1=sqrt(R*R-t*t);
			s=-d*t1+R*R*acos(t/R)+R*R*acos((d-t)/R);
		}
		if(d>=r2) s1=0;
        else if(d<=fabs(r-R)) s1=min(pi*r*r,pi*R*R);
        else
        {	
			double t=(r*r+d*d-R*R)/2.0/d;
       		double t1=sqrt(r*r-t*t);
        	s1=-d*t1+r*r*acos(t/r)+R*R*acos((d-t)/R);
        }
        if (d>=r3) s2=0;
		else{
			double t=d/2;
			double t1=sqrt(r*r-t*t);
			s2=-d*t1+r*r*acos(t/r)+r*r*acos((d-t)/r);
		}
        printf("%.6f\n",s-2*s1+s2);
	}
	return 0;
} 
