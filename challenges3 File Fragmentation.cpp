#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <map>
using namespace std;
map<string,int> m;
string s[150];
int main()
{
	int T;
	scanf("%d",&T);
	getchar();
	getchar();
	while (T--)
	{
		m.clear();
		int k=0;
		int l=0,max=0;
		string sss;
		while (getline(cin,s[k]) && s[k].length()>0)
		{
			l+=s[k].length();
			k++;
		}
		l=l*2/k;
		for (int i=0;i<k;i++)
			for (int j=i+1;j<k;j++)
				if (s[i].length()+s[j].length()==l)
				{
					string ss;
					ss=s[i]+s[j];
					if (m[ss]>0) m[ss]++;
					else m[ss]=1;
					if (m[ss]>max)
					{
						max=m[ss];
						sss=ss;
					}
					ss=s[j]+s[i];
					if (m[ss]>0) m[ss]++;
					else m[ss]=1;
					if (m[ss]>max)
					{
						max=m[ss];
						sss=ss;
					}
				}
		cout<<sss<<endl;
		if(T) printf("\n");
	}
	return 0;
}
