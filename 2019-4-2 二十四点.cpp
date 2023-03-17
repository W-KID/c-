#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <map>
using namespace std;
//ԭ��һ��ջ�����֣�һ��ջ������

//ע��numberջ��Ԫ��ȡ��������ʱ ��һ��ȡ������Ӧ���ǳ������ڶ�������Ϊ������
//�������ַ���ʱ ���Բ���vector<string>(n,string)����һ��vector���� ���г���Ϊn������Ϊstring

int calculate(int a, int b, char c) {
	switch (c) {
		case '+':
			return a + b;

		case '-':
			return a - b;

		case 'x':
			return a * b;

		case '/':
			return a / b;
	}
}

int main() {
	int n, x1;
	cin >> n;
	map<char, int> index;
	index['+'] = 1;
	index['-'] = 1;
	index['x'] = 2;
	index['/'] = 2;
	int num1, num2;
	char opera;
	vector<string>all(n, string());//ʲô����Ϊn��ÿ��ֵ��string������Ϊ�յ�vector��ά���飻

	for (int i = 0; i < n; i++) {//���������ַ�����all vector������

		string value;
		cin >> value;
		all.push_back(value)
		cin.get();
	}

	for (int k = 0; k < n; k++) { //ѭ������δ����



		stack<int>number; //ջnuber�洢����
		stack<char>opr;//ջopr�洢����
		string arr = all[k];//����vector�е�stringԪ��
		int sum1 = 0;//sum1Ϊ���ȼ��ߵ�����õ��Ľ�� ������push��numberջ��

		for (int i = 0; i < 7; i++) {//�����ַ�����

			if (arr[i] >= '0' && arr[i] <= '9') { //���Ϊ���֣���תΪ���ַ���numberջ��
				number.push(arr[i] - '0');

			} else if (arr[i] == '+' || arr[i] == '-' || arr[i] == 'x' || arr[i] == '/') {//����� + - x /�����opr��
				if (opr.size() == 0) //���Ϊ�գ���push
					opr.push(arr[i]);
				else if (index[arr[i]] > index[opr.top()])//������ȼ�����ջ��Ԫ��Ҳpush
					opr.push(arr[i]);
				else if (index[arr[i]] <= index[opr.top()]) { //�����Ԫ�����ȼ�����ջ��Ԫ�أ�
					//����oprջ��Ԫ�س�վ��numberǰ����Ҳ��ջ���������㣬
					opera = opr.top();
					opr.pop();
					num1 = number.top();
					number.pop();
					num2 = number.top() ;
					number.pop();
					sum1 = calculate(num2, num1, opera);//�����push��number�У�Ȼ���ٽ��÷�����ջ
					number.push(sum1);
					opr.push(arr[i]);
				}
			}
		}

		while (number.size() > 1 && !opr.empty()) {//���nuberԪ��Ԫ�ش���1����opr��Ϊ��
			num1 = number.top();//��numberջǰ����ȡ���� ��oprջ��Ԫ�س���
			number.pop();
			num2 = number.top();
			number.pop();
			opera = opr.top();
			opr.pop();
			sum1 = calculate(num2, num1, opera);
			number.push(sum1);//���������ջ������sum+=sum1,��Ϊ����number��Ԫ��ֻ������ opr������ �����е�һ�������
			//���ֻ�Ӳ���ջ�Ļ������ճ� numberֻ��һ��Ԫ�أ�oprҲֻ��һ�����޷�����
		}


		if (number.top() == 24)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
		arr.clear();

	}

	return 0;
}
//2 8+4+3x4
