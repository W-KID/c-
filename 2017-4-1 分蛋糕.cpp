#include <iostream>
using namespace std;
//思路：
//考虑一种特殊情况 假如最后一块分给了朋友，不够k重量（即使前面也分了加起来还是不够）
//此时也要算分成功了（即这时候要加一个是否判断分到最后一块，并且必须是if分成功的else判断）
//因为如果最后一块分了过了k重量就不需要这个else判断

int main() {
	int n, k;//n块蛋糕，每个朋友至少分k重量；
	cin >> n >> k;
	int arr[n];

	for (int i = 0; i < n; i++) {

		cin >> arr[i];
	}

	int j = 0;
	int count = 0;
	int sum = 0;

	for (int j = 0; j < n; j++) {

		sum += arr[j];

		if (sum >= k) {
			count++;
			sum = 0;
		} else if (j == n - 1)
			count++;
	}

	cout << count << endl;
	return 0;
}