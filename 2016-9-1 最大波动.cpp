#include <iostream>
#include <vector>
using namespace std;

//原理：拿max记录最大差值
int main() {
	int num;
	vector<int> arr;
	cin >> num;


	for (int i = 0; i < num; i++) {

		int value;
		cin >> value;
		arr.push_back(value);
	}

	int max = abs(arr[1] - arr[0]);
	int d_value;

	for (int j = 1; j < num; j++) {

		d_value = abs(arr[j] - arr[j - 1]);

		if (d_value > max)
			max = d_value;
	}

	cout << max;
	return 0;
}