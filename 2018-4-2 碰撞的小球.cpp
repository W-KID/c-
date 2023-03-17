#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;


//�����vector������{}ֱ�ӳ�ʼ������Ԫ��Ϊͬһ��Ԫ��
// ԭ��
//������������ �ֱ����ǰ�еĲ����ͷ���
//��ÿ��С����б��� ����ǰ�з���ǰ������  ����Ϊ����λ����ż�� ���Բ�����һ��С���� ������ײ������С��
//��K��С����� ���α���1-k-1��С�򣬿��Ƿ�����ײ�ģ�����ȡ�����ǵķ���
int main() {
	int n, l, t;
	vector<int>sphere;

	cin >> n >> l >> t;
	bool arr[n];//������
	memset(arr, true, sizeof(arr));

	for (int i = 0; i < n; i++) {

		int value;
		cin >> value;
		sphere.push_back(value);
	}

	while (t--) {
		for (int i = 0; i < n; i++) {

			if (arr[i])
				sphere[i]++;
			else
				sphere[i]--;

			if (sphere[i] > l) {
				sphere[i] = l - 1;
				arr[i] = !arr[i];
			}

			if (sphere[i] < 0) {
				arr[i] = !arr[i];
				sphere[i] = 1;
			}

			for (int j = 0; j < i; j++) {

				if (sphere[j] == sphere[i]) {
					arr[i] = !arr[i];
					arr[j] = !arr[j];
					break;
				}
			}


		}


	}

	for (int i = 0; i < n; i++) {

		cout << sphere[i] << " ";

	}


	return 0;
}