#include <bits/stdc++.h>
using namespace std;
int main()
{
	char a[20]="qwertyuiopasdfg";
	char b[20]="ert";
	strncpy(b,a+1,5);
	b[5]='\0';
	cout<<b<<endl;
	cout<<strstr(a,b)<<endl;
	return 0;
}
