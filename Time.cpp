// BEGIN CUT HERE

// END CUT HERE
#line 5 "Time.cpp"
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

class Time
{
        public:
        string whatTime(int s)
        {
            int a=0,b=0;
            if (s >= 3600){
            	a=s/3600;
            	s=s%3600;
            }
            if (s >= 60){
            	b=s/60;
            	s=s%60;
            }
        	char ss[50];
        	//ss=a+":"+b+":"+s;
        	sprintf(ss,"%d:%d:%d",a,b,s);
			return ss;
        	//printf("%d:%d:%d",a,b,s);
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 0; string Arg1 = "0:0:0"; verify_case(0, Arg1, whatTime(Arg0)); }
	void test_case_1() { int Arg0 = 3661; string Arg1 = "1:1:1"; verify_case(1, Arg1, whatTime(Arg0)); }
	void test_case_2() { int Arg0 = 5436; string Arg1 = "1:30:36"; verify_case(2, Arg1, whatTime(Arg0)); }
	void test_case_3() { int Arg0 = 86399; string Arg1 = "23:59:59"; verify_case(3, Arg1, whatTime(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
        Time ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
