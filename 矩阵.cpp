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
    //�����������
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
        x = y = 0;  //��A[0][0]��ʼ

        for (m = 0; m < N;)
        {   //m
            if (m == x) //�ص�
                m++;
            else
            {
                for (n = 0; n < N;)
                {   //n
                    if (n == y) //�ص�
                        n++;
                    else
                    {
                        if (array[x][y] + array[m][n] < array[x][n] + array[m][y])
                        {   //A[x][y] + A[m][n] �� A[x][n] + A[m][y] С ȡA[x][n]��A[m][y]�����ֵ
                            if (array[x][n] > array[m][y])
                                y = n;
                            else
                                x = m;
                            m = n = 0; //��ʼ��Ϊ0 ���±���
                        }
                        else if (array[x][y] < array[m][n])
                        {   //A[x][y] + A[m][n] �� ����A[m][n] > A[x][y] ȡA[m][n]
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
                        {   //A[x][y]��ʱ��������
                            n++;
                        }   //end if
                    }   //end if
                }   //end n
                
                //����n֮��A[x][y]��ʱ���� �����¸�m
                m++;
            }   //end if
        }   //end m

        //�������� �ҵ����ֵA[x][y]
        row[x] = y; //��¼����
        val[x] = array[x][y];   //��¼ֵ

        for (int i = 0; i < N; i++)
        {   //��A[x][y]������ �� Ϊ-1
            array[x][i] = array[i][y] = -1;
        }
        cnt++;
    }

    //��ʾ���
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
