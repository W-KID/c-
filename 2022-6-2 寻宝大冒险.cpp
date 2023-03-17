#include <iostream>
using namespace std;

struct node {
	int x, y;
};


int main() {
	int n, l, s; //���������������Ŀ���n���̻�ͼ�Ĵ�Сl�Ͳر�ͼ�Ĵ�Сs
	int tree[n + 1][n + 1] = {0};
	cin >> n >> l >> s;
	node tree_node[n];

	for (int i = 0; i < n; i++) {//����ÿ����������

		int x, y;
		cin >> x >> y;
		tree[x][y] = 1;
		tree_node[i] = {x, y};
	}

	int treasure_map[s + 1][s + 1] = {0};

	for (int i = s; i >= 0; i--) {

		for (int j = 0; j <= s; j++)

			cin >> treasure_map[i][j];//�ر�ͼ������
	}

	int count = 0;

	for (int i = 0; i < n; i++) {

		if (l - tree_node[i].x >= s || l - tree_node[i].y >= s) {
			for (int j = 0; j <= s; j++) {

				for (int k = 0; k <= s; k++) {

					if (tree[tree_node[i].x + j][tree_node[i].y + k] == treasure_map[j][k] && treasure_map[j][k] == 1)
						count += 1;
				}
			}
		} else
			count = 0;
	}

	cout << count;
	return 0;
}
