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
#include <ctime>
#define LL __int64
#define eps 1e-8
using namespace std;
struct node{
	LL x,y,z,d;
};
int equal(node a,node b){
	if (a.x==b.x && a.y==b.y && a.z==b.z)
		return 1;
	return 0;
}
void cmp(node &a){
	if (a.x>a.y)
		swap(a.x,a.y);
	if (a.x>a.z)
		swap(a.x,a.z);
	if (a.y>a.z)
		swap(a.y,a.z); 
}
node find(node &a){
	node t=a;
	LL l1=t.y-t.x,l2=t.z-t.y,l;
	while (l1!=l2){
		if (l1<l2){
			l=(l2-1)/l1;
			t.x+=l*l1;
			t.y+=l*l1;
		}
		else{
			l=(l1-1)/l2;
			t.z-=l*l2;
			t.y-=l*l2;
		}
		a.d+=l;
		cmp(t);
		l1=t.y-t.x;
		l2=t.z-t.y;
	}
	return t;
}
node find1(node &a,LL s)  
{  
    node t=a;  
    while(s>0)  
    {  
        int l2=t.z-t.y,l1=t.y-t.x,l;  
        if(l1<l2)  
        {  
            l=(l2-1)/l1;  
            if(l>s) l=s;  
            t.x+=l*l1;
            t.y+=l*l1;  
        }  
        else  
        {  
            l=(l1-1)/l2;  
            if(l>s) l=s;  
            t.z-=l*l2;  
            t.y-=l*l2;  
        }  
        s-=l;  
        cmp(t);  
        l2=t.z-t.y;  
        l1=t.y-t.x;  
    }  
    return t;  
}
int main(){
	node st,ed;
	while (~scanf("%I64d%I64d%I64d %I64d%I64d%I64d",&st.x,&st.y,&st.z,&ed.x,&ed.y,&ed.z)){
		st.d=0;ed.d=0;
		cmp(st);cmp(ed);
		if (!equal(find(st),find(ed)))
			cout<<"NO"<<endl;
		else{
			LL d1=st.d,d2=ed.d;
			LL dis=max(st.d-ed.d,ed.d-st.d);
			if (st.d>ed.d) st=find1(st,dis);
			else ed=find1(ed,dis);
			LL mid,left=0,right=min(d1,d2);
			while (left<right){
				mid=(left+right)/2;
				if (equal(find1(st,mid),find1(ed,mid)))
					right=mid;
				else left=mid+1;
			}
			printf("YES\n%d\n",left*2+dis);
		}
	}
	return 0;
}
