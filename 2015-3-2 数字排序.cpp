#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

//思路
//用map来存储数值和数值的个数，由于map的值如果是int类型 则每个map的key对应的value默认是0，则可以直接map[key]++
//将map存入vector中准备排序 由于map有两个值key和value 所以存入vector中应该以pair<int,int>来存储，同时初始vector的值
//即	vector<pair<int, int>> sort_vec(index_Arr.begin(), index_Arr.end());
//然后利用库函数<algorithm>中的sort函数进行排序
//按照题目的排序规则，重写排序规则 （返回值是true和false 由前一个和后一个比较得出）
bool cmp(pair<int, int> &a, pair<int, int> &b) {
	if (a.second != b.second) {
		return a.second > b.second;
	} else
		return a.first < b.first;
}

int main() {
	int n, x;
	map<int, int>::iterator it;
	cin >> n;
	map<int, int>index_Arr;

	for (int i = 0; i < n; i++) {

		cin >> x;
		it = index_Arr.find(x);

		if (it == index_Arr.end())
			index_Arr[x] = 1;
		else
			index_Arr[x]++;
	}

	vector<pair<int, int>> sort_vec(index_Arr.begin(), index_Arr.end());
	sort(sort_vec.begin(), sort_vec.end(), cmp);

	for (auto iter = sort_vec.begin(); iter != sort_vec.end(); iter++)

		cout << iter->first << " " << iter->second << endl;
	return 0;
}