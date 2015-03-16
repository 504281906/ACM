#include<stdio.h>
#include<string.h>
const int Maxsize = 1024;
char num[Maxsize],a[Maxsize];
int sum[Maxsize];
int main( )
{
    int t,k;
    scanf( "%d\n",&t );
    k = t;
    while( k-- )
    {
           memset( sum,0,sizeof( sum ) );
           for( int i = 0; i < 2; ++i )
           {
                scanf( "%s",num );
                int len = strlen( num );
                for(i = 0; i < len; ++i )//ºËÐÄ
                {
                     sum[i] += num[len - i - 1] - '0';
                     if( sum[i] > 9 )
                     {
                         ++sum[i+1];
                         sum[i] -= 10;
                         }
                      
                }
                if( i == 0 )
                    strcpy( a,num );
           }
           int j = Maxsize - 1;
           while( !sum[j] )
                  --j;
           printf( "Case %d:\n",t - k );
           printf( "%s + %s = ",a,num );
           for( ; j >= 0; --j )
                printf( "%d",sum[j] );
           puts( "" );
           if( k )puts( "" );
           } 
    return 0;
}
