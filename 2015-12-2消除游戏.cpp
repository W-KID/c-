#include <iostream>
using namespace std;
const int N = 30;

//90分思路：
//利用结构体存
struct node {
	int value;
	bool flag1 = false;
	bool flag2 = false;
} node_arr[N][N];

bool operator==(const node &a, const node &b) {
	if (a.value == b.value)
		return true;
	else
		return false;
}

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)

		for (int j = 0; j < m; j++) {

			int x;
			cin >> x;
			node_arr[i][j].value = x;
		}


	for (int i = 0; i < n; i++) {

		for (int j = 0; j < m - 1; j++) {

			if (node_arr[i][j] == node_arr[i][j + 1] && node_arr[i][j] == node_arr[i][j + 2]
			   ) {
				node_arr[i][j].flag1 = true;
				node_arr[i][j + 1].flag1 = true;
				node_arr[i][j + 2].flag1 = true;
			}
		}
	}

	for (int i = 0; i < m; i++)

		for (int j = 0; j < n - 1; j++) {

			if (node_arr[j][i] == node_arr[j + 1][i] && node_arr[j][i]  == node_arr[j + 2][i]
			   ) {
				node_arr[j][i].flag2 = true;
				node_arr[j + 1][i].flag2 = true;
				node_arr[j + 2][i].flag2 = true;
			}
		}

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < m ; j++) {

			if (node_arr[i][j].flag1 || node_arr[i][j].flag2) {
				node_arr[i][j].value = 0;
			}

			cout << node_arr[i][j].value << " ";
		}

		cout << endl;
	}

	return 0;
}
