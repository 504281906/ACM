#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
	
using namespace std;
	
bool finished = false;	// ��ǰ�˳��ݹ�ı�־��
	
// ��ÿ��������Ϊ���ظ��ĵ��ʡ�
bool parse2word(string line, vector < string > &word)
{
	istringstream iss(line);
	string w;
	bool found;
	while (iss >> w)
	{
		found = false;
		for (int i = 0; i < word.size(); i++)
			if (w == word[i])
				found = true;
		if (!found)
			word.push_back(w);
	}
	
	return word.size() > 0;
}
	
bool cmp(char a, char b)
{
	return a < b;
}
	
// ����Ƿ�������������ĸӳ�䵽ͬһ������ĸ��
bool conflicts(string cipher)
{
	// ����������������ͬ��ĸ���������϶����ڡ�
	sort(&cipher[0], &cipher[0] + cipher.length(), cmp);
	
	for (int i = 0; i < cipher.length() - 1; i++)
		if (cipher[i] != '*' && cipher[i + 1] != '*' && 
					cipher[i] == cipher[i + 1])
			return true;
	
	return false;
}
	
// ���ݵ�ǰ���� cipher������ƥ�䵥�� d �� w��
bool match(string d, string w, string &cipher)
{
	// ���浱ǰ�����Ա㲻��ƥ��ʱ�ָ���
	string tmp = cipher;
	
	// ���ʳ��Ȳ�ͬ���϶��޷�ƥ�䡣
	if (d.length() != w.length())
		return false;
	
	// �������ĵ���d�����ĵ��� w ����ַ�����ƥ�䡣	
	for (int i = 0; i < w.length(); i++)
	{	
		// �������ַ� w[i] ���޶�Ӧ�����ַ�ƥ��ʱ���������ַ� w[i] �������ַ� d[i] ƥ�䡣
		if (cipher[w[i] - 'a'] == '*')
			cipher[w[i] - 'a'] = d[i];
		else
		{
			// �����ַ� w[i] ���������ַ�ƥ�䣬���⵱ǰ�������ַ� d[i] �Ƿ�
			// �������е���ͬ����Ϊ�������������ַ�ӳ��ͬһ�����ַ����ʵ����߲�ͬ
			// ʱ���� false��
			if (cipher[w[i] - 'a'] != d[i])
			{
				cipher = tmp;
				return false;
			}
		}
	}
	
	if (conflicts(cipher))
	{
		cipher = tmp;
		return false;
	}
	
	return true;
}
	
// ���ݻ�ȡ�����������
void output(string line, string cipher)
{
	for (int i = 0; i < line.length(); i++)
		if (line[i] == ' ')
			cout << ' ';
		else
			cout << cipher[line[i] - 'a'];
	cout << endl;
}
	
// ���ܡ�
void decipher(vector < string > &dict, vector < string > &word, int start, 
								string &cipher)
{
	// ���浱ǰ���룬�Ա㲻��ƥ��ʱ�ָ���
	string tmp = cipher;
	
	// ����Ƿ��Ѿ�ƥ�������е��ʡ�
	if (start == word.size())
	{
		// ��������Ƿ���ڳ�ͻ��
		finished = !conflicts(cipher);
		return;
	}
	
	// �����Ϊstart�ĵ��ʿ�ʼƥ�䡣
	for (int i = 0; i < dict.size(); i++)
		// �����ƥ��ɹ����� word[start]����ƥ�䵥�� word[start + 1]��
		if (match(dict[i], word[start], cipher))
		{
			// �ݹ���ǰƥ�䡣
			decipher(dict, word, start + 1, cipher);
			
			// ���ݱ�־�����Ƿ���ǰ�����ݹ顣
			// ��δƥ�䵽���һ�����ʣ��ָ�����Ϊ֮ǰ�����ֵ��
			if (finished)
				return;
			else
				cipher = tmp;
		}
}
	
int main(int argc, char *argv[])
{
	string line;
	int count;
	vector < string > dict;
	map < string, int > exist;
	map < string, int >::iterator it;
	vector < string > word;
	
	cin >> count;
	cin.ignore();
	
	// ���뵥���ֵ䣬ע��������ظ��ĵ��ʴ��ڡ�ʹ�� map ����߲������ܡ�
	for (int i = 0; i < count; i++)
	{
		getline(cin, line);
		it = exist.find(line);
		if (it == exist.end())
		{
			dict.push_back(line);
			exist.insert(make_pair< string, int >(line, dict.size() - 1));
		}
	}
	
	// �������ģ���ÿһ�н��н��롣
	while (getline(cin, line))
	{
		if (line.length() == 0)
		{
			cout << endl;
			continue;
		}
		
		word.clear();
		parse2word(line, word);
		
		finished = false;
		string cipher(26, '*');
	
		if (!(word.size() > dict.size()))
			decipher(dict, word, 0, cipher);
		
		output(line, cipher);
	}
	
	return 0;
}
