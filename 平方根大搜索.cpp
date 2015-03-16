#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>
using namespace std;
int a1[10010],a2[10010],b[10000],c[10000],l1,l2,s[110000];
int l3,l4,l5,point,point2,point3,point1;
char ans[1000];
char ss[23];
int chengfa()
{
	int pos,i,j;
	memset(s,0,sizeof(s));
	for (i=1;i<=l4;i++)
		for (j=1,pos=i;j<=l4;j++)
			s[pos++]+=a2[i]*a2[j];
	pos-=1;
	for (i=1;i<=pos;i++)
	if (s[i]>=10)
	{
		if (i==pos) pos++;
		s[i+1]+=s[i]/10;
		s[i]%=10;
	}
	return pos;
}
void jia()
{
	int p=1,i;
	if (point > point1)
	{
		for (i=1;i<=point - point1;i++)
			a2[p++]=a1[i];
		int tt=1;
		for (i=point - point1+1;i<=l1;i++)
			a2[p++]=a1[i]+c[tt++];
		point2=point;
	}
	else
	{
		for (i=1;i<=point1-point;i++)
			a2[p++]=c[i];
		int tt=i;
		for (i=1;i<=l1;i++)
			a2[p++]=a1[i]+c[tt++];
		point2=point1;
	}
	int kk=0;
	p--;
	for (i=1;i<=p;i++)
	{
		a2[i]+=kk;
		kk=a2[i]/10;
		a2[i]%=10;
	}
	if (kk!=0) a2[++p]=kk;
	l4=p;
}
int gobj()
{
	int sl=l5,bl=l2;
	if (sl-point3>bl) return 1;
	else if (sl-point3<bl) return -1;
	while (sl>0 && bl>0)
	{
		if (s[sl]>b[bl]) return 1;
		if (s[sl]<b[bl]) return -1;
		sl--;bl--;
	}
	if (sl==0) return 0;
	else return 1;
}
int main()
{
	int T,n;
	scanf("%d",&T);
	while (T--)
	{
		memset(ans,0,sizeof(ans));
		memset(a1,0,sizeof(a1));
		memset(a2,0,sizeof(a2));
		memset(c,0,sizeof(c));
		memset(b,0,sizeof(b));
		scanf("%d",&n);
		getchar();
		scanf("%s",&ss);
		int m=sqrt(n);
		int mm=m;
		int j=1;
		l1=0;
		point=0;
		while (mm)
		{
			a1[j++]=mm % 10;
			mm/=10;
			l1++;
		}
		point=0;
		mm=n;
		j=1;l2=0;
		while (mm)
		{
			b[j++]=mm%10;
			mm/=10;
			l2++;
		}
		c[1]=1;l3=1;
		int i;
		for (i=1;i<=130;i++)
		{
			for (j=1;j<=l3;j++)
				c[j]*=5;
			int kk=0;
			for (j=1;j<=l3;j++)
			{
				c[j]+=kk;
				kk=c[j]/10;
				c[j]=c[j]%10;
			}
			if (kk) c[++l3]=kk;
			point1=i;
			jia();
			/*for (j=l4;j>0;j--)
			{
				if (point2==j) cout<<".";
				printf("%d",a2[j]);
			}
			cout<<endl;*/
			l5=chengfa(); //平方后长度
			point3=2*point2; //平方后小数点位置
			/*for (j=l5;j>0;j--)
			{
				if (point3==j) cout<<".";
				printf("%d",s[j]);
			}
			cout<<endl;*/
			int re=gobj();
			if (re==1) //1:s>b -1:s<b
				ans[i-1]='0';
			else if (re==-1)
			{
				ans[i-1]='1';
				memset(a1,0,sizeof(a1));
				for (j=1;j<=l4;j++)
					a1[j]=a2[j];
				l1=l4;
				point=point2;
			}
			else break;
		}
		for (j=i;j<=130;j++)
			ans[i]='0';
		ans[130]='\0';
		//cout<<ans<<endl;
		cout<<strstr(ans,ss) - ans << endl;
	}
	return 0;
}
