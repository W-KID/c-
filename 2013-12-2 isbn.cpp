#include <iostream>
#include <vector>
#include <string>
using namespace std;

//字符只能占一个位置 char c='10' 错误
//思路:
//由字符串s接收输入 然后遍历字符串s，同时每遍历一个看他是否在间隔符位置 不在则将他加入vector数组isbn中（只存9位数子，最后一个不存）
//并且用每一位有效数字算total总值，直到s前一位（因为最后一个是用于判断的）
//将total取余计算
//再判断total是否等于10 是则将c赋值为为'X'（c用于一会置换s中的最后一位），不是则将total转为字符型赋值给c
//最后判断c是否等于s最后一位的判断符 否则替换s中最后一位 输出s 是则输出"Right"
//
int main() {
	string s;
	vector<int> isbn;
	int total = 0;
	char c;
	cin >> s;

	for (int i = 0, j = 0; i < s.length() - 1; i++) {

		if (i != 1 && i != 5 && i != 11) {
			isbn.push_back(s[i] - '0');
			total += isbn[j] * (j + 1);
			j++;
		}

	}

	total = total % 11 ;

//	vector<int>::iterator it;
//	it = isbn.end()- 1;
//	cout << s[12] << endl;
//	cout << total << endl;
	c = total == 10 ? 'X' : total + '0';

	if (c != s[12]) {
		s[12] = c;
		cout << s << endl;;
	} else
		cout << "Right";
	return 0;
}