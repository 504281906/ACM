#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 10000 + 4;

char str[2][MAX*3];
char input[MAX];
int L;
int lineNum;
int Num[2];
int visit[MAX*3];

int main()
{
    int T;
    int n;
    char ch1, ch2;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d", &L);
        getchar();
        Num[0] = Num[1] = 0;
        for(int i=0; i<2; ++i) {
            scanf("%s", input);
            int cur = 0;
            int length = strlen(input);
            for(int j=0; j<length;  ) {
                n = 0;
                while(input[j] <= '9' && input[j] >= '0') {
                    n = n*10 + (input[j++] - '0');
                }
                Num[i] += n;
                for(int k=1; k<=n; k++) {
                    str[i][cur++] = input[j];
                }
                j++;
            }
           // printf("%s\n", str[i]);
        }
        if(Num[0] != Num[1]) {
            printf("Case %d: No\n", t);
            continue;
        }
        lineNum = Num[0] / L;
        memset(visit, -1, sizeof(visit));
        bool res = true;
        for(int i=0; i<lineNum; ++i) {
            bool flag = false;
            for(int j=0; j<lineNum; ++j) {
                if(visit[j] != -1) {
                    continue;
                }
                int k;
                for(k=0; k<L; ++k) {
                    if(str[0][i+k*lineNum] != str[1][j+k*lineNum]) {
                        break;
                    }
                }
                if(k >= L) {
                    visit[j] = 1;
                    flag = true;
                    break;
                }
            }
            if(!flag) {
                res = false;
                break;
            }
        }
        if(res) {
            printf("Case %d: Yes\n", t);
        }else {
            printf("Case %d: No\n", t);
        }
    }
    return 0;
}
