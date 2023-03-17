#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
//原理：
//采用递归的思想解决最值问题
//首先找出递归边界，即总值小于包邮价格时结束递归
//因为要找的是最小值 ，即可能有多种包邮组合结果，所以返回值应该是由当前递归的最小值和公告最小值比较出的最小值
//递归的时候减去的书不能重复计算，即新的递归遍历的位置应该是基于上次的位置加1

int min_sum(int sum, vector<int> &book, int x, int j) {
	if (sum < x)
		return 0;
	int sum1;

	for (int i = j; i < book.size(); i++) {

		if (sum - book[i] >= x) {
			sum1 = min_sum(sum - book[i], book, x, i + 1);
		}

	}

	return min(sum1, sum)

}



int main() {
	int n, x;
	cin >> n >> x;
	vector<int> book(n);
	int sum = 0;

	for (int i = 0; i < n; i++) {

		cin >> book[i];
		sum += book[i];
	}

	cout << min_sum(sum, book, x, 0);

	return 0;
}