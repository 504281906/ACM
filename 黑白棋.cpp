#include <iostream>
using namespace std;

int qi[8][8];

void print_h(int h)
{
	cout << "     " << (char)(h+65) << "�c";
	for (int k=0; k<8; k++)
	{
		switch (qi[h][k])
		{   case 0: cout << "��"; break;
		    case 1: cout << "��"; break;
			case 2: cout << "��"; break;
		}
	}
	cout << "�f" << endl;
}

void print()
{
	cout << "        ����������������" << endl;
	cout << "      �X�h�h�h�h�h�h�h�h�[" << endl;
	for (int l=0; l<8; l++)
		print_h(l);
	cout << "      �^�k�k�k�k�k�k�k�k�a" << endl;
}

void xiugai(int hang, int lie, int heng, int zong, int num)
{
	for (int i=1; i<=num; i++)
	{
		hang+=heng; lie+=zong;
		qi[hang][lie]=3-qi[hang][lie];
	}
}

int panduan(int count, int shu, int se)
{
	int out; // out=0:������; out=1:����; out=2:�����������سɹ�;
    if (shu==0) out=0;
	else if (shu==(3-se)) out=1;
	     else if (count==1) out=0;
		      else out=2;
	return out;
}

bool chuli(int se, int i, int j, bool leixing)
{
	bool ctrl=false;
	int flag=1;
	int hang=i; int lie=j;
	int count=0;
	while (hang>0 && flag==1) // �����ж�
	{
		hang--;
		count++;
		flag=panduan(count, qi[hang][lie], se);
	}
	if (flag==2) if (leixing) {   xiugai(i,j,-1,0,count-1); ctrl=true; }
	             else ctrl=true;

	flag=1;
	count=0;
    hang=i; lie=j;
	while (hang<7 && flag==1) // �����ж�
	{
		hang++;
		count++;
		flag=panduan(count, qi[hang][lie], se);
	}
	if (flag==2) if (leixing) {   xiugai(i,j,1,0,count-1); ctrl=true; }
                 else ctrl=true;
	flag=1;
	count=0;
    hang=i; lie=j;
	while (lie>0 && flag==1) // �����ж�
	{
		lie--;
		count++;
		flag=panduan(count, qi[hang][lie], se);
	}
	if (flag==2) if (leixing) {   xiugai(i,j,0,-1,count-1); ctrl=true; }
                 else ctrl=true;
	flag=1;
	count=0;
    hang=i; lie=j;
	while (lie<7 && flag==1) // �����ж�
	{
		lie++;
		count++;
		flag=panduan(count, qi[hang][lie], se);
	}
	if (flag==2) if (leixing) {   xiugai(i,j,0,1,count-1); ctrl=true; }
                 else ctrl=true;
	flag=1;
	count=0;
    hang=i; lie=j;
	while (hang>0 && lie>0 && flag==1) // �������ж�
	{
		hang--; lie--;
		count++;
		flag=panduan(count, qi[hang][lie], se);
	}
	if (flag==2) if (leixing) {   xiugai(i,j,-1,-1,count-1); ctrl=true; }
                 else ctrl=true;
	flag=1;
	count=0;
    hang=i; lie=j;
	while (hang<7 && lie<7 && flag==1) // �������ж�
	{
		hang++; lie++;
		count++;
		flag=panduan(count, qi[hang][lie], se);
	}
	if (flag==2) if (leixing) {   xiugai(i,j,1,1,count-1); ctrl=true; }
                 else ctrl=true;
	flag=1;
	count=0;
    hang=i; lie=j;
	while (hang>0 && lie<7 && flag==1) // �������ж�
	{
		hang--; lie++;
		count++;
		flag=panduan(count, qi[hang][lie], se);
	}
	if (flag==2) if (leixing) {   xiugai(i,j,-1,1,count-1); ctrl=true; }
                 else ctrl=true;
	flag=1;
	count=0;
    hang=i; lie=j;
	while (hang<7 && lie>0 && flag==1) // �������ж�
	{
		hang++; lie--;
		count++;
		flag=panduan(count, qi[hang][lie], se);
	}
	if (flag==2) if (leixing) {   xiugai(i,j,1,-1,count-1); ctrl=true; }
                 else ctrl=true;
	if (ctrl && leixing) qi[i][j]=se;
	return ctrl;
}


int main()
{
	bool ctrl=false, ctrl_all=false, ctrl_1=false, ctrl_2=false;
	int j=0,i;
	int n=1;
	int se=2;
	char h,l;
	int lie, hang;	
	int count_hei=0; int count_bai=0;
	for (int i=0; i<8; i++)
		for (j=0; j<8; j++)
			qi[i][j]=0;
	qi[3][3]=1; qi[4][4]=1; qi[3][4]=2; qi[4][3]=2;
	while (n<61)
	{
		se=3-se;
		for (i=0; i<8; i++)
		{
			for (j=0; j<8; j++)
			{
				if (qi[i][j]==0)
				{
					ctrl_1=(ctrl_1 || chuli(1, i, j, false));
					if (ctrl_1 && ctrl_2) break;
					ctrl_2=(ctrl_2 || chuli(2, i, j, false));
					if (ctrl_1 && ctrl_2) break;
				}
			}
			if (ctrl_1 && ctrl_2) break;
		}
		if (!(ctrl_1 || ctrl_2)) break;
		if ((!ctrl_1) && ctrl_2 && (se==1)) continue;
		if ((!ctrl_2) && ctrl_1 && (se==2)) continue;
		count_hei=0; count_bai=0;
		for (i=0; i<8; i++)
			for (j=0; j<8; j++)
			{
			    if (qi[i][j]==1) count_hei++;
			    else if (qi[i][j]==2) count_bai++;
			}
		print();
		cout << "     �ڷ� " << count_hei << " : " << count_bai << " �׷�" << endl;
		if (se==1) cout << "     �ڷ�����" << endl;
		else cout << "     �׷�����" << endl;
		while (!ctrl)
		{
			cout << "     ";
			cin >> h >> l;
		    cout << endl;
		    hang=h-65; lie=l-48;
			if (qi[hang][lie]!=0) ctrl=false;
		    else ctrl=chuli(se, hang, lie, true);
			if (!ctrl) cout << "     �˴���������!" << endl;
		}
		ctrl=false; ctrl_1=false; ctrl_2=false;
		n++;
	}
	count_hei=0; count_bai=0;
	for (i=0; i<8; i++)
		for (j=0; j<8; j++)
		{
			if (qi[i][j]==1) count_hei++;
			else if (qi[i][j]==2) count_bai++;
		}
	print();
	cout << "     �ڷ� " << count_hei << " : " << count_bai << " �׷�" << endl;
	if (count_hei>count_bai) cout << "     �ڷ�ʤ!" << endl;
	else if (count_hei<count_bai) cout << "     �׷�ʤ!" << endl;
	     else cout << "     ��ƽ��!" << endl;
	cout << "     ��������˳�..." << endl;
	cin >> i;
	return 0;
}
