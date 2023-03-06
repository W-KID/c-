#include <iostream>
#include <vector>
using namespace std;

//思路：
//将输入的数存入数组
//然后循环从数组取出一个数，总个数加1，用i表示下次数组要走的步数，
//用k代替当前数组元素的序号 让k和k+1个元素比较 若一样则i+1，直到不一样为止
//此时数组序号就为原先序号＋i 继续循环
//最后循环结束，输出总个数
int main() {
	int n;
	vector<int>index;
	int count = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {

		int x;
		cin >> x;
		index.push_back(x);
	}

	int j = 0;

	while (j < n) {
		count++;
		int i = 1;
		int k = j;

		while (index[k] == index[k + 1]) {
			i++;
			k++;
		}

		j = j + i;
	}

	cout << count;
	return 0;
}