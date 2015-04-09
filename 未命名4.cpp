#include
#include  //sqrt pow atan2 cos sin
#include  //max
using namespace std;

#define eps 1e-8
#define MAXN 200
struct Point
{
    double x,y;
    Point(){}
    Point(double tx,double ty){x=tx;y=ty;}
}p[MAXN];

int n,r;
double dist(Point p1,Point p2)
{
    return sqrt(pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2));
}
Point Get_circleCentre(Point p1,Point p2){
    Point mid=Point((p1.x+p2.x)/2,(p1.y+p2.y)/2);
    double angle=atan2(p1.x-p2.x,p2.y-p1.y);
    double d=sqrt(r*r-pow(dist(p1,mid),2));
    return Point(mid.x+d*cos(angle),mid.y+d*sin(angle));
}
int main(){
    while(cin>>n>>r)
    {
        for(int i=0; i
            cin>>p[i].x>>p[i].y;
        int ans=1;
        for(int i=0; i
        {
            for(int j=i+1; j
            {
                if(dist(p[i],p[j]) > 2.0*r) continue;
                Point centre=Get_circleCentre(p[i],p[j]);
               
                int cnt=0;
                for(int k=0; k
                    if(dist(centre,p[k])<1.0*r+eps) cnt++;//cout<<"dist(centre,p[k]):"<<dist(centre,p[k])<<endl;
                ans=max(ans,cnt);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
