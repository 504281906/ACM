// BEGIN CUT HERE

// END CUT HERE
#line 5 "TheKingsRoadsDiv2.cpp"
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

class TheKingsRoadsDiv2
{
		bool q[1000][1000];
        public:
        string getAnswer(int h, vector <int> a, vector <int> b)
        {
        	string gg="Incorrect";
            int i,s[2000],f=0,pos=0;
            int g[5000];
            int k=1;
            for (i=1;i<=h;i++)
            	k=2*k;
            k-=1;
            memset(s,0,sizeof(s));
            memset(q,0,sizeof(q));
            for (i=0;i<k;i++){
            	s[a[i]]++;
            	s[b[i]]++;
            	if (a[i]==b[i]){        
					f++;
					pos=i;
				}
				if (q[a[i]][b[i]]==1){
					f++;
					pos=i;
				}
				q[a[i]][b[i]]=1;
				q[b[i]][a[i]]=1;
            }
            memset(g,0,sizeof(g));
            for (i=1;i<=k;i++)
            	g[s[i]]++;
            if (f>1) return gg;
            for (f==1?i=pos:i=0;i<k;i++){
            	if (a[i]!=b[i]){
            		g[s[a[i]]]--;
            		g[s[a[i]]-1]++;
            		g[s[b[i]]]--;
            		g[s[b[i]]-1]++;
            	}
            	else{
            		g[s[a[i]]]--;
            		g[s[a[i]]-2]++;
            	}
            	//sort(g+1,g+4);
            	if (g[1]==(k+1)/2 && g[2]==1 && g[3]==(k-((k+1)/2+1))){
            		gg="Correct";
            		break;
            	}
            	if (a[i]!=b[i]){
            		g[s[a[i]]]++;
            		g[s[a[i]]-1]--;
            		g[s[b[i]]]++;
            		g[s[b[i]]-1]--;
            	}
            	else{
            		g[s[a[i]]]++;
            		g[s[a[i]]-2]--;
            	}
            	if (f==1) break;
            }
            return gg;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_1() { int Arg0 = 3; int Arr1[] = {4, 7, 7, 1, 1, 1, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {6, 5, 1, 7, 4, 3, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Correct"; verify_case(0, Arg3, getAnswer(Arg0, Arg1, Arg2)); }
	void test_case_0() { int Arg0 = 2; int Arr1[] = {1, 2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2, 1, 3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Incorrect"; verify_case(1, Arg3, getAnswer(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 3; int Arr1[] = {7, 1, 1, 2, 2, 3, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {7, 1, 7, 4, 5, 2, 6}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Incorrect"; verify_case(2, Arg3, getAnswer(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 2; int Arr1[] = {1, 3, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2, 1, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Correct"; verify_case(3, Arg3, getAnswer(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 3; int Arr1[] = {6, 5, 3, 3, 5, 5, 6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 5, 5, 6, 4, 7, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Correct"; verify_case(4, Arg3, getAnswer(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
        TheKingsRoadsDiv2 ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
