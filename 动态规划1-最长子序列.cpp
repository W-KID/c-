#include <iostream>
using namespace std;
#include <math.h>
#include <vector>
//�ݹ���
/*int  maxlen(int x, vector<int> &arr ) {
	//ʹ�� int ������Ϊ������������,�޷���ȡ����ĳ��ȣ���Ϊ�����˻�����ָ�룬ָ��������׵�ַ��
//��ʹ��vector������vector.size���󳤶ȣ���Ҫʹ��vector&�������Ա��⸴��Ԫ�أ��������ܿ��������Ԫ�����ܴ������ܴ�
//����ʹ��const vector<int>&���Ա���Ԫ�ر�����
	if (x == arr.size() - 1)
		return 1;
	int max_len = 1;

	for (int i = x + 1; i < arr.size(); i++)

		if (arr[i] > arr[x])
			max_len = max(max_len, maxlen(i, arr) + 1);
	return max_len;
}*/

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);

	for (int i = 0; i < n; i++) {

		cin >> arr[i];
	}

	int count = 1;
	vector <int> dp(n, 1);


	for (int i = 1; i < n; i++) {

		for (int j = 0; j < i; j++) {

			if (arr[i] > arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
				count = max(count, dp[i]);
			}

		}
	}

//�ݹ���
//	count = maxlen(0, arr);

	cout << count;
	return 0;
}