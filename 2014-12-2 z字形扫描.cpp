#include <iostream>
using namespace std;

//观察z字形走向可以看出 只有在第一行 或者第一列 或者最后一行 或者最后一列的情况是走一步，
//其它皆是未达到（第一行 或者第一列 或者最后一行 或者最后一列）斜着走多步
//于是可以给4种特殊情况单独输出 斜着统一输出（包括第一个（0,0）位置的元素）
//因为斜着走变的x，y坐标不是x+1，y-1 就是x+（-1），y-（-1） ,于是可以用dir=1还是-1来决定左上走还是右下走
//大循坏的条件应该是x,y>=0&&x,y<n(表示遍历对象在开辟范围内)
//最后走到x=n-1,y=n-1位置 由于都不满足上述条件，但还是会进行公共加减，最后造成越界，所以应判断坐标是否在这个位置以结束循环
int main() {
	int n;
	cin >> n;
	int arr[n][n];

	for (int i = 0; i < n; i++)

		for (int j = 0; j < n; j++) {

			int x;
			cin >> x;
			arr[i][j] = x;
		}

//dir 为1则往右下走，dir为-1则往右上跑
	int i = 0, j = 0, dir = 0;


	while (i >= 0 && i != n && j >= 0 && j != n) {
		cout << arr[i][j] << " ";

		if (i == n - 1 && j == n - 1) //防止超出边界
			break;

		//右边
		if (i == 0 && j != n - 1) {
			j = j + 1;
			dir = 1;
			cout << arr[i][j] << " ";
		}
		// 左下
		else if (j == 0 && i != n - 1) {

			i += 1;
			dir = -1;
			cout << arr[i][j] << " ";
		}
		//下
		else if (i == n - 1) {
			j++;
			cout << arr[i][j] << " ";
			dir = -1;
		}
		//右上
		else if (j == n - 1) {

			i++;
			cout << arr[i][j] << " ";
			dir = 1;
		}

		i += dir;
		j -= dir;

	}

	return 0;
}
//1 5 3