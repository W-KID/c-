#include <iostream>
#include <vector>
using namespace std;
const int N = 1e6 + 10;

struct times {
	bool x = false;
	bool y = false;
} time[N];

int main() {
	int n;
	cin >> n;
	int m = 2;
	int max1 = 0, max2 = 0;

	for (int i = 0; i < n; i++) {

		int a1, b1;
		cin >> a1 >> b1;

		for (int j = a1; j < b1; j++)

			time[j].x = true;

	}

	for (int i = 0; i < n; i++) {

		int a2, b2;
		cin >> a2 >> b2;


		for (int j = a2; j < b2; j++)

			time[j].y = true;

	}

	int count = 0;

	for (int i = 0; i < N; i++) {

		if (time[i].y && time[i].x)
			count++;
	}

	cout << count;

	return 0;
}