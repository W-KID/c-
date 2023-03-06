#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//ԭ��
//1.��n��m�ֱ���ܴ��ڶ����� �͵������ ����һ���ṹ������node_Arr���Դ洢ÿ�����ڵ���������ʹ���λ�����
//2.ÿ�������x��y������ṹ������������бȽ� ��������ڵ��������������С�ڵ������������Ĵ���λ�������� Ȼ���¼�˽ṹ�����top_node
//3.���ν��˽ṹ�忪ʼ��ÿһ���ṹ�帳ֵ����һ���ṹ�壬ֱ�����һ���ṹ�帳ֵ����һ���ṹ��
//4.�ٽ�top_node��ֵ�����һ���ṹ����� ����λ�õĸ���������break���ѭ������Ϊ�Ӹߵ�λ�����λ�ñ������ߵ������ˣ��Ͳ��ÿ��ǵ͵ģ�
//5.����������궼û���������ģ������IGNORED


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