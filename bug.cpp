#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<deque>
#include<cstdlib>
using namespace std;
typedef long long INT;
const INT MOD = 1000000007; 
const int maxn = 2000000+5;
char str[maxn],temp[maxn];
int get_num(INT s,INT t)
{
    for(int i = 0;i < t;++i)
    {
        s = s >> 1;
        if(s == 0)
        return 0;
    }
    return s;
}
int main()
{
	//freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
    while(gets(temp))
    {
        if(temp[0] == '#')
        break;
        int len = strlen(temp),f = 0;
        for(int i = 0;i < len; ++i)
        if(temp[i] != ' ')
        str[f++] = temp[i];
        str[f] = NULL;
        len = f;
        deque<INT> que1;
        deque<char> que2;
        //预处理
        for(int i = 0;i < len-2;++i)
        if(str[i] == '>' && str[i+1] == '>' && str[i+2] != '>')
        str[i] = str[i+1] = '^';
        char ss[20];       //缓存数字
        for(int i = 0;i < len;++i)
        {
            if(str[i] == 'S'  || str[i] == 's')
            {
                i++;
                que2.push_front('<');
            }
            if(str[i] == '>')
            {
                INT tt = *que1.begin();
                que1.pop_front();
                que2.pop_front();    //计算完后把'<'弹出来
                tt *= tt;
                tt %= MOD;
                if(*que2.begin() == '^')
                {
                    INT tt2 = *que1.begin();
                    que1.pop_front();
                    que1.push_front(get_num(tt2,tt));
                    que2.pop_front();
                }
                else que1.push_front(tt);
            }
            if(str[i] == '^')
            {
                i++;
                que2.push_front('^');
            }
            if(str[i] >= '0' && str[i] <= '9')
            {
                int ll = 0;
                while(str[i] >= '0' && str[i] <= '9')
                {
                    ss[ll++] = str[i];
                    i++;
                }
                i--;
                ss[ll] = NULL;
                int tt = atoi(ss);
                if(*que2.begin() == '^')
                {
                    int tt2 = *que1.begin();
                    que1.pop_front();
                    que2.pop_front();
                    que1.push_front(get_num(tt2,tt));  //get_num计算tt2 >> tt之后压回到栈中
                }
                else que1.push_front(tt);
            }
        }
        while(!que2.empty())
        {
            if(*que2.begin() == '^')
            {
                que2.pop_front();   //现在只可能剩下^
                int tt1 = *que1.begin();
                que1.pop_front();
                int tt2 = *que1.begin();
                que1.pop_front();
                que1.push_front(get_num(tt2,tt1));
            }
    /*        else if(*que2.begin() == '>')
            {
                INT tt = *que1.begin();
                que1.pop_front();
                tt *= tt;
                tt %= MOD;
                que1.push_front(tt);
                que2.pop_front();
                que2.pop_front();
            }*/
        }
        printf("%d\n",*que1.begin());
        que2.clear();
        que1.clear();
    }
    return 0;
}
