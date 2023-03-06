#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

//˼·
//��map���洢��ֵ����ֵ�ĸ���������map��ֵ�����int���� ��ÿ��map��key��Ӧ��valueĬ����0�������ֱ��map[key]++
//��map����vector��׼������ ����map������ֵkey��value ���Դ���vector��Ӧ����pair<int,int>���洢��ͬʱ��ʼvector��ֵ
//��	vector<pair<int, int>> sort_vec(index_Arr.begin(), index_Arr.end());
//Ȼ�����ÿ⺯��<algorithm>�е�sort������������
//������Ŀ�����������д������� ������ֵ��true��false ��ǰһ���ͺ�һ���Ƚϵó���
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