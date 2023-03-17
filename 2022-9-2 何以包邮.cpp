#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
//ԭ��
//���õݹ��˼������ֵ����
//�����ҳ��ݹ�߽磬����ֵС�ڰ��ʼ۸�ʱ�����ݹ�
//��ΪҪ�ҵ�����Сֵ ���������ж��ְ�����Ͻ�������Է���ֵӦ�����ɵ�ǰ�ݹ����Сֵ�͹�����Сֵ�Ƚϳ�����Сֵ
//�ݹ��ʱ���ȥ���鲻���ظ����㣬���µĵݹ������λ��Ӧ���ǻ����ϴε�λ�ü�1

int min_sum(int sum, vector<int> &book, int x, int j) {
	if (sum < x)
		return 0;
	int sum1;

	for (int i = j; i < book.size(); i++) {

		if (sum - book[i] >= x) {
			sum1 = min_sum(sum - book[i], book, x, i + 1);
		}

	}

	return min(sum1, sum)

}



int main() {
	int n, x;
	cin >> n >> x;
	vector<int> book(n);
	int sum = 0;

	for (int i = 0; i < n; i++) {

		cin >> book[i];
		sum += book[i];
	}

	cout << min_sum(sum, book, x, 0);

	return 0;
}