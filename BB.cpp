#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <queue>
using namespace std;
#define maxn 110//2

int main()
{
    //freopen("test.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    char a[maxn],b[maxn];
    while(scanf("%s%s",a,b )==2)
    {
        int al1[26]={0},al2[26]={0},l1=strlen(a),l2=strlen(b);
        for(int i=0;i<l1;i++){
            al1[ a[i]-'a' ]++;
        }
        for(int i=0;i<l2;i++){
            al2[ b[i]-'a' ]++;
        }
        int i,more=0;
        for( i=0;i<26;i++){
            if(al1[i]<al2[i]){
                printf("need tree\n");
                break;
            }
            else if(al1[i]>al2[i])more=1;
        }

        if(i==26){

            if(!more)printf("array\n");
            else {
                //sub

                int i,j=0,f=0;
                for( i=0;i<l2;i++)
				{
                        while(j<l1&&a[j]!=b[i])j++;
                        if(j==l1)
						{
							printf("both\n");
                            break;
                        }
                        j++;
                }
                if(i==l2)printf("automaton\n");
            }
        }

    }
    return 0;
}
