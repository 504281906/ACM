#include <fstream>
#include <iostream>
using namespace std;
int main()
{
	int n,a[10],b[10];
	char c[100];
	ofstream f;
	ifstream k;
	f.open("t.txt");
	f<<1<<endl;
	f<<200<<" "<<123456<<endl;
	f<<300<<" "<<122131<<endl;
	f.close();
	f.open("t.txt",ios::in);
	f<<2<<endl;
	f.close();
	k.open("t.txt",ios::app);
	k>>n;
	for (int i=0;i<n;i++)
		k>>a[i]>>b[i];
	printf("%d\n",n);
	for (int i=0;i<n;i++)
		printf("%d %d\n",a[i],b[i]);
	return 0;
}


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
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	for (;cin;)
	cin>>a[++t];
	for (int i=t-1;i>1;i--)
		cout<<a[i]<<" ";
	cout<<a[1]<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
