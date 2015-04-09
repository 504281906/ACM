#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
char c[510];
int ff(char a[510],char b[510])
{
	int cc[510];
	int la,lb,k; 
	memset(cc,0,sizeof(cc));
	la=strlen(a)-1;
	lb=strlen(b)-1;
	k=la+1;
	int t=0;
	while (k--)
	{
		if (lb>=0)
		cc[t]=(a[la--]-b[lb--]);
		else 
		cc[t]=a[la--]-'0';
		if (cc[t]<0)
		{
			a[la]--;
			cc[t]+=10;
		}
		t++;
	}
	while (cc[t]==0) t--;
	int ff=t;
	memset(c,0,sizeof(c));
	for (int j=t;j>=0;j--)
	c[ff-j]=cc[j]+'0';
	c[ff+1]='\0';
	return ff+1;
}
int main()
{
	char a[510],b[510],f[510];
	while (cin>>a>>b)
	{
		int num=0,T=0;
		int la=strlen(a);
		int lb=strlen(b);
		if (la<lb || la==lb && strcmp(a,b)<0)
			cout<<"0"<<" "<<a<<endl;
		else 
		{
			int i;
			for (i=0;i<lb;i++)
				c[i]=a[i];
			c[i]='\0';
			if (strcmp(c,b)<0)
				{
					c[i++]=a[i];
					c[i]='\0'; 
				} 
			while (i<=la)
			{
				int h;
				while (1)
				{
					num++;
					h=ff(c,b);
					if (strlen(c)<strlen(b) || strlen(c)==strlen(b) && strcmp(c,b)<0)
						break;
				}
				f[T++]=num+'0';
				num=0;
				while (1)
				{
					c[h++]=a[i];
					c[h]='\0';
					int j=0;
					while (c[0] =='0' && strlen(c)!=1)  
    				{
        				for(j=0;j<strlen(c);j++)  
            			c[j]=c[j+1];  
    				}
					i++;
					if (strlen(c)>strlen(b) ||(strlen(c)==strlen(b) && strcmp(c,b)>=0) || i==la+1)
						break;
					f[T++]='0';
				}
			}
			f[T++]='\0';
			cout<<f<<" ";
			int l=strlen(c)-1;
			while (c[l]-'0'==0) l--;
			if (l+1)
			cout<<c<<endl;
			else 
			cout<<endl;
		}
	}
	return 0;
}
