//思路
//先有一个数组将所有钥匙值存储
//然后将所有老师的借还事件存储，由时刻来决定 钥匙的的位置（由于时刻是必须是有序的且唯一的，所以可以用set来存储时刻）
//在同一时刻，先还后借，所以需要两个vector来分别存储还的事件和借的事件
//将借还的事件做成结构体，内含钥匙id值和时间time值
//将vector排序，按时间排序（同一时间按事件钥匙id值从小到大排序）（必须排序，排了序才能跟系统时间进行有小到大匹配比较）
//遍历时间，由于先还后借 所以内嵌循环 先遍历还的vector，处理完还的事件后，然后遍历借的事件。
//在内嵌的两个遍历中 需要更改的只有钥匙的值（因为时间是唯一且有序的）
//最后再重新遍历存储钥匙的数组，输出钥匙值

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
struct event {
	int id;
	int time;
};

cmp(event a, event b) {
	if (a.time == b.time)
		return a.id < b.id;
	else
		return a.time < b.time;
}
vector<event> bo_arr;
vector<event> re_arr;

int main() {
	int n, k;
	cin >> n >> k;
	set<int> times;
	int arr[n];

	for (int i = 0; i < n; i++)

		arr[i] = i + 1;

	while (k--) {
		int w, s, c, r;
		cin >> w >> s >> c;
		r = s + c;
		times.insert(s);
		times.insert(r);
		event bo;
		event re;
		bo.id = w;
		bo.time = s;
		bo_arr.push_back(bo);
		re.id = w;
		re.time = r;
		re_arr.push_back(re);
	}

	sort(bo_arr.begin(), bo_arr.end(), cmp);
	sort(re_arr.begin(), re_arr.end(), cmp);

	for (set<int>::iterator iter = times.begin(); iter != times.end(); iter++) {

		for (vector<event>::iterator r_iter = re_arr.begin(); r_iter != re_arr.end(); r_iter++) {

			if (r_iter->time == (*iter)) {
				for (int i = 0; i < n; i++) {

					if (!arr[i]) {
						arr[i] = r_iter->id;
						break;

					}

				}
			} else if (r_iter->time > (*iter))//这行可有可无 因为如果发现还的vector中事件大于了当前系统时间
				break;//就没必要继续循环匹配了（因为vector中时间是排好序的，后面也不可能匹配成功下面借同理）

		}

		for (vector<event>::iterator b_iter = bo_arr.begin(); b_iter != bo_arr.end(); b_iter++) {

			if (b_iter->time == (*iter)) {
				for (int i = 0; i < n; i++) {

					if (arr[i] == b_iter->id) {
						arr[i] = 0;
						break;
					}

				}
			} else if (b_iter->time > (*iter))
				break;
		}
	}

	for (int i = 0; i < n; i++)

		cout << arr[i] << " ";
	return 0;
}