#include <iostream>
#include <vector>
using namespace std;





//ԭ��
//��һ�ַ����������α����Ƚ�
//�ص㿼�� ֻ��ͬ������Ҳ���м��� ���� 4444 �����м��������Լ�
//int main() {
//	int  n;
//	cin >> n;
//	vector<int> num;
//
//	for (int i = 0; i < n; i++) {
//
//		int x;
//		cin >> x;
//		num.push_back(x);
//	}
//
//	bool found = false;
//
//	for (int i = 0; i < n; i++) {
//
//		int  max = 0, min = 0;
//
//		for (int j = 0; j < n; j++) {
//
//			if (j == i)
//				continue;
//
//			else if (num[j] > num[i]) {
//				max++;
//			} else if (num[j] < num[i])
//				min++;
//		}
//
//		if (max == min  ) {
//			cout << num[i] << endl;
//			found = true;
//			break;
//		}
//
//
//	}
//
//	if (!found)
//		cout << -1 << endl;
//
//	return 0;
//}
//�ڶ��ַ��� �������� ��Ϊ������м����Ļ���һ������������м䣬����Ϊ���ʣ��������ұ�ʣ�����
//��������ʣ����� �����ʣ�������һ������ұ���ʣ����� ���ұ�ʣ�������һ
//�жϳ�ȥ�м������������ظ�ֵ�� ��ߵ�ʣ������Ƿ�����ұ�ʣ�����
#include <algorithm>

int main() {
	int n;
	cin >> n;
	vector<int>num;

	for (int i = 0; i < n; i++) {

		int x;
		cin >> x;
		num.push_back(x);
	}

	sort(num.begin(), num.end());
	int mid = n / 2;
	int left_count = mid;
	int right_count = n - 1 - mid;

	for (int i = 0; i < mid; i++) {

		if (num[mid] == num[i])
			left_count--;
	}

	for (int j = mid + 1; j < n; j++) {

		if (num[mid] == num[j])
			right_count--;
	}

	if (left_count == right_count)
		cout << num[mid] << endl;
	else
		cout << "-1" << endl;
	return 0;

}