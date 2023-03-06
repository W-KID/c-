#include <iostream>
using namespace std;

//思路
//题目即按行先输出最后一列直到第一列，则可以外部循环初值为最后一列 内部循环行从0开始 输出数组[行][列]
int main() {

	int n, m;
	cin >> n >> m;
	int rot[n][m];

	for (int i = 0; i < n; i++)

		for (int j = 0; j < m; j++) {

			int x;
			cin >> x;
			rot[i][j] = x;
		}


	for (int i = m - 1; i >= 0; i--) {

		for (int j = 0; j < n; j++)

			cout << rot[j][i] << " ";
		cout << endl;
	}

	return 0;

}