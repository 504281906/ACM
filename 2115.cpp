#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct ss
{
	int fen,miao;
	char name[1000];
	int pai;
}s[10000];
bool cmp(ss a,ss b)
{
	if(a.fen!=b.fen) return a.fen<b.fen;
	else if(a.miao!=b.miao)return a.miao<b.miao;
	else 
	{
		if(strcmp(a.name,b.name)<0) return 1;
		else return 0;
	}
}
int main()
{
	int n,ji=1;
	scanf("%d",&n);
	while(n!=0)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%s",&s[i].name);
			scanf("%d:%d",&s[i].fen,&s[i].miao);
		}
		qsort(s,s+n,sizeof(s),cmp);
		s[0].pai=1;
		for(int i=1;i<n;i++)
		{
			if(s[i].fen==s[i-1].fen&&s[i].miao==s[i-1].miao) s[i].pai=s[i-1].pai;
			else s[i].pai=i+1;
		}
		cout<<"Case #"<<ji<<endl;
		for(int i=0;i<n;i++)
		{
			cout<<s[i].name<<" "<<s[i].pai<<endl;
		}
		ji++;
		cin>>n;
		if(n!=0) cout<<endl; 
	}
	return 0;
}
