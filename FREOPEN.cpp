#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
	int t=0;
	string a[11000];
//	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	for (;cin;)
	cin>>a[++t];
	for (int i=t-1;i>1;i--)
		cout<<a[i]<<" ";
	cout<<a[1]<<endl;
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
