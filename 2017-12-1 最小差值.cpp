#include <iostream>
#include <algorithm>
//˼·����һ��min���洢��Сֵ Ȼ�����α����Ƚϲ�ֵ��min ����min
using namespace std;

int main() {
	int n;
	cin >> n;
	int arr[n];

	for (int i = 0; i < n; i++)

		cin >> arr[i];
	int min = abs(arr[0] - arr[1]);
	int m;

	for (int i = 0; i < n - 1; i++)

		for (int j = i + 1; j < n; j++) {

			m = abs(arr[i] - arr[j]);

			if (min > m)
				min = m;
		}

	cout << min << endl;
	return 0;
}