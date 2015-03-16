#include<cstdio>
#include<cstring>
#include<map>
#include<vector>
#include<cmath>
#include<cstdlib>
#include<stack>
#include<queue>
#include <iomanip>
#include<iostream>
#include<algorithm>
using namespace std ;

char front,back,Left,Right,top,bottom ;
map<string,int>s; 
struct node
{
    char a,b,c,d,e,f ;
    int dep ;
}e;
 
 int check(struct node x)
 {
       if(x.a==top && x.b==bottom && x.c==Left && x.d==Right && x.e==front && x.f==back)
                return 1;
       else  return 0;           
 }
 
 int bfs(struct node x) 
 {
     queue<struct node >q;
     q.push(x) ;
     while(!q.empty())
     {
           struct node v,u ;
           u =q.front() ;
           q.pop();
           if(check(u))
              return u.dep ;
           for(int i = 1 ; i <= 4 ; i++)
           {
                  if(i==1)
                  {
                          char str[7] ;       
                             str[0]=v.a=u.d;
                             str[1]=v.b=u.c;
                       str[2]=v.c=u.a;
                       str[3]=v.d=u.b;
                       str[4]=v.e=u.e;
                       str[5]=v.f=u.f;          
                             v.dep=u.dep+1;
                       str[6]='\0' ;
                       if(!s[str])
                       {
                             // printf("%s\n",str);
                                s[str]=1;
                                q.push(v) ;
                       }
         
                  }else if(i==2)
                  {
                                char str[7] ;       
                             str[0]=v.a=u.c;
                             str[1]=v.b=u.d;
                       str[2]=v.c=u.b;
                       str[3]=v.d=u.a;
                       str[4]=v.e=u.e;
                       str[5]=v.f=u.f;          
                             v.dep=u.dep+1;
                       str[6]='\0' ;
                       if(!s[str])
                       {
                                s[str]=1;
                                q.push(v) ;
                       }
        
                  }else if(i==3)
                  {
                               char str[7] ;       
                             str[0]=v.a=u.f;
                             str[1]=v.b=u.e;
                       str[2]=v.c=u.c;
                       str[3]=v.d=u.d;
                       str[4]=v.e=u.a;
                       str[5]=v.f=u.b;          
                             v.dep=u.dep+1;
                       str[6]='\0' ;
                       if(!s[str])
                       {
                                s[str]=1;
                                q.push(v) ;
                       }
                      
                  }else if(i==4)
                  {
                             char str[7] ;       
                             str[0]=v.a=u.e;
                             str[1]=v.b=u.f;
                       str[2]=v.c=u.c;
                       str[3]=v.d=u.d;
                       str[4]=v.e=u.b;
                       str[5]=v.f=u.a;          
                             v.dep=u.dep+1;
                       str[6]='\0' ;
                       if(!s[str])
                       {
                                s[str]=1;
                                q.push(v) ;
                       }

                  }
           }
     }
     return 0;
 }
 
 int main()
 {   
   char a,b,c,d,e,f;
     while(~scanf("%c %c %c %c %c %c",&top,&bottom,&Left,&Right,&front,&back))
     {       getchar();
             scanf("%c %c %c %c %c %c",&a,&b,&c,&d,&e,&f) ;getchar();
            if(a==top && b==bottom && c==Left && d==Right && e==front && f==back)
                printf("0\n") ;
             else
             {
                     s.clear();
                     char str[7] ;
                     struct node x ;
                     str[0]=a;x.a=a;str[1]=b;x.b=b;str[2]=c;x.c=c;str[3]=d;x.d=d;str[4]=e;x.e=e;str[5]=f;x.f=f;str[6]='\0' ;
                     x.dep = 0 ;
                     s[str]=1;
                     int ans = bfs(x) ;
                     if(ans)
                        printf("%d\n",ans) ;
                     else printf("-1\n") ;   
             }  
        
     }
     return 0 ;
 }

