#include <iostream>
using namespace std;

int main() {
	int n, m; //��Ŀ����������ʦ����������m
	cin >> n >> m;
	int arr[n + 1];

	for (int i = 1; i <= n; i++) {

		cin >> arr[i]; //ÿ�������ȷ������ ��һ���� arr[1]
	}

	int c[n + 1]; //��ʾarr[i]��ǰ׺�˻���c2=arr[1]*arr[2],c0=1;
	c[0] = 1;

	for (int i = 1; i <= n; i++) {

		c[i] = c[i - 1] * arr[i];
	}

	int b[n + 1];
	b[1] = m % c[1] / c[0];

	for (int j = 2; j <= n; j++) {

		int sum = 0;

		for (int i = 0; i <= j - 2; i++)

			sum += c[i] * b[i + 1];
		b[j] = (m % c[j] - sum) / c[j - 1];

	}

	for (int i = 1; i <= n; i++) {

		cout << b[i] << " ";
	}


	return 0;
}