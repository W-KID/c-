#include <iostream>
#include <map>
#include <string.h>
using namespace std;

//˼·
//�ؼ����� Ӧ�����ж�yֵ���������������Ƿ���ڣ�Ȼ���ٴ�xֵ������x��y��ȵ����
int main() {
	int n, k;
	cin >> n >> k;
	bool arr[n + 1] = {false};
	arr[0] = true;
	int count = 0;

	for (int i = 0; i < k; i++) {

		int x, y;
		cin >> x >> y;


		if (arr[y] == false) {
			count++;
		}


		arr[x] = true;
	}

	cout << count;

	return 0;
}