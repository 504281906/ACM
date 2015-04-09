#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

struct PT
{
    int x1,y1,x2,y2;
    string gogogo;
};

const int dir_x[4]={1,0,0,-1};
const int dir_y[4]={0,-1,1,0};
const char dir[4]={'D','L','R','U'};

char mp[20][20];
int n,m;

int hash(int a,int b,int c,int d)
{
    int ret=a;
    ret=ret*100+b;
    ret=ret*100+c;
    ret=ret*100+d;
    return ret;
}

void ck(int& x1,int& y1,int& x2,int& y2,int d)
{
    if(x1<0||x1>=n||y1<0||y1>=m||mp[x1][y1]=='#')
    {
        x1=x1-dir_x[d];y1=y1-dir_y[d];
    }
    if(x2<0||x2>=n||y2<0||y2>=m||mp[x2][y2]=='#')
    {
        x2=x2-dir_x[d];y2=y2-dir_y[d];
    }
}

int main()
{
while(scanf("%d%d",&n,&m)!=EOF)
{
    int a=0,b=0,c=0,d=0;
    for(int i=0;i<n;i++) scanf("%s",mp[i]);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(mp[i][j]=='*')
            {
                if(a==0&&b==0)
                {
                    a=i;b=j;
                }
                else
                {
                    c=i;d=j;
                }
            }
        }
    }
    PT ac=(PT){a,b,c,d,"@"};

    queue<PT> q;
    q.push(ac);
    set<int> st;
    st.insert(hash(a,b,c,d));
    bool flag=false;
    string ans;
    while(!q.empty())
    {
        PT u=q.front(),v; q.pop();
        if(flag && u.gogogo.size()>ans.size()) break;
        if(u.x1==u.x2&&u.y1==u.y2)
        {
            if(ans.size()==0) ans=u.gogogo;
            else if(ans>u.gogogo) ans=u.gogogo;
            flag=true;
        }
        for(int i=0;i<4;i++)
        {
            int X1=u.x1+dir_x[i],X2=u.x2+dir_x[i];
            int Y1=u.y1+dir_y[i],Y2=u.y2+dir_y[i];
            ck(X1,Y1,X2,Y2,i);

            string R=u.gogogo+dir[i];
            int h=hash(X1,Y1,X2,Y2);
            if(!st.count(h))
            {
                st.insert(h);
                v=(PT){X1,Y1,X2,Y2,R};
                /*for (int kk=0;kk<R.size();kk++)
                printf("%c",R[kk]);
                printf("\n");*/
                q.push(v);
            }
        }
    }
    if(!flag) cout<<"Sorry\n";
    else
    {
        int n=ans.size();
        for(int i=1;i<n;i++) cout<<ans[i];
        cout<<endl;
    }
}
    return 0;
}

