#include <iostream>
#include <vector>
#include <string>
using namespace std;

//�ַ�ֻ��ռһ��λ�� char c='10' ����
//˼·:
//���ַ���s�������� Ȼ������ַ���s��ͬʱÿ����һ�������Ƿ��ڼ����λ�� ������������vector����isbn�У�ֻ��9λ���ӣ����һ�����棩
//������ÿһλ��Ч������total��ֵ��ֱ��sǰһλ����Ϊ���һ���������жϵģ�
//��totalȡ�����
//���ж�total�Ƿ����10 ����c��ֵΪΪ'X'��c����һ���û�s�е����һλ����������totalתΪ�ַ��͸�ֵ��c
//����ж�c�Ƿ����s���һλ���жϷ� �����滻s�����һλ ���s �������"Right"
//
int main() {
	string s;
	vector<int> isbn;
	int total = 0;
	char c;
	cin >> s;

	for (int i = 0, j = 0; i < s.length() - 1; i++) {

		if (i != 1 && i != 5 && i != 11) {
			isbn.push_back(s[i] - '0');
			total += isbn[j] * (j + 1);
			j++;
		}

	}

	total = total % 11 ;

//	vector<int>::iterator it;
//	it = isbn.end()- 1;
//	cout << s[12] << endl;
//	cout << total << endl;
	c = total == 10 ? 'X' : total + '0';

	if (c != s[12]) {
		s[12] = c;
		cout << s << endl;;
	} else
		cout << "Right";
	return 0;
}