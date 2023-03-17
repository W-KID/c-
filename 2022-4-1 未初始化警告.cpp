#include <iostream>
#include <map>
#include <string.h>
using namespace std;

//思路
//关键在于 应该先判断y值在这个数组序号里是否存在，然后再存x值。避免x和y相等的情况
int main() {
	int n, k;
	cin >> n >> k;
	bool arr[n + 1] = {false};
	arr[0] = true;
	int count = 0;

	for (int i = 0; i < k; i++) {

		int x, y;
		cin >> x >> y;


		if (arr[y] == false) {
			count++;
		}


		arr[x] = true;
	}

	cout << count;

	return 0;
}