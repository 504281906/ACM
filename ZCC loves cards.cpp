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
LL sta[100010];
int a[50];
int main()
{
	int n,m,i,j,k,i1,i2,i3,i4,i5,i6,L;
	while (3==scanf("%d%d%d",&n,&m,&L))
	{
		memset(sta,0,sizeof(sta));
		memset(a,0,sizeof(a));
		LL t=0,s;
		for (i=0;i<n;i++)
			scanf("%d",&a[i]);
		if (m==1) 
		{
			for (i=0;i<n;i++)
				sta[++t]=1<<i;
		}
		else if (m==2)
		{
			for (i=0;i<n-1;i++)
				for (i1=0;i1<n-(i+1);i1++)
				{
					s=(1<<(i+i1+1))+(1<<i1);
					sta[++t]=s;
				}
		}
		else if (m==3)
		{
			for (i=0;i<n-2;i++)
				for (j=0;j<n-(i+1)-1;j++)
					for (k=0;k<n-2-i-j;k++)
					{
					    s=(1<<(i+k+j+2))+(1<<(j+k+1))+(1<<k);
						sta[++t]=s;
					}
		}
		else if (m==4)
		{
			for (i=0;i<n-3;i++)
			for (i1=0;i1<n-(i+1)-2;i1++)
			for (i2=0;i2<n-i-i1-3;i2++)
			for (i3=0;i3<n-i1-i2-i-3;i3++)
			{
				s=(1<<(i+i1+i2+i3+3))+(1<<(i1+i2+i3+2))+(1<<(i2+i3+1))+(1<<i3);
				sta[++t]=s;
			}	
		}
		else if (m==5)
		{
			for (i=0;i<n-3;i++)
			for (i1=0;i1<n-(i+1)-2;i1++)
			for (i2=0;i2<n-i-i1-3;i2++)
			for (i3=0;i3<n-i1-i2-i-4;i3++)
			for (i4=0;i4<n-i1-i2-i3-i-4;i4++)
			{
				s=(1<<(i+i1+i2+i3+i4+4))+(1<<(i1+i2+i3+i4+3))+(1<<(i2+i3+i4+2))+(1<<(i3+i4+1))+(1<<(i4));
				sta[++t]=s;
			}	
		}
		else
		{
			for (i=0;i<n-3;i++)
			for (i1=0;i1<n-(i+1)-2;i1++)
			for (i2=0;i2<n-i-i1-3;i2++)
			for (i3=0;i3<n-i1-i2-i-4;i3++)
			for (i4=0;i4<n-i1-i2-i3-i-5;i4++)
			for (i5=0;i5<n-i-i1-i2-i3-i4-5;i5++)
			{
				s=(1<<(i+i1+i2+i3+i4+i5+5))+(1<<(i1+i2+i3+i4+i5+4))+(1<<(i2+i3+i4+i5+3))+(1<<(i3+i4+i5+2))+(1<<(i4+i5+1))+(1<<i5);
				sta[++t]=s;
			}	
		}
	//	cout<<t<<endl;
	//	for (i=1;i<=t;i++)
	//		cout<<sta[i]<<endl;
		int ss[50],ans=0;
		memset(ss,0,sizeof(ss));
		for (i=1;i<=t;i++)
		{
			map<int,int>mp;
			int l=0;
			for (j=0;j<n;j++)
				if ((1<<j) & sta[i])
					ss[l++]=j;        //序列出来了  cout<<ss<<endl;
			sort(ss,ss+l);
			do
    		{
        	//	for (i=0;i<m;i++)
        	//		printf("%d ",a[ss[i]]);
        	//	cout<<endl;
        		mp.clear();
        		int s1[50];
        		memset(s1,0,sizeof(s1));
        		for (i1=0;i1<m;i1++)
        		{
        			s1[i1]=s1[i1+m]=a[ss[i1]];
        			mp[s1[i1]]=1;
        		}
        		for (i1=0;i1<m;i1++)
        		{
        			int h=s1[i1];
        			for (j=i1+1;j<i1+m;j++)
        			{
        				h=h^s1[j];
        				mp[h]=1;
        			}
        		}
        		int h=L;
        		while (mp[h]) h++;
        		if (h!=L && h-1>ans) ans=h-1; 
    		}while (next_permutation(ss, ss+l));
		}
		cout<<ans<<endl;
	}
	return 0;
}
