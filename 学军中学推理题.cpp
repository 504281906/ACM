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
#include <ctime>
#define LL __int64
#define eps 1e-8
#define pi acos(-1)
using namespace std;
int ma,mi,minx,maxx;
int a[15],g[5];
void find(){
	mi=11;
	ma=-1;
	for (int i=1;i<=4;i++){
		if (mi>g[i]){
			mi=g[i];
			minx=i;
		}
		if (ma<g[i]){
			ma=g[i];
			maxx=i;
		}
	}
}
int jugg3(){
	if (a[3]==1 && a[3]!=a[2] && a[3]!=a[4] && a[3]!=a[6]) return 0;
	if (a[3]==2 && a[6]!=a[2] && a[6]!=a[3] && a[6]!=a[4]) return 0;
	if (a[3]==3 && a[2]!=a[3] && a[2]!=a[4] && a[2]!=a[6]) return 0;
	if (a[3]==4 && a[4]!=a[2] && a[4]!=a[3] && a[4]!=a[6]) return 0;
	return 1;
}
int jugg4(){
	if (a[4]==1 && a[1]==a[5]) return 0;
	if (a[4]==2 && a[2]==a[7]) return 0;
	if (a[4]==3 && a[1]==a[9]) return 0;
	if (a[4]==4 && a[6]==a[10]) return 0;
	return 1;
}
int jugg5(){
	if (a[5]==1 && a[5]==a[8]) return 0;
	if (a[5]==2 && a[5]==a[4]) return 0;
	if (a[5]==3 && a[5]==a[9]) return 0;
	if (a[5]==4 && a[5]==a[7]) return 0;
	return 1;
}
int jugg6(){
	if (a[6]==1 && a[8]==a[2] && a[8]==a[4]) return 0;
	if (a[6]==2 && a[8]==a[1] && a[8]==a[6]) return 0;
	if (a[6]==3 && a[8]==a[3] && a[8]==a[10]) return 0;
	if (a[6]==4 && a[8]==a[5] && a[8]==a[9]) return 0;
	return 1;
}
int jugg7(){
	if (a[7]==1 && minx==3) return 0;
	if (a[7]==2 && minx==2) return 0;
	if (a[7]==3 && minx==1) return 0;
	if (a[7]==4 && minx==4) return 0;
	return 1;
}
int jugg8(){
	if (a[8]==1 && fabs(a[1]-a[7])!=1) return 0;
	if (a[8]==2 && fabs(a[1]-a[5])!=1) return 0;
	if (a[8]==3 && fabs(a[1]-a[2])!=1) return 0;
	if (a[8]==4 && fabs(a[1]-a[10])!=1) return 0;
	return 1;
}
int jugg9(){
	int k;
	if (a[1]==a[6]) k=0;
	else k=1;
	if (a[9]==1 && k==(a[5]==a[6])) return 0;
	if (a[9]==2 && k==(a[5]==a[10])) return 0;
	if (a[9]==3 && k==(a[5]==a[2])) return 0;
	if (a[9]==4 && k==(a[5]==a[9])) return 0;
	return 1;
}
int jugg10(){
	if (a[10]==1 && ma-mi==3) return 0;
	if (a[10]==2 && ma-mi==2) return 0;
	if (a[10]==3 && ma-mi==4) return 0;
	if (a[10]==4 && ma-mi==1) return 0;
	return 1;
}
int jugg(){
	find();
	if (jugg3()) return 0;
	if (jugg4()) return 0;
	if (jugg5()) return 0;
	if (jugg6()) return 0;
	if (jugg7()) return 0;
	if (jugg8()) return 0;
	if (jugg9()) return 0;
	if (jugg10()) return 0;
	return 1;
}
void go(){
	for (int q1=1;q1<=4;q1++){
		a[1]=q1;
		memset(g,0,sizeof(g));
		g[q1]++;
		for (int q2=1;q2<=4;q2++){
			a[2]=q2;
			g[q2]++;
			int k;
			switch(q2){
				case 1:{
					a[5]=3;
					g[3]++;
					k=3;
					break;
				}
				case 2:{
					a[5]=4;
					g[4]++;
					k=4;
					break;
				}
				case 3:{
					a[5]=1;
					g[1]++;
					k=1;
					break;
				}
				case 4:{
					a[5]=2;
					g[2]++;
					k=2;
					break;
				}
				default :break;
			}
			for (int q3=1;q3<=4;q3++){
				a[3]=q3;
				g[q3]++;
				for (int q4=1;q4<=4;q4++){
					a[4]=q4;
					g[q4]++;
					for (int q6=1;q6<=4;q6++){
						a[6]=q6;
						g[q6]++;
						for (int q7=1;q7<=4;q7++){
							a[7]=q7;
							g[q7]++;
							for (int q8=1;q8<=4;q8++){
								a[8]=q8;
								g[q8]++;
								for (int q9=1;q9<=4;q9++){
									a[9]=q9;
									g[q9]++;
									for (int q10=1;q10<=4;q10++){
										a[10]=q10;
										g[q10]++;
										if (jugg()) return;
										else {
											g[q10]--;
											continue;
										}
									}
									g[q9]--; 
								}
								g[q8]--;
							}
							g[q7]--;
						}
						g[q6]--;
					}
					g[q4]--;
				}
				g[q3]--;
			}
			g[k]--;
			g[q2]--;
		}
		g[q1]--;
	}
}
int main(){
	go();
	for (int i=1;i<=10;i++)
		printf("%d:%c\n",i,'A'+a[i]-1);
	return 0;
}
