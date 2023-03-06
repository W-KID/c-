#include <iostream>
#include <vector>
using namespace std;

//ע�� �ж� x����a ��С��b  ����ֱ��a<x<b ���� x>a&&x<b
//˼·��
//�����Ȱ�ÿ���£�����ǰ�������£�����������������δ洢��������
//Ȼ��������������������е��������������αȽ� ���ҳ����ϵ��·ݣ�һ����Ҫ�����жϣ�����ж�һ�£���ֱ�����һ�º������������
//Ȼ������������ȥǰһ���µ��������ó��ľ�������µľ���ڼ���
int sum(int month, int year) {
	int x1 = 31, x3 = 31, x4 = 30, x5 = 31, x6 = 30, x7 = 31, x8 = 31, x9 = 30, x10 = 31, x11 = 30, x12 = 31;
	int x2;

	if ((!(year % 4) && (year % 100)) || !(year % 400))
		x2 = 29;
	else
		x2 = 28;

	int all = 0;
	vector <int> mon = {x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12};

	for (int i = month; i > 0; i--) {

		all += mon[i - 1];
	}

	return all;

};

int main() {
	vector<int> mon_all;
	int y, d;
	cin >> y >> d;

	for (int i = 0; i < 12; i++) {

		mon_all.push_back(sum(i + 1, y));
	}

	int month;
	int day;

	for (int j = 1; j <= 12; j++) {

		if (d > 0 && d <= mon_all[0]) {
			month = 1;
			day = d;
			break;
		} else if (d > mon_all[j - 1] && d <= mon_all[j ]) {
			month = j + 1;
			day = d - mon_all[j - 1];
			break;
		}
	}

	cout << month << endl << day;
}