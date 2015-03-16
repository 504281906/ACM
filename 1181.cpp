#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    char s[100];
    while(scanf("%s",s)!=EOF)
	{
        bool bs[30][30]={false};
        bool cs[30]={false};
        int i,j,k;
        bs[s[0]-'a'][s[strlen(s)-1]-'a']=true;
        while(scanf("%s",s)!=EOF){
            if(strcmp(s,"0")==0)break;
            bs[s[0]-'a'][s[strlen(s)-1]-'a']=true;
        }        
        cs[1]=true;  
        for(k=0;k<26;k++)
		{
            for(i=0;i<26;i++)
			{
                if (cs[i]) continue;
                for(j=0;j<26;j++)
				{
                    if(!cs[j])continue;
                    if(bs[j][i])
					{
                        cs[i]=true;
                        break;
                    }
                }
            }
        }
        if(cs['m'-'a'])puts("Yes.");
        else puts("No.");
    }
    return 0;
}
