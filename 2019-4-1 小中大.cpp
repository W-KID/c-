#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//˼·��
//ע����������ͱ���һλС�� ��printfĬ�Ͼ����������� .1f������һλС����
//mid��Ϊdouble���� ���������� ����int(mid)
int main() {
	int n;
	double mid;
	cin >> n;
	int arr[n];

	for (int i = 0; i < n; i++)

		cin >> arr[i];
	int max, min;

	if (arr[0] > arr[n - 1]) {
		max = arr[0];
		min = arr[n - 1];
	} else {
		max = arr[n - 1];
		min = arr[0];
	}

	if (n % 2 == 0) {
		mid = (arr[n / 2] + arr[(n / 2) - 1]) / 2.0;

		if ((mid - int(mid)) == 0)
			printf("%d %d %d", max, int(mid), min);
		else
			printf("%d %.1f %d", max, mid, min);
	}

	else {
		mid = arr[n / 2];

		printf("%d %d %d", max, int(mid), min);
	}

	return 0;
}