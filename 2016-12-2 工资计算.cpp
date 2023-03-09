#include <iostream>
using namespace std;


















































//c++判断不能用0<A<10,要A>0&&A<10
//第一种解法用枚举所有可能来看税前值（因为题目讲了税前是整百 所以每次可以加100）
//int  calculate_money(int  money) {
//	int pre_money = 0;
//
//	if (money < 3600) {
//		pre_money = money;
//	}
//
//	else {
//		int now_money = 0;
//		float tax1 = 0.03, tax2 = 0.1, tax3 = 0.2, tax4 = 0.25, tax5 = 0.3, tax6 = 0.35, tax7 = 0.45;
//
//		for (int i = 3600; i <= 200000; i += 100) {
//
//			int excess = i - 3500;
//
//			if (0 < excess && excess <= 1500)
//				now_money = i - tax1 * excess;
//			else if (1500 < excess && excess <= 4500)
//				now_money = i - tax1 * 1500 - (excess - 1500) * tax2;
//			else if (4500 < excess && excess <= 9000)
//				now_money = i - tax1 * 1500 - 3000 * tax2 - (excess - 4500) * tax3;
//			else if (9000 < excess && excess <= 35000)
//				now_money = i - tax1 * 1500 - 3000 * tax2 - 4500 * tax3 - (excess - 9000) * tax4;
//			else if (35000 < excess && excess <= 55000)
//				now_money = i - tax1 * 1500 - 3000 * tax2 - 4500 * tax3 - 26000 * tax4 - (excess - 35000) * tax5;
//			else if (55000 < excess && excess <= 80000)
//				now_money = i - tax1 * 1500 - 3000 * tax2 - 4500 * tax3 - 26000 * tax4 - 20000 * tax5 - (excess - 55000) * tax6;
//			else if (80000 < excess )
//				now_money = i - tax1 * 1500 - 3000 * tax2 - 4500 * tax3 - 26000 * tax4 - 20000 * tax5 - 25000 * tax6 -
//				            (excess - 80000) * tax7;
//
//			if (now_money == money) {
//				pre_money = i;
//				break;
//			}
//		}
//	}
//
//
//	return pre_money;
//
//}
//
//int main() {
//	int  money;
//
//	cin >> money;
//	int  pre_money = calculate_money( money);
//	cout << pre_money << endl;
//	return 0;
//}
