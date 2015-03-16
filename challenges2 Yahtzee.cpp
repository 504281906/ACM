#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
int a[15][10];
void DFS(int x)
{
	for (int i=0;i<13;i++)
	if (vs[i])
	{
		vs[i]=false;
		for (int j=0;j<13;j++)
		{
			switch (j)
			{
				case 0:{
					if (vf[j])
					{
						vf[j]==false;
						f0(a[i]);
						DFS(x+1);
					}
					break;
				}
				case 1:{
					if (vf[j])
					{
						vf[j]==false;
						f1(a[i]);
						DFS(x+1);
					}
					break;
				}
				case 2:{
					if (vf[j])
					{
						vf[j]==false;
						f2(a[i]);
						DFS(x+1);
					}
					break;
				}
				case 3:{
					if (vf[j])
					{
						vf[j]==false;
						f3(a[i]);
						DFS(x+1);
					}
					break;
				}
				case 4:{
					if (vf[j])
					{
						vf[j]==false;
						f4(a[i]);
						DFS(x+1);
					}
					break;
				}
				case 5:{
					if (vf[j])
					{
						vf[j]==false;
						f5(a[i]);
						DFS(x+1);
					}
					break;
				}
				case 6:{
					if (vf[j])
					{
						vf[j]==false;
						f6(a[i]);
						DFS(x+1);
					}
					break;
				}
				case 7:{
					if (vf[j])
					{
						vf[j]==false;
						f7(a[i]);
						DFS(x+1);
					}
					break;
				}
				case 8:{
					if (vf[j])
					{
						vf[j]==false;
						f8(a[i]);
						DFS(x+1);
					}
					break;
				}
				case 9:{
					if (vf[j])
					{
						vf[j]==false;
						f9(a[i]);
						DFS(x+1);
					}
					break;
				}
				case 10:{
					if (vf[j])
					{
						vf[j]==false;
						f10(a[i]);
						DFS(x+1);
					}
					break;
				}
				case 11:{
					if (vf[j])
					{
						vf[j]==false;
						f11(a[i]);
						DFS(x+1);
					}
					break;
				}
				case 12:{
					if (vf[j])
					{
						vf[j]==false;
						f12(a[i]);
					}
					break;
				}
			}
		}
	}
}
int main()
{
	int t=0;
	char s[20];
	while (gets(s)!=NULL)
	{
		if (strlen(s)<2) break;
		t++;
		sscanf(s,"%d %d %d %d %d",&a[t][0],&a[t][1],&a[t][2],&a[t][3],&a[t][4]);
		sort(a[t],a[t]+5);
		if (t==13)
		{
			t=0;
			memset(vs,true,sizeof(vs));
			memset(vf,true,sizeof(vf));
			DFS(0);
		} 
	}
	return 0;
}
