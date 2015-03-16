// BEGIN CUT HERE

// END CUT HERE
#line 5 "BoardFoldingDiv2.cpp"
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;
#define PB push_back
#define MP make_pair
#define REP(i,n) for(i=0;i<(n);++i)
#define FOR(i,l,h) for(i=(l);i<=(h);++i)
#define FORD(i,h,l) for(i=(h);i>=(l);--i)
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;
class BoardFoldingDiv2
{
	struct node
	{
		int x,y,x1,y1;
		node();
		node(int x,int y,int x1,int y1):x(x),y(y),x1(x1),y1(y1){};
	};
	/*int cmpare(vector <string> s,int y1,int y2){
		int l=s.size();
		for (int i=0;i<l;i++)
			if (s[i][y1]!=s[i][y2]) return 1;
		return 0;
	}*/
	int gg[100][100];
	int rr[100][100];
	int ll[100][100];
	void init(vector <string> s,int x,int y){
		memset(gg,0,sizeof(gg));
		for (int i=0;i<y;i++){
			for (int j=i+1;j<y;j++){
				int flag=1;
				for (int k=0;k<x;k++)
					if (s[k][i]!=s[k][j]){
						flag=0;
						break;
					}
				if (flag){
					gg[i][j]=gg[j][i]=1;
				}
			}
		}
	}
        public:
        int howMany(vector <string> s)
        {
        	map<LL,int>mp;
        	mp.clear();
			queue<node>q;
        	int ans=1;
        	int i,j;
        	int x=0,y=0;
        	x=s.size();
        	//while (s[0][y]=='0' || s[0][y]=='1') y++;
        	y=s[0].length();
        	init(s,x,y);
        	q.push(node(0,0,x,y));
        	mp[x*100+y]=1;
        	while (!q.empty()){
        		node k=q.front();
        		q.pop();
        		for (i=k.x+1;i<k.x1;i++){ //ÐÐ 
        			int l1=i-k.x;  //k.x-i
        			int l2=k.x1-i; //i-k.x1
        			int f=0;
        			if (l1<=l2){
        				for (j=k.x;j<i;j++)
        					if (s[j]!=s[i+i-j-1]){
        						f=1;
        						break;
        					}
        				if (f) continue;
        				LL h=i*1000000+k.y*10000+k.x1*100+k.y1;
						node h1=node(i,k.y,k.x1,k.y1);
						if (mp[h]==0){
        					mp[h]=1;
        					ans++;
        					q.push(h1);
        				}
        				if (l1==l2){
       						h=k.x*1000000+k.y*10000+i*100+k.y1;
       						h1=node(k.x,k.y,i,k.y1);
       						if (mp[h]==0){
        						mp[h]=1;
        						ans++;
        						q.push(h1);
        					}
        				}
        			}
					else{
						LL h=k.x*1000000+k.y*10000+i*100+k.y1;
        				node h1=node(k.x,k.y,i,k.y1);
        				if (mp[h]==0){
        				for (j=k.x1-1;j>=i;j--)
        					if (s[j]!=s[2*i-j-1]){
        						f=1;
        						break;
        					}
        				if (f) continue;
        					mp[h]=1;
        					ans++;
        					q.push(h1);
        				}
        			}
        		}
        		for (i=k.y+1;i<k.y1;i++){ //ÁÐ 
        			int l1=i-k.y;  
        			int l2=k.y1-i; 
        			int f=0;
        			if (l1<=l2){
        				for (j=k.y;j<i;j++)
        					if (gg[j][2*i-j-1]==0){
        						f=1;
        						break;
        					}
        				if (f) continue;
        				LL h=k.x*1000000+i*10000+k.x1*100+k.y1;
						node h1=node(k.x,i,k.x1,k.y1);
        				if (mp[h]==0){
        					mp[h]=1;
        					ans++;
        					q.push(h1);
        				}
        				if (l1==l2){
        					h=k.x*1000000+k.y*10000+k.x1*100+i;
        					h1=node(k.x,k.y,k.x1,i);
        					if (mp[h]==0){
        						mp[h]=1;
        						ans++;
        						q.push(h1);
        					}
        				}
        			}
					else{
						LL h=k.x*1000000+k.y*10000+k.x1*100+i;
        				node h1=node(k.x,k.y,k.x1,i);
        				if (mp[h]==0){
        				for (j=k.y1-1;j>=i;j--)
        					if (gg[j][2*i-j-1]==0){
        						f=1;
        						break;
        					}
        				if (f) continue;
        					mp[h]=1;
        					ans++;
        					q.push(h1);
        				}
        			}
        		}
        	}
        	return ans;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_2(); if ((Case == -1) || (Case == 1)) test_case_3(); if ((Case == -1) || (Case == 2)) test_case_1(); if ((Case == -1) || (Case == 3)) test_case_0(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"10",
 "11"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, howMany(Arg0)); }
	void test_case_1() { string Arr0[] = {"1111111",
 "1111111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 84; verify_case(1, Arg1, howMany(Arg0)); }
	void test_case_2() { string Arr0[] = {"0110",
 "1001",
 "1001",
 "0110"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(2, Arg1, howMany(Arg0)); }
	void test_case_3() { string Arr0[] = {"0",
 "0",
 "0",
 "1",
 "0",
 "0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(3, Arg1, howMany(Arg0)); }
	void test_case_4() { string Arr0[] = {"000",
 "010",
 "000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(4, Arg1, howMany(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
//		vector <string> ss(100);
		//string ss={"11111111111"};
//        cout<<m.howMany(ss);
        BoardFoldingDiv2 ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
