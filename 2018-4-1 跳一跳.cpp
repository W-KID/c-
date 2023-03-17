#include <iostream>
#include <vector>
using namespace std;

//思路：主要是用一个pre存储上次的得分
int main() {
	vector<int> arr;
	int n;
	int score = 0;
	int pre = 0;
	cin >> n;
	int i = 0;

	while (n) {
		if (n == 1) {
			score += 1;
			pre = 1;
		} else if (n == 2 && (i == 0 || pre == 1)) {
			pre = 2;
			score += 2;
		} else {
			pre = pre + 2;
			score += pre;
		}

		cin >> n;
		i++;
	}


	cout << score;
	return 0;
}