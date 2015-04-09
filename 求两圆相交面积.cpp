int main()
{
    double d,t,t1,s,x,y,xx,yy,r,rr;
    while(cin>>x>>y>>r)
    {
        cin>>xx>>yy>>rr;
        d=sqrt((x-xx)*(x-xx)+(y-yy)*(y-yy));
        if(d>=r+rr) s=0;
        else if(d<=fabs(r-rr)) s=min(acos(-1.0)*r*r,acos(-1.0)*rr*rr);
        else    （里面有两种情况可以统一）
        {	
			t=(r*r+d*d-rr*rr)/2.0/d;
       		t1=sqrt(r*r-t*t);
        	s=-d*t1+r*r*acos(t/r)+rr*rr*acos((d-t)/rr);
        }
        cout<<fixed<<setprecision(3)<<s<<endl;
    }
    return 0;
}
