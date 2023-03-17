#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;


//数组和vector不能用{}直接初始化所有元素为同一个元素
// 原理：
//创建两个数组 分别控制前行的步数和方向
//对每个小球进行遍历 根据前行方向前进步数  又因为他们位置是偶数 所以不可能一个小球动了 会马上撞到其它小球
//第K个小球动完后 依次遍历1-k-1个小球，看是否有相撞的，有则取反他们的方向
int main() {
	int n, l, t;
	vector<int>sphere;

	cin >> n >> l >> t;
	bool arr[n];//正方向
	memset(arr, true, sizeof(arr));

	for (int i = 0; i < n; i++) {

		int value;
		cin >> value;
		sphere.push_back(value);
	}

	while (t--) {
		for (int i = 0; i < n; i++) {

			if (arr[i])
				sphere[i]++;
			else
				sphere[i]--;

			if (sphere[i] > l) {
				sphere[i] = l - 1;
				arr[i] = !arr[i];
			}

			if (sphere[i] < 0) {
				arr[i] = !arr[i];
				sphere[i] = 1;
			}

			for (int j = 0; j < i; j++) {

				if (sphere[j] == sphere[i]) {
					arr[i] = !arr[i];
					arr[j] = !arr[j];
					break;
				}
			}


		}


	}

	for (int i = 0; i < n; i++) {

		cout << sphere[i] << " ";

	}


	return 0;
}