#include <iostream>
#include <string>
using namespace std;

//思路:
//用string存储输入的数 然后采取数组的方式遍历string 将每一位数加出来（string是一个字符串数组 每一位都是一个字符，用字符-‘0’可以将字符转化为数字 ）
int main() {
	string s;
	cin >> s;
	int sum = 0;

	for (int i = 0; i < s.length() ; i++) {

		int value = s[i] - '0';
		sum += value;
	}

	cout << sum;
	return 0;
}