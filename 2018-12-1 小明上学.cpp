#include <iostream>
using namespace std;



//0 ºì1 ÂÌ3 »Æ2
int main() {
	int r, y, g;
	cin >> r >> y >> g;
	int n;
	cin >> n;
	int sum = 0;

	while (n--) {
		int l, d;
		cin >> l >> d;

		if (l == 0) {
			sum += d;
		} else if (l == 1) {
			sum += d;
		} else if (l == 2) {
			sum += d;
			sum += r;
		}

		
	}
cout << sum;

	return 0;
}