#include <iostream>
#include <vector>
using namespace std;

//将输入的身份号存入数组
//从数组第一个元素开始，初始一个count=1，记录同一身份号出现的次数，再从0开始遍历直到当前身份号之前的元素，每遍历到同一个身份号，count+1，循环结束输出count
//由于刚开始第一个元素没有之前的元素，所以嵌套循环里加一个判断条件 只有序号不为0且出现了相同的元素才count+1
//简而言之就是遍历到数组某个元素，在对这个之前的元素又进行了一次遍历
int main() {
	vector <int>reader;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {

		int x;
		cin >> x;
		reader.push_back(x);
	}

//	vector<int>counts;

	for (int i = 0; i < n; i++) {

		int count = 1;

		for (int j = 0; j < i; j++) {

			if (reader[i] == reader[j] && i != 0)
				count++;
		}

		cout << count << " ";
	}

	return 0;
}