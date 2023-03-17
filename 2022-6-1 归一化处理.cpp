#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	double arr[n];
	double sum = 0.0, sum1 = 0.0;

	for (int i = 0; i < n; i++) {

		cin >> arr[i];
		sum += arr[i];
	}

	double aver = sum / n;
	double da, f[n];

	for (int i = 0; i < n; i++) {

		sum1 += pow((arr[i] - aver), 2);
	}

	da = sum1 / n;

	for (int i = 0; i < n; i++) {

		f[i] = (arr[i] - aver) / sqrt(da);
		cout << f[i] << endl;
	}

	return 0;
}
