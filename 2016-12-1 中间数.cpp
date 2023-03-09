#include <iostream>
#include <vector>
using namespace std;





//原理
//第一种方法利用两次遍历比较
//重点考虑 只有同样的数也有中间数 比如 4444 他的中间数就是自己
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
//第二种方法 利用排序 因为如果有中间数的话，一定在有序队列中间，两边为左边剩余的数和右边剩余的数
//如果左边有剩余的数 则左边剩余的数减一；如果右边有剩余的数 则右边剩余的数减一
//判断除去中间数（可能有重复值） 左边的剩余的数是否等于右边剩余的数
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