#include <iostream>
using namespace std;
#include <math.h>
#include <vector>
//递归解决
/*int  maxlen(int x, vector<int> &arr ) {
	//使用 int 数组作为函数参数传递,无法获取数组的长度（因为数组退化成了指针，指向数组的首地址）
//而使用vector可以用vector.size来求长度，且要使用vector&这样可以避免复制元素，减少性能开销（如果元素量很大，则开销很大）
//或者使用const vector<int>&可以避免元素被更改
	if (x == arr.size() - 1)
		return 1;
	int max_len = 1;

	for (int i = x + 1; i < arr.size(); i++)

		if (arr[i] > arr[x])
			max_len = max(max_len, maxlen(i, arr) + 1);
	return max_len;
}*/

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);

	for (int i = 0; i < n; i++) {

		cin >> arr[i];
	}

	int count = 1;
	vector <int> dp(n, 1);


	for (int i = 1; i < n; i++) {

		for (int j = 0; j < i; j++) {

			if (arr[i] > arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
				count = max(count, dp[i]);
			}

		}
	}

//递归解决
//	count = maxlen(0, arr);

	cout << count;
	return 0;
}