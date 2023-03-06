#include <iostream>
#include <vector>
using namespace std;

//原理
//循环遍历满足条件的（大于前一个和后一个 或者小于前一个和后一个）
int main() {
	int n;
	vector<int>num;
	cin >> n;

	for (int i = 0; i < n; i++) {

		int x;
		cin >> x;
		num.push_back(x);
	}

	int count = 0;

	for (int j = 1; j < n - 1; j++) {

		if ((num[j - 1] > num[j] && num[j] < num[j + 1]) || (num[j - 1] < num[j] && num[j] > num[j + 1]))
			count++;
	}

	cout << count;
	return 0;
}