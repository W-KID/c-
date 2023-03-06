#include <iostream>
using namespace std;
const int N = 101;

//原理：
//计算总面积 可以看成计算每个像素点的面积，最后求总和（因为有重叠部分，所以按只要像素点有值则加1）
int main() {
	int index_Arr[N][N] = {0};
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {

		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		for (int i = x1; i < x2; i++)

			for (int j = y1; j < y2; j++)

				index_Arr[i][j]++;
	}

	int area = 0;

	for (int i = 0; i < N; i++)

		for (int j = 0; j < N; j++) {

			if (index_Arr[i][j])
				area++;
		}

	cout << area << endl;;

	return 0;
}