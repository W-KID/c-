#include <iostream>
using namespace std;
#include <vector>

//用循环将每个输入的数存入vector数组中，然后利用双重嵌套循环把每个数取出来和剩下的比较 看是否有相反数；
int main() {
	int a, num, count = 0;
	vector<int>all;
	cin >> num;

	for (int i = 0; i < num; i++) {

		cin >> a;
		all.push_back(a);
	}

	for (int i = 0; i < num; i++) {

		for (int j = i + 1; j < num; j++) {

			if (all[i] == (-all[j])) {
				count++;
				break;
			}
		}
	}

	cout << count << endl;
	return 0;
}