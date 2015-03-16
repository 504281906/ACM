// A Multiplication Game ���˷���Ϸ��
// PC/UVa IDs: 110505/847, Popularity: A, Success rate: high Level: 3
// Verdict: Accepted
// Submission Date: 2011-05-29
// UVa Run Time: 0.012s
//
// ��Ȩ���У�C��2011�����metaphysis # yeah dot net
//
// ����������Ϊ 162��Ϊ�˷�ֹ�Է��õ����ڵ��� 162����������һ����һ��Ӧ���������������� 162 / 
// 9 = 18��������ڵ��� 18����Է����Գ��� 9 ���ɴ��ڵ��� 162��������һ����һ��Ӧ�þ���ѡ����
// ��˺�õ����ڵ��� 9 ��������Ϊ��������һ������ѡ���Ǹ��������ս����³˻����ڵ��� 18����Ϊ 9 /
// 9 = 1����˭�ȳˣ�˭����ʤ��
// ���ڸ�������N������ Stan ��˵���ȴﵽ�� N������ʤ�����ع鵽��һ������� Stan �ȴﵽ N / 9��
// ��ʧ�ܣ�������һ������ Stan �ȴﵽ N / 9 / 2����ʤ����ʹ�õݹ������ɡ�
	
#include <iostream>
#include <cmath>
	
using namespace std;
	
void ones(int number, bool win)
{
	if (number <= 9 && win)
	{
		cout << "Stan wins." << endl;
		return;
	}
	if (number <= 2 && !win)
	{
		cout << "Ollie wins." << endl;
		return;
	}
	
	if (win)
		ones(ceil(number / 9.0), !win);
	else
		ones(ceil(number / 2.0), !win);
}
	
int main(int ac, char *av[])
{
	int number;
	
	while (cin >> number)
		ones(number, true);
	
	return 0;
}
