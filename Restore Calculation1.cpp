#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
#include <map>
#include <stack>
#include <list>
#include <vector>
using namespace std;
#define LL __int64
const LL M=1e9+7;
char s1[1010],s[1010],s2[1010];
LL dp[100][3];
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	while (gets(s))
	{
		memset(dp,0,sizeof(dp));
		if (s[0]=='0') break;
		gets(s1);gets(s2);
		int l=strlen(s);
		dp[l][0]=1;
		for (int i=l-1;i>=0;i--) //   ���ҵ���ڼ�λ 
			for (int p=0;p<2;p++)     //  p��ʾ�Ƿ��λ0,1 
				if (dp[i+1][p]>0)   //��ʾ��һλ�Ƿ����
					for (int j=0;j<10;j++) // ����s��iλ��������j 
					{
						if (i==0 && j==0) continue;   //���λ����Ϊ0 
						if (s[i]=='?' || s[i]-'0'==j)
						for (int k=0;k<10;k++)   //����s1�ϵ�iλ������k 
						{
							if (i==0 && k==0) continue;
							if (s1[i]=='?' || s1[i]-'0'==k)
							if (s2[i]=='?' || s2[i]-'0'==(j+k+p)%10)
								dp[i][(j+k+p)/10]=(dp[i][(j+k+p)/10]+dp[i+1][p])%M;
						}
					}
		cout<<dp[0][0]<<endl;
	}
	return 0;
}
