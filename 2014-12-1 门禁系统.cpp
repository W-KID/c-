#include <iostream>
#include <vector>
using namespace std;

//���������ݺŴ�������
//�������һ��Ԫ�ؿ�ʼ����ʼһ��count=1����¼ͬһ��ݺų��ֵĴ������ٴ�0��ʼ����ֱ����ǰ��ݺ�֮ǰ��Ԫ�أ�ÿ������ͬһ����ݺţ�count+1��ѭ���������count
//���ڸտ�ʼ��һ��Ԫ��û��֮ǰ��Ԫ�أ�����Ƕ��ѭ�����һ���ж����� ֻ����Ų�Ϊ0�ҳ�������ͬ��Ԫ�ز�count+1
//�����֮���Ǳ���������ĳ��Ԫ�أ��ڶ����֮ǰ��Ԫ���ֽ�����һ�α���
int main() {
	vector <int>reader;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {

		int x;
		cin >> x;
		reader.push_back(x);
	}

//	vector<int>counts;

	for (int i = 0; i < n; i++) {

		int count = 1;

		for (int j = 0; j < i; j++) {

			if (reader[i] == reader[j] && i != 0)
				count++;
		}

		cout << count << " ";
	}

	return 0;
}