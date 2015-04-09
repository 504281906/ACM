#include <iostream>
#include <iomanip>
#include <time.h>
#include <cstdio> 
#include <algorithm>
#define N 3
#define MAX 50

using namespace std;

int main()
{
    int array[N][N];
    //产生随机数组
    srand( (unsigned)time( NULL ) );
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            array[i][j] = rand() % MAX;
        }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << setw(5) << array[i][j];
        cout << endl;
    }

    int row[N];
    int val[N];
    for (int i = 0; i < N; i++)
        row[i] = val[i] = 0;

    int x, y, m, n;
    for (int cnt = 0; cnt < N;)
    {
        x = y = 0;  //从A[0][0]开始

        for (m = 0; m < N;)
        {   //m
            if (m == x) //重叠
                m++;
            else
            {
                for (n = 0; n < N;)
                {   //n
                    if (n == y) //重叠
                        n++;
                    else
                    {
                        if (array[x][y] + array[m][n] < array[x][n] + array[m][y])
                        {   //A[x][y] + A[m][n] 比 A[x][n] + A[m][y] 小 取A[x][n]和A[m][y]的最大值
                            if (array[x][n] > array[m][y])
                                y = n;
                            else
                                x = m;
                            m = n = 0; //初始化为0 重新遍历
                        }
                        else if (array[x][y] < array[m][n])
                        {   //A[x][y] + A[m][n] 大 但是A[m][n] > A[x][y] 取A[m][n]
                            x = m;
                            y = n;
                            m = n = 0;
                        }
                        //else if (array[x][y] == -1)
                        //{
                        //    x = m;
                        //    y = n;
                        //    m = n = 0;
                        //}
                        else
                        {   //A[x][y]暂时符合条件
                            n++;
                        }   //end if
                    }   //end if
                }   //end n
                
                //遍历n之后A[x][y]暂时满足 继续下个m
                m++;
            }   //end if
        }   //end m

        //遍历结束 找到最大值A[x][y]
        row[x] = y; //记录坐标
        val[x] = array[x][y];   //记录值

        for (int i = 0; i < N; i++)
        {   //置A[x][y]所在行 列 为-1
            array[x][i] = array[i][y] = -1;
        }
        cnt++;
    }

    //显示结果
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += val[i];
        cout << "A[" << i << "][" << row[i] << "]";
        if (i == N - 1)
            cout << " = ";
        else
            cout << " + ";
    }
    cout << sum << endl;
    
    for (int i = 0; i < N; i++)
    {
        cout << val[i];
        if (i == N - 1)
            cout << " = ";
        else
            cout << " + ";
    }
    cout << sum << endl;

    return 0;
}
