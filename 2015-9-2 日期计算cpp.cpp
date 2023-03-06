#include <iostream>
#include <vector>
using namespace std;

//注意 判断 x大于a 且小于b  不能直接a<x<b 必须 x>a&&x<b
//思路：
//可以先把每个月（包括前面所有月）的总天数算出来依次存储到数组中
//然后用输入的天数与数组中的相邻两个月依次比较 ，找出符合的月份（一月需要单独判断，如果判断一月，则直接输出一月和输入的天数）
//然后再用天数减去前一个月的总天数得出的就是这个月的具体第几天
int sum(int month, int year) {
	int x1 = 31, x3 = 31, x4 = 30, x5 = 31, x6 = 30, x7 = 31, x8 = 31, x9 = 30, x10 = 31, x11 = 30, x12 = 31;
	int x2;

	if ((!(year % 4) && (year % 100)) || !(year % 400))
		x2 = 29;
	else
		x2 = 28;

	int all = 0;
	vector <int> mon = {x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12};

	for (int i = month; i > 0; i--) {

		all += mon[i - 1];
	}

	return all;

};

int main() {
	vector<int> mon_all;
	int y, d;
	cin >> y >> d;

	for (int i = 0; i < 12; i++) {

		mon_all.push_back(sum(i + 1, y));
	}

	int month;
	int day;

	for (int j = 1; j <= 12; j++) {

		if (d > 0 && d <= mon_all[0]) {
			month = 1;
			day = d;
			break;
		} else if (d > mon_all[j - 1] && d <= mon_all[j ]) {
			month = j + 1;
			day = d - mon_all[j - 1];
			break;
		}
	}

	cout << month << endl << day;
}