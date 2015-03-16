#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

const ll MOD = (ll)1e9+7;
const int MAXN = 100;

ll dp[MAXN][2];
char str[3][MAXN];

int main() 
{
		freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
    while (scanf("%s", str[0])!=EOF) {
        if ('0'==str[0][0]&&'\0'==str[0][1]) return 0;
        scanf("%s%s", str[1], str[2]);
        memset(dp, 0, sizeof(dp));
        int len = strlen(str[0]);
        dp[len][0] = 1;
        for (int l = len-1; l > 0; l--) //第l位
            for (int p = 0; p < 2; p++) 
			if (dp[l+1][p]>0) //进位
                for (int i = 0; i < 10; i++) 
				if ('?'==str[0][l] || i==(str[0][l]-'0'))  //a[l]
                    for (int j = 0; j < 10; j++) 
					if ('?'==str[1][l] || j==(str[1][l]-'0'))  //b[l]
                        if ('?'==str[2][l] || (i+j+p)%10==(str[2][l]-'0')) 
						{
                           // ll &now = dp[l][(i+j+p)/10];
                            dp[l][(i+j+p)/10] = (dp[l][(i+j+p)/10]+dp[l+1][p])%MOD;
                        }
        //最后一位不为0
        for (int p = 0; p < 2; p++) 
		if (dp[1][p]>0) //进位
            for (int i = 1; i < 10; i++) 
			if ('?'==str[0][0] || i==(str[0][0]-'0'))  //a[l]
                for (int j = 1; j < 10; j++) 
				if ('?'==str[1][0] || j==(str[1][0]-'0'))  //b[l]
                    if ('?'==str[2][0] || (i+j+p)%10==(str[2][0]-'0')) 
					{
                       // ll &now =now  ;
                        dp[0][(i+j+p)/10]= (dp[0][(i+j+p)/10]+dp[1][p])%MOD;
                    }

        printf("%lld\n", dp[0][0]);
    }
}
