#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

//原理：
//利用变长数组vector来存储输入的值，map来存储每个值出现的个数
//在循环里 先将value赋值给vector，然后在map中查vector是否存在 存在则将他的个数加一 否则赋1
//在之后将他的值与最大出现次数比较（因为默认为0，所以第一个数的次数必定比他大，一定在第一次循环后变为最大次数）大则将它赋为最大次数max_num,他的value值赋给max_value
int main() {
	int num, value, max_value, max_num = 0;
	vector<int>number;
	map<int, int>counts;
	cin >> num;

	for (int i = 0; i < num; i++) {

		cin >> value;
		number.push_back(value);

//		if (counts.find(key) != counts.end()) 这样写好一些 看他找键值对是否找到末尾了 是则表示没有这个键值
		if (counts.count(value) > 0) {
			counts[value]++;
		} else
			counts[value] = 1;

		if (counts[value] > max_num || (counts[value] == max_num && value < max_value)) {
			max_value = value;
			max_num = counts[value];
		}
	}

	cout << max_value << endl;
//	cout << max_value << "出现次数" << max_num << endl;
	return 0;
}