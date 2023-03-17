#include <iostream>
#include <vector>
using namespace std;

struct node {
	int time;
	int need;
};
vector<node> plan;

int main() {
	int n, m, k;
	cin >> n >> m >> k;//出行计划个数n，查询个数m，等待核酸检测结果所需时间k

	for (int i = 0; i < n; i++) {

		int time, need;

		cin >> time >> need;
		plan.push_back({time, need});
	}

	int find;

	for (int j = 0; j < m; j++) {

		cin >> find;
		int count = 0;
		int start = find + k;

		for (int i = 0; i < plan.size(); i++) {

			if (plan[i].time >= start)
				if (plan[i].time - plan[i].need < start ) {
					count++;
				}
		}

		cout << count << endl;
	}


	return 0;
}