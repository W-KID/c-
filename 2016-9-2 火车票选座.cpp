#include <iostream>
using namespace std;
const int N = 20;
const int M = 5;







































//��һ�ַ���-��ά����˼·��
//��ʼһ��bool�������ڴ洢��λλ�ã���ʼֵΪfalse
//����һ������justify��x,arr[][5]�����ڴ���ÿ����Ҫ�������λƱ��
//�����ڲ� ����Ƕ��ѭ������ �ڵ�һ������У��������У�������һ��count��������ʣ��Ŀ���λ
//����������ٵڶ���ѭ������������λ��arr��Ϊ����ʣ����λ��count++��ֱ�������ڶ���ѭ��
//Ȼ���ж��Ƿ�ʣ����λ��count>=��Ҫռ����λ��������������ٽ��б���������ѭ��
//�ڵ�����ѭ����Ҫ���㰴�б�������С�ڵ�������������ұ�ռ��λ��ҪС�ڵ�����Ҫ����λ��
//��ѭ��������ǿ���λ�����ģ�����λռ�ˣ����������λ�ţ���ǰ���+����*5-1����Ȼ��ռ��λ����1
//ֱ��ռ��������Ҫ����λ������
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



//�ڶ��ַ�����һά����˼·��
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