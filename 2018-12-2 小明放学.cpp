#include <iostream>
using namespace std;
//思路
//此题的关键在于这里给的红绿灯时间是红绿的的剩余时间并且相对于最开始放学的时候，而不是过这个路口需要等待多少时间
//所以从一开始就要用一个sum数组来存储总时间（同时也方便更新当前红绿灯），然后没有红绿灯就直走
//有的话就可以先对总消耗时间取r+g+b的余，由sum1存储，方便更新红绿灯，
//在判断时 如果判断是黄灯的话 不仅要用计算当前所花时间，还要加上下一个红的时间
//在判断时会判断4次 以当前红灯剩余时间t为列，判断 是否小于红灯剩余时间。。。else if判断到是否小于总r+g+b
//因为t只是剩余时间，更新后可能刚好又更会当前状态
//最后输出sum


//如果发现是绿灯 则不用计算等待时间 但如果是黄灯，原本等待时间的前提下还要加上红灯的等待时间
//sum一定要定义为longlong类型，因为可以算一下，如果定义为int，显然有可能会超出内存要求的。
//0 红1 绿3 黄2
int main() {
	int r, y, g;
	cin >> r >> y >> g;
	int n, l, t;
	cin >> n;
	long long  sum = 0; //记录总共用了多少时间
	int sum1 = 0; //记录总时间取于红绿灯循环的时间，即不足一轮的时间，方便与红绿灯比较

	while (n--) {

		cin >> l >> t; //如果是红绿灯，这里输入的是当前红绿灯相对于小明放学开始的时候还剩多少秒

		if (l == 0) {
			sum += t;
		} else if (l == 1) {
			sum1 = sum % (r + y + g);

			if (sum1 < t)
				sum += t - sum1;
			else if (t <= sum1 && sum1 < t + g);
			else if (sum1 >= t + g && sum1 < t + g + y)
				sum += t + g + y + r - sum1;
			else if (sum1 >= t + g + y && sum1 < r + g + y)
				sum += r + g + y + t - sum1;

		} else if (l == 3) {
			sum1 = sum % (r + y + g);

			if (sum1 >= t && sum1 < t + y )
				sum += t + y - sum1 + r;
			else if (sum1 >= t + y && sum1 < t + y + r)
				sum += t + y + r - sum1;
			else if (sum1 >= t + y + r && sum1 < r + y + g)
				;
		} else if (l == 2) {
			sum1 = sum % (r + y + g);

			if (sum1 < t) {
				sum += t - sum1 + r;
			} else if (sum1 >= t && sum1 < t + r)
				sum += t + r - sum1;
			else if (sum1 >= t + r && sum1 < t + r + g);
			else if (sum1 >= t + r + g && sum1 < r + g + y)
				sum += t + r + g + y - sum1 + r;
		}
	}

	cout << sum;

	return 0;
}