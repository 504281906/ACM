#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <assert.h>
#include <algorithm>
#define MAX 1234567890
#define MIN -1234567890
#define exps 1e-8
#define MOD 1000000007

using namespace std;
const int maxn = 2000000+5;
int i, k;
int OPE[] = {1, 2}; /// 1 ����ƽ����2 ��������
char tmp[maxn];
char str[maxn]; ///�޿ո�ı��ʽ
int num[maxn]; ///����ջ
int ope[maxn]; ///����ջ
int numptr; ///ָ������ջ��
int opeptr; ///ָ�����ջ��

int number()
{
        int t = 0;
        char n[108];
        memset(n, 0, sizeof(n));
        int tans;
        while (str[i] >= '0' && str[i] <= '9')
        {
                n[t++] = str[i++];
        }
        n[t] = NULL;
       // sscanf(n, "%d", &tans);
        i--;
        return atoi(n);
}

void rightmove()
{
	opeptr--;
	int temp = num[numptr--],temp2 = num[numptr--];
	while(temp--)
	{
		temp2 = temp2 >> 1;
		if(temp2 == 0)
		{
			num[++numptr] = 0;
			return;
		}
	}
	num[++numptr] = temp2;
	
/*		
//        cout << "���� ��\n";
//        cout << "ջ����һλ " << num[numptr-1] <<" ���� "<<num[numptr] << " ��Ϊ ";
        ope[opeptr--] = 0;
        if(num[numptr] > 30) num[numptr-1] = 0;
        else num[numptr-1] = num[numptr-1] >> num[numptr];
//        cout << num[numptr-1];
//        cout << "���� ����" << num[numptr] << endl;
        num[numptr--] = 0;*/
        
}

int main()
{
      // freopen("in.txt", "r", stdin);
      //  freopen("outt.txt","w",stdout);

        while (gets(tmp) && tmp[0] != '#')
        {
        		memset(str,0,sizeof(str));
                int ans = 0;
                int lent = strlen(tmp);
                memset(str, 0, sizeof(str));
                for (i = 0, k = 0; i < lent; i++) ///��ȥ�ո�
                {
                        if(tmp[i] != ' ') str[k++] = tmp[i];
                }      
                str[k] = '\0';  ////////////////////////////////                
//                printf("%s\n", str);
                int len = k;
                numptr = -1;
                opeptr = -1;
         //       memset(num, 0, sizeof(num));     //��û��Ҫ///////////////////////////     
          //      memset(ope, 0, sizeof(ope));
//                cout << endl;
                for (i = 0; i < len; i++)
                {
                        if(str[i] == 'S') ///ƽ��
                        {
                                ope[++opeptr] = 1;
                                i++;
//                                cout << "ƽ�� ��\n";
                        }
                        else if(str[i] >= '0' && str[i] <= '9') ///����
                        {
                                num[++numptr] = number();
                         //       printf("heheh %d\n",num[0]);
//                                cout << "���ֽ� ��" << num[numptr] << endl;
                                while (opeptr >= 0 && ope[opeptr] == 2) //�����ڲ���ջ��
                                {
                                        rightmove();
                                }
                        }
                        else if(str[i] == '>')
                        {
                                if(str[i+1] == '>' && (i + 2) < len && (str[i+2] == 'S' || (str[i+2] >= '0' && str[i+2] <= '9'))) ///����     /////////////////////
                                {
//                                        cout << "���� ��\n";
										if(str[i+2] == 'S')     ////////// //////////////////
										{
                                        	ope[++opeptr] = 2;
                                        	i++;
                                        }
                                        else 
                                        {
                                        	i+= 2; ///////////////////////////
											ope[++opeptr] = 2;	
                                        	num[++numptr] = number();
                                        //	printf("haha %d\n",num[numptr]);
                                        	rightmove();
                                        }
                                        	
                                }
                                else
                                {
//                                        cout << num[numptr] << " ��Ϊ ";
                                        long long s = num[numptr];
                                        s = s * s % MOD;
                                        num[numptr] = s;
                                        ope[opeptr--] = 0;
//                                        cout << num[numptr] << endl;
//                                        cout << "ƽ�� ��\n";

                                      //  while (ope[opeptr] == 2) {rightmove();}
                                      while(opeptr >= 0 && ope[opeptr] == 2) rightmove();
                                }
                        }
                }
                printf("%d\n", num[numptr]);
        }
        return 0;
}
