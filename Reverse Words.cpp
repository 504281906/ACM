#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;
char a[1010][1010];
int main()
{
	int t;
	freopen("B-large-practice.in","r",stdin);
	freopen("output.out","w",stdout);
	scanf("%d",&t);
	getchar();
	int h=0;
	while (t--)
	{
		string line,ss;
		while (getline(cin,line))
		{
			istringstream s(line);
			int i=0,j;
			while (s>>a[i++]);
			printf("Case #%d: ",++h);
			for (j=i-2;j>0;j--)
				cout<<a[j]<<" ";
			cout<<a[0]<<endl;
		}
		
	}
	return 0;
}
