#include <iostream>
using namespace std;
const int N = 20;
const int M = 5;







































//第一种方法-二维数组思路：
//初始一个bool数组用于存储座位位置，初始值为false
//定义一个函数justify（x,arr[][5]）用于传入每次需要购买的座位票数
//函数内部 利用嵌套循环遍历 在第一层遍历中（即遍历行）先设置一个count用来计算剩余的空座位
//满足则进入再第二个循环（列数即座位）arr不为空则剩余座位数count++，直到结束第二个循环
//然后判断是否剩余座位数count>=需要占的座位数，如果满足则再进行遍历第三个循环
//在第三个循环中要满足按列遍历的数小于等于最大列数并且被占座位数要小于等于需要的座位数
//在循环中满足非空座位条件的，则将座位占了，且输出该座位号（当前序号+行数*5-1），然后占座位数加1
//直到占到满足需要的座位数结束
//void justify(int x, bool arr[][5]) {
//	for (int i = 0; i < N; i++) {
//
//		int count = 0;
//
//		for (int j = 0; j < M; j++) {
//
//			if (!arr[i][j]) {
//				count++;
//			}
//		}
//
//		if (count >= x) {
//			for (int k = 0, num = 0; k < M  && (num < x); k++) {
//
//				if (!arr[i][k]) {
//					arr[i][k] = true;
//					cout << k + i *M + 1 << " " ;
//					num++;
//				}
//
//
//			}
//
//			cout << endl;
//			break;
//		}
//
//	}
//}
//
//int main() {
//	int n;
//	cin >> n;
//	bool arr[N][M] = {false};
//
//	for (int i = 0; i < n; i++) {
//
//		int x;
//		cin >> x;
//		justify(x, arr);
//	}
//
//	return 0;
//}



//第二种方法，一维数组思路：
void justify(int num, int arr[]) {
	int count = 0;

	bool cont = false;

	for (int i = 0; i < N; i++) {

		if (M - arr[i] >= num) {
			for (int i = 0; i < num; i++)

				cout << M *i + +arr[i] << " ";

			break;
		}

		cout << endl;

		if (i = N - 1)
			cont = true;
	}

	if (cont) {
		for (int i = 0; i < N && num; i++) {

			if (M - arr[i]) {
				cout << M *i + ++arr[i] << " ";
				num--;
			}

		}

		cout << endl;
	}

}

int main() {
	int n;
	int arr[N] = {0};
	cin >> n;

	for (int i = 0; i < n; i++) {

		int num;
		cin >> num;
		justify(num, arr);
	}

	return 0;
}