#include <iostream>
using namespace std;
//˼·��
//����һ��������� �������һ��ָ������ѣ�����k��������ʹǰ��Ҳ���˼��������ǲ�����
//��ʱҲҪ��ֳɹ��ˣ�����ʱ��Ҫ��һ���Ƿ��жϷֵ����һ�飬���ұ�����if�ֳɹ���else�жϣ�
//��Ϊ������һ����˹���k�����Ͳ���Ҫ���else�ж�

int main() {
	int n, k;//n�鵰�⣬ÿ���������ٷ�k������
	cin >> n >> k;
	int arr[n];

	for (int i = 0; i < n; i++) {

		cin >> arr[i];
	}

	int j = 0;
	int count = 0;
	int sum = 0;

	for (int j = 0; j < n; j++) {

		sum += arr[j];

		if (sum >= k) {
			count++;
			sum = 0;
		} else if (j == n - 1)
			count++;
	}

	cout << count << endl;
	return 0;
}