#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <map>
using namespace std;
//原理一个栈存数字，一个栈存数组

//注意number栈中元素取出来运算时 第一个取出来的应该是除数，第二个才作为被除数
//输入多次字符串时 可以采用vector<string>(n,string)生成一个vector数组 其中长度为n，类型为string

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
	vector<string>all(n, string());//什么长度为n，每个值是string类型且为空的vector二维数组；

	for (int i = 0; i < n; i++) {//输入所有字符存在all vector数组里

		string value;
		cin >> value;
		all.push_back(value)
		cin.get();
	}

	for (int k = 0; k < n; k++) { //循环次数未结束



		stack<int>number; //栈nuber存储数字
		stack<char>opr;//栈opr存储符号
		string arr = all[k];//调用vector中的string元素
		int sum1 = 0;//sum1为优先级高的运算得到的结果 会重新push如number栈里

		for (int i = 0; i < 7; i++) {//遍历字符数组

			if (arr[i] >= '0' && arr[i] <= '9') { //如果为数字，则转为数字放入number栈中
				number.push(arr[i] - '0');

			} else if (arr[i] == '+' || arr[i] == '-' || arr[i] == 'x' || arr[i] == '/') {//如果是 + - x /则放入opr中
				if (opr.size() == 0) //如果为空，则push
					opr.push(arr[i]);
				else if (index[arr[i]] > index[opr.top()])//如果优先级高于栈顶元素也push
					opr.push(arr[i]);
				else if (index[arr[i]] <= index[opr.top()]) { //如果该元素优先级低于栈顶元素，
					//则先opr栈顶元素出站，number前两个也出栈，进行运算，
					opera = opr.top();
					opr.pop();
					num1 = number.top();
					number.pop();
					num2 = number.top() ;
					number.pop();
					sum1 = calculate(num2, num1, opera);//将结果push如number中，然后再将该符号入栈
					number.push(sum1);
					opr.push(arr[i]);
				}
			}
		}

		while (number.size() > 1 && !opr.empty()) {//如果nuber元素元素大于1，且opr不为空
			num1 = number.top();//则将number栈前两个取出来 和opr栈顶元素出来
			number.pop();
			num2 = number.top();
			number.pop();
			opera = opr.top();
			opr.pop();
			sum1 = calculate(num2, num1, opera);
			number.push(sum1);//这里必须入栈不能用sum+=sum1,因为可能number中元素只有三个 opr中两个 ，进行第一次运算后
			//如果只加不入栈的话，会照成 number只有一个元素，opr也只有一个，无法操作
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
