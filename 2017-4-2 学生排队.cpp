#include <iostream>
using namespace std;

//重点注意两点 第一点 出队出的是学号 不是数组序号 所以首先要把对应学号的序号找到
//不要复用同一个变量名称 淦！！！

int main() {
	int num, k;
	cin >> num >> k;
	int arr[num + 1];

	for (int i = 1; i <= num; i++) {

		arr[i] = i;
	}

	for (int s = 0; s < k; s++) {

		int m, n, j, r;
		cin >> m >> n;

		for (int i = 1; i <= num; i++) {

			if (arr[i] == m)
				r = i;
		}



		if (n > 0) {
			arr[0] = m;

			for (j = r; j <  n + r; j++)

				arr[j] = arr[j + 1];

		} else if (n < 0) {
			arr[0] = m;

			for (j = r; j > r + n  ; j--)

				arr[j] = arr[j - 1];

		}

		arr[j] = arr[0];



	}

	for (int i = 1; i <= num; i++) {

		cout << arr[i] << " ";
	}




	return 0;
}
/*#include <iostream>
using namespace std;

//重点注意两点 第一点 出队出的是学号 不是数组序号 所以首先要把对应学号的序号找到
//m向前移动n（n<0）步的时候,由上一个位置代替当前位置向前遍历 只遍历到当前位置为m+n-1之前就行
// 因为该赋值是由前一个赋值给当前 所以序号只能走到前一个 即m+n+1
// m+n,m+n+1,m+n+2.....m-2,m-1,m;(n<0)
int main() {
	int num, k;
	cin >> num >> k;
	int arr[num + 1];

	for (int i = 1; i <= num; i++) {

		arr[i] = i;
	}

	for (int s = 0; s < k; s++) {

		int m, n, j, r;
		cin >> m >> n;

		for (int i = 1; i <= num; i++) {

			if (arr[i] == m)
				r = i;
		}



		if (n > 0) {
			for (j = r; j <  n + r ; j++)

				arr[j] = arr[j + 1];

		} else if (n < 0) {q

			for (j = r; j > r + n ; j--)

				arr[j] = arr[j - 1];

		}

		arr[r + n] = m ;



	}

	for (int i = 1; i <= num; i++) {

		cout << arr[i] << " ";
	}




	return 0;
}*/