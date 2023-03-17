//˼·
//����һ�����齫����Կ��ֵ�洢
//Ȼ��������ʦ�Ľ軹�¼��洢����ʱ�������� Կ�׵ĵ�λ�ã�����ʱ���Ǳ������������Ψһ�ģ����Կ�����set���洢ʱ�̣�
//��ͬһʱ�̣��Ȼ���裬������Ҫ����vector���ֱ�洢�����¼��ͽ���¼�
//���軹���¼����ɽṹ�壬�ں�Կ��idֵ��ʱ��timeֵ
//��vector���򣬰�ʱ������ͬһʱ�䰴�¼�Կ��idֵ��С�������򣩣�����������������ܸ�ϵͳʱ�������С����ƥ��Ƚϣ�
//����ʱ�䣬�����Ȼ���� ������Ƕѭ�� �ȱ�������vector�������껹���¼���Ȼ���������¼���
//����Ƕ������������ ��Ҫ���ĵ�ֻ��Կ�׵�ֵ����Ϊʱ����Ψһ������ģ�
//��������±����洢Կ�׵����飬���Կ��ֵ

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
			} else if (r_iter->time > (*iter))//���п��п��� ��Ϊ������ֻ���vector���¼������˵�ǰϵͳʱ��
				break;//��û��Ҫ����ѭ��ƥ���ˣ���Ϊvector��ʱ�����ź���ģ�����Ҳ������ƥ��ɹ������ͬ��

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