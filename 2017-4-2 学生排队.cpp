#include <iostream>
using namespace std;

//�ص�ע������ ��һ�� ���ӳ�����ѧ�� ����������� ��������Ҫ�Ѷ�Ӧѧ�ŵ�����ҵ�
//��Ҫ����ͬһ���������� �ƣ�����

int main() {
	int num, k;
	cin >> num >> k;
	int arr[num + 1];

	for (int i = 1; i <= num; i++) {

		arr[i] = i;
	}

	for (int s = 0; s < k; s++) {

		int m, n, j, r;
		cin >> m >> n;

		for (int i = 1; i <= num; i++) {

			if (arr[i] == m)
				r = i;
		}



		if (n > 0) {
			arr[0] = m;

			for (j = r; j <  n + r; j++)

				arr[j] = arr[j + 1];

		} else if (n < 0) {
			arr[0] = m;

			for (j = r; j > r + n  ; j--)

				arr[j] = arr[j - 1];

		}

		arr[j] = arr[0];



	}

	for (int i = 1; i <= num; i++) {

		cout << arr[i] << " ";
	}




	return 0;
}
/*#include <iostream>
using namespace std;

//�ص�ע������ ��һ�� ���ӳ�����ѧ�� ����������� ��������Ҫ�Ѷ�Ӧѧ�ŵ�����ҵ�
//m��ǰ�ƶ�n��n<0������ʱ��,����һ��λ�ô��浱ǰλ����ǰ���� ֻ��������ǰλ��Ϊm+n-1֮ǰ����
// ��Ϊ�ø�ֵ����ǰһ����ֵ����ǰ �������ֻ���ߵ�ǰһ�� ��m+n+1
// m+n,m+n+1,m+n+2.....m-2,m-1,m;(n<0)
int main() {
	int num, k;
	cin >> num >> k;
	int arr[num + 1];

	for (int i = 1; i <= num; i++) {

		arr[i] = i;
	}

	for (int s = 0; s < k; s++) {

		int m, n, j, r;
		cin >> m >> n;

		for (int i = 1; i <= num; i++) {

			if (arr[i] == m)
				r = i;
		}



		if (n > 0) {
			for (j = r; j <  n + r ; j++)

				arr[j] = arr[j + 1];

		} else if (n < 0) {q

			for (j = r; j > r + n ; j--)

				arr[j] = arr[j - 1];

		}

		arr[r + n] = m ;



	}

	for (int i = 1; i <= num; i++) {

		cout << arr[i] << " ";
	}




	return 0;
}*/