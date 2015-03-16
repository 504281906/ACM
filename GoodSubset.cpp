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
 
#define M 1000000007
#define SZ(x) (int(x.size()))
int toInt(string s){ istringstream sin(s); int t; sin>>t; return t;}
template<class T> string toString(T x){ ostringstream sout; sout<<x; return sout.str();}
 
// BEGIN CUT HERE
typedef long long int64;
int64 toInt64(string s){ istringstream sin(s); int64 t; sin>>t;return t;}
template<class T> T gcd(T a,T b){ if(a<0) return gcd(-a,b);if(b<0) return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
// END CUT HERE
 
class GoodSubset
{
public:
    int numberOfSubsets(int goodValue, vector <int> d) 
    {
        int n=d.size();
        map<int,int>mp;
        int i,gv=goodValue;
		map<int,int>::iterator it;
		for (i=0;i<n;i++)
		{
			map<int,int>now=mp;
			for (it=mp.begin(); it!=mp.end(); it++)
			{
				int key=it->first;
				int val=it->second;
				long long int t=key;
				if (gv<d[i]*t) continue;
				now[d[i]*t]=(now[d[i]*t]+val)%1000000007;
			}
			now[d[i]]++;
			mp=now;
		}
        return mp[gv];
}
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arr1[] = {2,3,4,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(0, Arg2, numberOfSubsets(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 6; int Arr1[] = {2,3,4,5,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(1, Arg2, numberOfSubsets(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1; int Arr1[] = {1,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 7; verify_case(2, Arg2, numberOfSubsets(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 12; int Arr1[] = {1,2,3,4,5,6,7,8,9,10,11,12}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(3, Arg2, numberOfSubsets(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 5; int Arr1[] = {1,2,3,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(4, Arg2, numberOfSubsets(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
        GoodSubset ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
