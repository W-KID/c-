#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//˼·��
//��һ�ַ�����ͨ�����н��⣬����ѭ������;�Ѷ�ͷԪ��push׷�ӵ���β��Ȼ��Ѷ�ͷԪ��pop���ˣ�
//����frontָ����Զָ���һ��Ԫ�أ�pop��Զ����һ��Ԫ�أ�push��Զ������β׷��Ԫ��
int main() {
	int n, k;
	cin >> n >> k;
	queue<int> child;
	int all_index = 1;

	for (int i = 1; i <= n; i++) {

		child.push(i);
	}

	while (child.size() > 1) {
		if (!(all_index % k) || (all_index % 10 == k))
			child.pop();
		else {
			child.push(child.front());
			child.pop();
		}

		all_index++;
	}

	cout << child.front();

	return 0;
}






//#include <iostream>
//#include <vector>
//using namespace std;
//
//struct node {
//	int index ;
//	bool pass = false;
//};
//
//int main() {
//
//	int n, k;
//	cin >> n >> k;
//	node child[n];
//
//	for (int i = 0; i < n; i++ ) {
//
//		child[i].index = i + 1;
//	}
//
//	int all_index = 1, exist = n;
//
//	for (int i = 0; i < n; i++) {
//
//		if (!child[i].pass) {
//			if (!(all_index % k) || (all_index % 10 == k)) {
//				exist--;
//				child[i].pass = true;
//			}
//
//			all_index++;
//		}
//
//
//
//		if (i == n - 1)
//			i = -1;
//
//		if (exist == 1)
//			break;
//	}
//
//	for (int i = 0; i < n; i++ ) {
//
//		if (!child[i].pass)
//			cout << child[i].index;
//	}
//
//
//	return 0;
//}
