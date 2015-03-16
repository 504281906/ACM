// BEGIN CUT HERE

// END CUT HERE
#line 5 "ABC.cpp"
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
int vis[32][32][32][450];
class ABC
{
	int m,g;
	int p[5],s[50];
	int DFS(int a,int b){
		if (b>g || (b+(m*(m-1)/2-(a-1)*(a-2)/2))<g) return 0;
		if (a==m+1){
			if (b==g) return 1;
			else return 0;
		}
		if (vis[a][p[1]][p[2]][b]) return 0;
		vis[a][p[1]][p[2]][b]=1;
		int f=0;
		for (int i=1;i<=3;i++){
			p[i]++;
			s[a]=i;
			int h=b;
			for (int j=1;j<i;j++)
				h+=p[j];
			f=DFS(a+1,h);
			if (f) return f;
			else p[i]--;
		}
		return f;
	}
        public:
        string createString(int n, int k)
        {
        	m=n;g=k;
        	memset(p,0,sizeof(p));
        	memset(s,0,sizeof(s));
        	memset(vis,0,sizeof(vis));
            int f=DFS(1,0);
            string ans="";
            if (f){
            	for (int i=1;i<=n;i++)
            		ans+='A'+s[i]-1;
            }
            return ans;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 3; string Arg2 = "ABC"; verify_case(0, Arg2, createString(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 0; string Arg2 = "CBA"; verify_case(1, Arg2, createString(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 30; int Arg1 = 262; string Arg2 = ""; verify_case(2, Arg2, createString(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 28; int Arg1 = 262; string Arg2 = "CABBACCBAABCBBB"; verify_case(3, Arg2, createString(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
        ABC ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
