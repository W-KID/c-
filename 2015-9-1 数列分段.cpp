#include <iostream>
#include <vector>
using namespace std;

//˼·��
//�����������������
//Ȼ��ѭ��������ȡ��һ�������ܸ�����1����i��ʾ�´�����Ҫ�ߵĲ�����
//��k���浱ǰ����Ԫ�ص���� ��k��k+1��Ԫ�رȽ� ��һ����i+1��ֱ����һ��Ϊֹ
//��ʱ������ž�Ϊԭ����ţ�i ����ѭ��
//���ѭ������������ܸ���
int main() {
	int n;
	vector<int>index;
	int count = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {

		int x;
		cin >> x;
		index.push_back(x);
	}

	int j = 0;

	while (j < n) {
		count++;
		int i = 1;
		int k = j;

		while (index[k] == index[k + 1]) {
			i++;
			k++;
		}

		j = j + i;
	}

	cout << count;
	return 0;
}