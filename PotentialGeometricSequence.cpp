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
 
class PotentialGeometricSequence
{
public:
    int numberOfSubsequences(vector <int> d) 
    {
    	int k=d.size();
        int ret=2*k-1;
        int i,j;
    	for (i=0;i<k-2;i++)
    	{
    		int a=d[i+2]-d[i+1];
    		int b=d[i+1]-d[i];
    		if (a==b)
    		{
    			ret++;
    			for (j=i+3;j<k;j++)
    			{
    				int c=d[j]-d[j-1];
    				if (a==c) ret++;
    				else break;
    			}
    		}else continue;
    	}
        return ret;
        }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(0, Arg1, numberOfSubsequences(Arg0)); }
	void test_case_1() { int Arr0[] = {1,2,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(1, Arg1, numberOfSubsequences(Arg0)); }
	void test_case_2() { int Arr0[] = {3,2,1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(2, Arg1, numberOfSubsequences(Arg0)); }
	void test_case_3() { int Arr0[] = {1,2,4,8,16}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(3, Arg1, numberOfSubsequences(Arg0)); }
	void test_case_4() { int Arr0[] = {1,3,5,5,5,5,64,4,23,2,3,4,5,4,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 37; verify_case(4, Arg1, numberOfSubsequences(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
        PotentialGeometricSequence ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
