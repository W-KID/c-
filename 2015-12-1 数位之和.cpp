#include <iostream>
#include <string>
using namespace std;

//˼·:
//��string�洢������� Ȼ���ȡ����ķ�ʽ����string ��ÿһλ���ӳ�����string��һ���ַ������� ÿһλ����һ���ַ������ַ�-��0�����Խ��ַ�ת��Ϊ���� ��
int main() {
	string s;
	cin >> s;
	int sum = 0;

	for (int i = 0; i < s.length() ; i++) {

		int value = s[i] - '0';
		sum += value;
	}

	cout << sum;
	return 0;
}