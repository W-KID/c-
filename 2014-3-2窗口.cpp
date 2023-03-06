#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//原理：
//1.由n，m分别接受窗口定点数 和点击次数 制造一个结构体数组node_Arr用以存储每个窗口的两对坐标和窗口位置序号
//2.每次输入的x，y将其与结构体数组遍历进行比较 将满足大于等于左下坐标点且小于等于右上坐标点的窗口位置序号输出 然后记录此结构体对象top_node
//3.依次将此结构体开始的每一个结构体赋值给上一个结构体，直到最后一个结构体赋值给上一个结构体
//4.再将top_node赋值给最后一个结构体完成 窗口位置的更迭。并且break这个循环（因为从高的位置向低位置遍历，高的满足了，就不用考虑低的）
//5.如果最后遍历完都没满足条件的，则输出IGNORED


//const int N = 15;
//int n, m;
//
//struct  node {
//	int x1, y1, x2, y2, weight ;
//} node_Arr[N];


//int main() {
//	cin >> n >> m;
//
//	for (int i = 0; i < n; i++) {
//
//		int x1, y1, x2, y2, weight;
//		cin >> x1 >> y1 >> x2 >> y2;
//		node_Arr[i] = {x1, y1, x2, y2, i + 1};
//	}
//
//	int top;
//	int x, y;
//
//	for (int j = 0; j < m; j++) {
//
//		cin >> x >> y;
//
//		for (int k = n - 1; k >= 0; k--) {
//
//			if (node_Arr[k].x1 <= x && node_Arr[k].x2 >= x && node_Arr[k].y1 <= y && node_Arr[k].y2 >= y) {
//				top = node_Arr[k].weight;
//				cout << top << endl;
//				auto top_node = node_Arr[k];
//
//				for (int t = k; t < n - 1; t++) {
//
//					node_Arr[t] = node_Arr[t + 1];
//				}
//
//				node_Arr[n - 1] = top_node;
//				break;
//			}
//
//			if (k == 0)
//				cout << "IGNORED" << endl;
//		}
//
//	}
//
//	return 0;
//}

const int N = 15;
int n, m;
struct  node {
	int x1, y1, x2, y2, weight ;
} node_Arr[N];

int  get_index(int x, int y) {
	for (int k = n - 1; k >= 0; k--) {

		if (node_Arr[k].x1 <= x && node_Arr[k].x2 >= x && node_Arr[k].y1 <= y && node_Arr[k].y2 >= y) {
			return k;
		}
	}

	return -1;

}

int main() {
	cin >> n >> m;
	int x1, y1, x2, y2;

	for (int i = 0; i < n; i++) {

		cin >> x1 >> y1 >> x2 >> y2;
		node_Arr[i] = {x1, y1, x2, y2, i + 1};

	}

	int top, x, y;

	for (int j = 0; j < m; j++) {

		cin >> x >> y;
		top = get_index(x, y);

		if (!(top + 1)) {
			cout << "IGNORED" << endl;
		} else {
			cout << node_Arr[top].weight << endl;
			auto top_node = node_Arr[top];

			for (int k = top; k < n - 1; k++) {

				node_Arr[k] = node_Arr[k + 1];
			}

			node_Arr[n - 1] = top_node;

		}
	}

	return 0;
}