
#include <deque>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
//˼·�����������Ŀ�ҵ�һ�뷨���Ǳ�����⣬��ʵ֤���������ȷʵ�ǶԵġ�
//ȷ���˴���˼·��Ҫ����ʲô�������ݽṹ����Ŀ��ʱ��Ϊ���ߣ���ͬһʱ�̵��Ȼ������Ƚ裬���ͽ�����У�
//����ȷ����Set���洢ʱ�̣�set���Զ�������û���ظ�����������vector���洢ÿ�ν���߻����¼���
//���������洢Կ�׵����У�����򻹵��¼����ɽṹ�壬����ʱ�̺����Կ��id��
//��Vector����Ȼ��ͨ������Set���ҵ���Ӧʱ�̵��¼��������¼��ķ��������ɡ�
struct T {
	int _time;//��or��Կ�׵�ʱ��
	int id;//Կ�ױ��
};

bool cmp(T a, T b) { //ʱ�����ȣ��ٴ����
	if (a._time == b._time)
		return a.id < b.id;
	return a._time < b._time;
}

set<int> Set;//ʱ�̼��ϣ��Զ�����
vector<T> ta;//��Կ������
vector<T> re;//��Կ�׵�����
int main() {
	int n, k;//n���ҹ�,k����ʦ
	cin >> n >> k;

	while (k--) {
		int w, s, c;
		cin >> w >> s >>
		    c; //w,s,c    wԿ�ױ�š�s��ʼ�Ͽε�ʱ���c�Ͽε�ʱ��
		int h = s + c;//��Կ�׵�ʱ��
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
	int arr[n];//Կ������

	for (int i = 1; i <= n; i++) {

		arr[i] = i; //��ʼ��Կ������
	}

	for (set<int>::iterator it = Set.begin(); it != Set.end(); it++) { //����ͬһ��setʱ�̣��ȴ���Կ�׵�

		for (vector<T>::iterator it1 = re.begin(); it1 != re.end(); it1++) {

			if (it1->_time == *it) {
				for (int i = 1; i <= n; i++) {

					if (arr[i] == 0) {
						arr[i] = it1->id;
						break;//ע�⣬ÿ��ֻ����һ���¼�������break��������º����0�����ظ���ֵ
					}
				}
			} else if (it1->_time > *it)
				break;

		}/*cout<<"����֮���������";for(int i=1;i<=n;i++){cout<<arr[i]<<" "; //��ʼ��Կ������ }cout<<endl;*/

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
		}/*cout<<"����֮���������";for(int i=1;i<=n;i++){cout<<arr[i]<<" ";}cout<<endl;*/
	}

	for (int i = 1; i <= n; i++)

		cout << arr[i] << " ";
	return 0;
}