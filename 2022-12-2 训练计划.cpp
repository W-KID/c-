#include <iostream>
#include <vector>
using namespace std;

struct train {
	int index;
	int depend = 0; //ÿ��ѵ����Ŀ��������Ŀ
	int day;//ÿ��ѵ����Ŀ����Ҫ������
	int early = 0;
	int last = 0;
	bool last_change = false;
} training[100];

int main() {
	int n, m;// n���������Ļ������,mѵ����Ŀ��������
	cin >> n >> m;

	for (int i = 0; i < m; i++ ) {

		training[i].index = i + 1;//ѵ����Ŀ�ı��
		int value;
		cin >> value;
		training[i].depend = value; //ÿ��ѵ����Ŀ��������Ŀ

		if (value == 0)
			training[i].early = 1;



	}

	for (int i = 0; i < m; i++) {

		int value2;
		cin >> value2;
		training[i].day = value2; //ÿ��ѵ����Ŀ����Ҫ������
	}

	bool la = true;

	for (int i = 0; i < m; i++)  {

		if (training[i].depend != 0) {
			training[i].early = training[training[i].depend - 1].early + training[training[i].depend - 1].day ;

			if (training[i].early + training[i].day - 1 > n)
				la = false;

		}
	}

	training[m - 1].last = n - training[m - 1].day + 1;

	for (int i = m - 1; i >= 0; i--) {

		if (training[i].last_change == false)
			training[i].last = n - training[i].day + 1;

		if (training[i].depend != 0) {
			training[training[i].depend].last = min(training[training[i].depend].last,
			                                        training[i].last - training[training[i].depend].day);
			training[i].last_change = true;
		}

		if (training[i].last < 1)
			la = false;
	}


	for (int j = 0; j < m; j++) {

		cout << training[j].early << " ";

	}

	cout << endl;

	if (la) {
		for (int j = 0; j < m; j++) {

			cout << training[j].last << " ";


		}


	}

	return 0;
}