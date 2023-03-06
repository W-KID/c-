#include <iostream>
using namespace std;
const int N = 15;
const int M = 10;

struct nodes {
	int x;
	int y;
} node[4];

int arr[N][M] = {0};
int index_Arr[4][4];

int main() {

	for (int i = 0; i < N; i++)

		for (int j = 0; j < M; j++) {

			cin >> arr[i][j];
		}

	int count = 0;

	for (int i = 0; i < 4; i++)

		for (int j = 0; j < 4; j++) {

			cin >> index_Arr[i][j];

			if (index_Arr[i][j]) {
				node[count].x = i;
				node[count].y = j;
				count++;
			}

		}

	int y;
	cin >> y;

	for (int i = 0; i < 4; i++)

		node[i].y = node[i].y + y - 1;

	for (int i = 0; i <= N; i++)

		if (i + node[3].x > N - 1 || arr[i + node[0].x][node[0].y] || arr[i + node[1].x][node[1].y]
		        || arr[i + node[2].x][node[2].y] || arr[i + node[3].x][node[3].y]) {
			i--;
			arr[i + node[0].x][node[0].y] = 1;
			arr[i + node[1].x][node[1].y] = 1;
			arr[i + node[2].x][node[2].y] = 1;
			arr[i + node[3].x][node[3].y] = 1;
			break;
		}

	for (int i = 0; i < N; i++) {

		for (int j = 0; j < M; j++)

			cout << arr[i][j] << " ";
		cout << endl;
	}

	return 0;
}