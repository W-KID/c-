#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	int num, value, d_value, count = 0;
	vector<int> all;
	cin >> num;

	for (int i = 0; i < num; i++) {

		cin >> value;
		all.push_back(value);
	}

	for (int i = 0; i < num; i++) {

		for (int j = i + 1; j < num; j++) {

			d_value = all[i] - all[j];

			if (abs(d_value) == 1)
				count++;
		}
	}

	cout << count;
	return 0;
}