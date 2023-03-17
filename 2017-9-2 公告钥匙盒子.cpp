
#include <deque>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
//思路：看到这道题目我第一想法就是暴力求解，事实证明暴力求解确实是对的。
//确定了大体思路就要想用什么样的数据结构，题目以时刻为主线，由同一时刻的先还还是先借，还和借的序列，
//我们确定用Set来存储时刻，set有自动排序且没有重复的特征，用vector来存储每次借或者还的事件，
//用数组来存储钥匙的序列，将借或还的事件做成结构体，包含时刻和相关钥匙id，
//将Vector排序，然后通过遍历Set，找到对应时刻的事件，进行事件的发生处理即可。
struct T {
	int _time;//拿or还钥匙的时刻
	int id;//钥匙编号
};

bool cmp(T a, T b) { //时间优先，再次序号
	if (a._time == b._time)
		return a.id < b.id;
	return a._time < b._time;
}

set<int> Set;//时刻集合，自动排序
vector<T> ta;//拿钥匙序列
vector<T> re;//还钥匙的序列
int main() {
	int n, k;//n个挂钩,k个老师
	cin >> n >> k;

	while (k--) {
		int w, s, c;
		cin >> w >> s >>
		    c; //w,s,c    w钥匙编号、s开始上课的时间和c上课的时长
		int h = s + c;//还钥匙的时间
		Set.insert(s);
		Set.insert(h);
		T t1;
		t1._time = s;
		t1.id = w;
		T r;
		r._time = h;
		r.id = w;
		ta.push_back(t1);
		re.push_back(r);
	}

	sort(ta.begin(), ta.end(), cmp);
	sort(re.begin(), re.end(), cmp);
	int arr[n];//钥匙序列

	for (int i = 1; i <= n; i++) {

		arr[i] = i; //初始化钥匙序列
	}

	for (set<int>::iterator it = Set.begin(); it != Set.end(); it++) { //对于同一个set时刻，先处理还钥匙的

		for (vector<T>::iterator it1 = re.begin(); it1 != re.end(); it1++) {

			if (it1->_time == *it) {
				for (int i = 1; i <= n; i++) {

					if (arr[i] == 0) {
						arr[i] = it1->id;
						break;//注意，每次只处理一个事件，少了break会出错，导致后面的0都被重复赋值
					}
				}
			} else if (it1->_time > *it)
				break;

		}/*cout<<"还完之后的序列是";for(int i=1;i<=n;i++){cout<<arr[i]<<" "; //初始化钥匙序列 }cout<<endl;*/

		for (
		    vector<T>::iterator it1 = ta.begin(); it1 != ta.end(); it1++) {

			if (it1->_time == *it) {
				for (int i = 1; i <= n; i++) {

					if (arr[i] == it1->id) {
						arr[i] = 0;
						break;
					}
				}
			} else if (it1->_time > *it)
				break;
		}/*cout<<"借完之后的序列是";for(int i=1;i<=n;i++){cout<<arr[i]<<" ";}cout<<endl;*/
	}

	for (int i = 1; i <= n; i++)

		cout << arr[i] << " ";
	return 0;
}