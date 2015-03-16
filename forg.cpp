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
int a[300000] ;
int cmp(int a,int b)
{
	return a<b;
}
int main()
{
	  int t,tt ,n,m,L;
	  scanf("%d",&t) ;
	  for(int tt = 1 ; tt <= t ;tt++)
	  {
	  	    scanf("%d%d%d",&n,&m,&L) ;
	  	    memset(a,0,sizeof(a));
	  	    for(int i = 1 ; i <= n ; i++)
	  	    {
	  	    	  scanf("%d",&a[i]) ;
	  	    }
	  	   	int ans = 0 ,wa=0;
	  	    if(n==0)
			  {
			  	            if( (m-wa) > L )
			  	            {
			  	             int x=(m-wa)/(L+1) ;  
					         ans = ans +2*x ;
					         wa = wa + x*(L+1) ;   
					        } 
			  	         if(m>wa) ans++; 
			  } 
else
{
			  int flag=0;
			a[n+1]=m ;
			sort(a+1,a+n+2);  
		//	for(int i = 0 ; i <= n+1 ; i++)  printf("%d ",a[i]);
	  	    for(int i =1 ; i <= n+1 ; i++)
	  	    {
	  	    	if(a[i] > wa)
	  	    	{   
	  	    	  if( (a[i] - wa) > L)
	  	    	  {    
                        if(!flag)
					    {
					        int x=(a[i]-wa)/(L+1) ;  
					         ans = ans +2*x ;
					         wa = wa + x*(L+1) ;   
							 if( (a[i]-wa)%(L+1) )  i-- ; 
						} 
						else 
						{
							 int x=(a[i]-wa)/(L+1) ;  
					         ans = ans +2*(x-1) ;
					         wa = wa + (x-1)*(L+1) ;   
							 if( (a[i]-wa)%(L+1) )  
							 {    
							 	   wa=wa+L ;ans++; i-- ;
							 	   if( (a[i]-wa) > L)
							 	    {
							 	      wa++ ; ans++ ;
							 	    }
							 	    flag=0;
							 }
							 else if( (a[i]-wa)%(L+1) == 0)
							 {
							 	    wa=wa+L ;ans++; i-- ;
							 	    flag=0;
							 }
							
						} 	  	 
	  	    	  }
	  	    	  else if((a[i]-wa) == L)  
					{
					   wa = wa+L ; ans++ ;
				    }
				  else if( (a[i]-wa) < L)
				  {
				  	   for(int j = i+1 ; j <= n+1 ;j++)
				  	      if(  (a[j]-wa) == L )
				  	      { 
				  	      	  wa = wa+L ; ans++;
				  	      	  i=j;
								  break;    
				  	      }
				  	      else if( (a[j]-wa) > L)
				  	      {
				  	      	     wa = a[j-1] ; ans ++ ; i=j-1;
				  	      	    //   wa = wa+L,ans++;i=j-1;
				  	      	    flag=1;
									 break;
				  	      }
				  }  
				}
			 	if(wa >= m)
				  break ;
			//	  printf("%d ",wa);
	  	    }
	  	    if(wa < m)
	  	       ans++;
	  	    	    
	  	    
}
	  	    if(L > m)  ans = 1 ;
	  	    
	  	 printf("Case #%d: %d\n",tt,ans);
	  	
	  }
	return 0;
}
