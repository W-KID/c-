#include <iostream>
using namespace std;
#include <vector>

//��ѭ����ÿ�������������vector�����У�Ȼ������˫��Ƕ��ѭ����ÿ����ȡ������ʣ�µıȽ� ���Ƿ����෴����
int main() {
	int a, num, count = 0;
	vector<int>all;
	cin >> num;

	for (int i = 0; i < num; i++) {

		cin >> a;
		all.push_back(a);
	}

	for (int i = 0; i < num; i++) {

		for (int j = i + 1; j < num; j++) {

			if (all[i] == (-all[j])) {
				count++;
				break;
			}
		}
	}

	cout << count << endl;
	return 0;
}