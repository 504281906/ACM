#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <set>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
 
#define SZ(x) (int(x.size()))
int toInt(string s){ istringstream sin(s); int t; sin>>t; return t;}
template<class T> string toString(T x){ ostringstream sout; sout<<x; return sout.str();}
 
// BEGIN CUT HERE
typedef long long int64;
int64 toInt64(string s){ istringstream sin(s); int64 t; sin>>t;return t;}
template<class T> T gcd(T a,T b){ if(a<0) return gcd(-a,b);if(b<0) return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
// END CUT HERE
 
class RectangleCoveringEasy
{
public:
    int solve(int holeH, int holeW, int boardH, int boardW) 
    {
        int ret;
        if (holeH>holeW)
	{
		holeH+=holeW;
		holeW=holeH-holeW;
		holeH=holeH-holeW;
	}
	if (boardH>boardW)
	{
		boardH+=boardW;
		boardW=boardH-boardW;
		boardH=boardH-boardW;
	}
	if (boardH>=holeH && boardW>=holeW && !(boardH==holeH && boardW==holeW))
		ret=1;
	else ret=-1;
        return ret;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; int Arg3 = 1; int Arg4 = -1; verify_case(0, Arg4, solve(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 5; int Arg2 = 4; int Arg3 = 6; int Arg4 = 1; verify_case(1, Arg4, solve(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 20; int Arg2 = 25; int Arg3 = 15; int Arg4 = 1; verify_case(2, Arg4, solve(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 3; int Arg1 = 10; int Arg2 = 3; int Arg3 = 12; int Arg4 = 1; verify_case(3, Arg4, solve(Arg0, Arg1, Arg2, Arg3)); }
// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
        RectangleCoveringEasy ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
