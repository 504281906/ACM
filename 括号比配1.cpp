#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
#define sz(x) ((int) (x).size())
const int INF = 11111;
int f[INF], flag;
string s;
int main() {
	cin >> s;
	int s1 = 0, s2 = 0, len = s.size() - 1;
	for (int i = 0; i <= len; i++) {
		if (s[i] == '(')
			f[i] = s1++;
		else
			f[i] = s2++;
	}
	for (int i = len, t; i >= 0; i--) {
		if (s[i] == ')') t = i;
		else {
			if (f[t] < f[i]) {
				swap (s[len], s[i]);
				reverse (s.begin() + i + 1, s.end() );
				flag = 1;
				break;
			}
		}
	}
	if (flag == 0)
		cout << "No solution";
	else
		cout << s;
	return 0;
}
