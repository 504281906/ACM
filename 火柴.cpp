#include<iostream>

#include<cstring>

#include<algorithm>

 

int MIN(int a,int b) { if( a<b )  return a;  else return b; }

int MAX(int a,int b) { if( a>b )  return a;  else return b; }

#define CLR(NAME,VALUE) memset(NAME,VALUE,sizeof(NAME))

 

using namespace std;

 

const int MAXPRI=10000;

bool isNotPri[MAXPRI];

int  priList[MAXPRI],priNum;

 

void CalPri() {  //线性筛法

       int i,j;

       memset(isNotPri,0,sizeof(isNotPri));

       isNotPri[0]=isNotPri[1]=1;  //not prime

       for(i=4;i<MAXPRI;i+=2) {

              isNotPri[i]=1;

       }

 

       priNum=0;

       for(i=3;i<MAXPRI;i+=2) {

              if( !isNotPri[i] ) {

                      priList[priNum++]=i;

              }

              for(j=0;j<priNum&&i*priList[j]<MAXPRI;++j) {

                     isNotPri[i*priList[j]]=1;

                     if( i%priList[j]==0 ) {

                            break;

                     }

              }

       }

}

 

 

const int M=1000000007;

const int LEN=2000000+10;

const int num[]={6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

 

int n,m;

int dp[LEN];

 

inline int& diArr(int i,int j) {

       return dp[i*m+j];

}

 

int main() {

        CalPri();

        int ca,i,j,k,tn,tm;

        cin>>ca;

        while( ca-- ) {

               cin>>n>>m;

               memset(dp,0,sizeof(dp));

 

               diArr(0,0)=1;

               for(i=0;i<n;++i) {

                      for(j=0;j<m;++j) {

                             for(k=0;k<10;++k) {  //只有十种数字选择

                                    if( i==0 && k==0 ) continue;  

 

                                    tn=i+num[k];

                                    if( tn>n ) continue;

 

                                    tm=(j*10+k)%m;   //注意是加K,而不是NUM[K]

                                    diArr(tn,tm)=(diArr(tn,tm)+diArr(i,j))%M;

                             }

                      }

               }

 

               int ans=0;

               for(i=2;i<m;++i) {

                      if( !isNotPri[i] ) {

                             ans=(ans+diArr(n,i))%M;

                      }

               }

 

               cout<<ans<<endl;

        }

   

     return 0;

 

}



