#include <iostream>
using namespace std;

//˼·
//��Ŀ��������������һ��ֱ����һ�У�������ⲿѭ����ֵΪ���һ�� �ڲ�ѭ���д�0��ʼ �������[��][��]
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