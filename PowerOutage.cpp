// BEGIN CUT HERE

// END CUT HERE
#line 5 "PowerOutage.cpp"
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
struct node{
	int a,b,c,next;
}edge[1000];
int head[1000];
int w=0;
int dp[1000][5];
void add(int a,int b,int c){
	w++;
	edge[w].a=a;
	edge[w].b=b;
	edge[w].c=c;
	edge[w].next=head[a];
	head[a]=w;
}
// dp[n][0]表示走到这点并且回到这点的最小时间
// dp[n][1]表示这点只走一次 
void DFS(int p,int father){
	int i,j,to,s;
	int son=0;
	for (i=head[p];i!=-1;i=edge[i].next){
		to=edge[i].b;
		if (to==father) continue;
		son++;
		DFS(to,p);
	}
	if (!son){
		dp[p][0]=0;
		dp[p][1]=0;
		return;
	}
	int sum=0;
	for (i=head[p];i!=-1;i=edge[i].next){
		to=edge[i].b;
		s=edge[i].c;
		if (to==father) continue;
		sum+=dp[to][0]+2*s;
	}
	dp[p][0]=sum;
	int mm=0x7fffffff;
	for (i=head[p];i!=-1;i=edge[i].next){
		to=edge[i].b;
		if (to==father) continue;
		s=edge[i].c;
		sum=dp[to][1]+s;
		for (j=head[p];j!=-1;j=edge[j].next){
			int go=edge[j].b;
			if (go==to || go==father) continue;
			sum+=dp[go][0]+2*edge[j].c;
		}
		mm=min(sum,mm);
	}
	dp[p][1]=mm;
}
class PowerOutage
{
        public:
        int estimateTimeOut(vector <int> a, vector <int> b, vector <int> c)
        {
        	int i;
            int n=a.size();
            memset(head,-1,sizeof(head));
            memset(edge,0,sizeof(edge));
            memset(dp,0,sizeof(dp));
        	for (i=0;i<n;i++){
        		add(a[i],b[i],c[i]);
        		add(b[i],a[i],c[i]);
        	}
        	DFS(0,-1);
        	int ans=dp[0][1];
        	return ans;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 10; verify_case(0, Arg3, estimateTimeOut(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {0,1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10,10,10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 40; verify_case(1, Arg3, estimateTimeOut(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {0,0,0,1,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,3,4,2,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10,10,100,10,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 165; verify_case(2, Arg3, estimateTimeOut(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {0,0,0,1,4,4,6,7,7,7,20}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,3,4,2,5,6,7,20,9,10,31}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10,10,100,10,5,1,1,100,1,1,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 281; verify_case(3, Arg3, estimateTimeOut(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {0,0,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {100,200,300,400,500}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2500; verify_case(4, Arg3, estimateTimeOut(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
        PowerOutage ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
