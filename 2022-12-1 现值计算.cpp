#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main() {
	int n;
	double sum1 = 0.0, sum2 = 0.0;
	double earning, pay;
	double p;
	cin >> n >> p;
	int money[n + 1];

	for (int i = 0; i <= n; i++) {

		cin >> money[i];
	}

	int value = 0;

	for (int i = 0; i <= n; i++) {

		if (money[i] >= 0) {
			if (i > 0)
				sum1 += money[i] / pow(1 + p, i);
			else
				sum1 += money[i];
		} else {
			if (i > 0)
				sum2 += money[i] / pow(1 + p, i);
			else
				sum2 += money[i];
		}
	}

	cout << sum1 + sum2 << endl;

}
