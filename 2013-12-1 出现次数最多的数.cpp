#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

//ԭ��
//���ñ䳤����vector���洢�����ֵ��map���洢ÿ��ֵ���ֵĸ���
//��ѭ���� �Ƚ�value��ֵ��vector��Ȼ����map�в�vector�Ƿ���� ���������ĸ�����һ ����1
//��֮������ֵ�������ִ����Ƚϣ���ΪĬ��Ϊ0�����Ե�һ�����Ĵ����ض�������һ���ڵ�һ��ѭ�����Ϊ����������������Ϊ������max_num,����valueֵ����max_value
int main() {
	int num, value, max_value, max_num = 0;
	vector<int>number;
	map<int, int>counts;
	cin >> num;

	for (int i = 0; i < num; i++) {

		cin >> value;
		number.push_back(value);

//		if (counts.find(key) != counts.end()) ����д��һЩ �����Ҽ�ֵ���Ƿ��ҵ�ĩβ�� �����ʾû�������ֵ
		if (counts.count(value) > 0) {
			counts[value]++;
		} else
			counts[value] = 1;

		if (counts[value] > max_num || (counts[value] == max_num && value < max_value)) {
			max_value = value;
			max_num = counts[value];
		}
	}

	cout << max_value << endl;
//	cout << max_value << "���ִ���" << max_num << endl;
	return 0;
}