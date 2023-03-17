#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int>shop;

	int n;
	cin >> n;
	int value;

	for (int i = 0; i < n; i++) {

		int x;
		cin >> x;
		shop.push_back(x);
	}

	for (int j = 0; j < n; j++) {

		if (j == 0)
			value = (shop[j] + shop[j + 1]) / 2;
		else if (j == n - 1)
			value = (shop[j - 1] + shop[j]) / 2;
		else
			value = (shop[j - 1] + shop[j] + shop[j + 1]) / 3;
		cout << value << " ";

	}

	return 0;
}