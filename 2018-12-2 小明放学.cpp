#include <iostream>
using namespace std;
//˼·
//����Ĺؼ�����������ĺ��̵�ʱ���Ǻ��̵ĵ�ʣ��ʱ�䲢��������ʼ��ѧ��ʱ�򣬶����ǹ����·����Ҫ�ȴ�����ʱ��
//���Դ�һ��ʼ��Ҫ��һ��sum�������洢��ʱ�䣨ͬʱҲ������µ�ǰ���̵ƣ���Ȼ��û�к��̵ƾ�ֱ��
//�еĻ��Ϳ����ȶ�������ʱ��ȡr+g+b���࣬��sum1�洢��������º��̵ƣ�
//���ж�ʱ ����ж��ǻƵƵĻ� ����Ҫ�ü��㵱ǰ����ʱ�䣬��Ҫ������һ�����ʱ��
//���ж�ʱ���ж�4�� �Ե�ǰ���ʣ��ʱ��tΪ�У��ж� �Ƿ�С�ں��ʣ��ʱ�䡣����else if�жϵ��Ƿ�С����r+g+b
//��Ϊtֻ��ʣ��ʱ�䣬���º���ܸպ��ָ��ᵱǰ״̬
//������sum


//����������̵� ���ü���ȴ�ʱ�� ������ǻƵƣ�ԭ���ȴ�ʱ���ǰ���»�Ҫ���Ϻ�Ƶĵȴ�ʱ��
//sumһ��Ҫ����Ϊlonglong���ͣ���Ϊ������һ�£��������Ϊint����Ȼ�п��ܻᳬ���ڴ�Ҫ��ġ�
//0 ��1 ��3 ��2
int main() {
	int r, y, g;
	cin >> r >> y >> g;
	int n, l, t;
	cin >> n;
	long long  sum = 0; //��¼�ܹ����˶���ʱ��
	int sum1 = 0; //��¼��ʱ��ȡ�ں��̵�ѭ����ʱ�䣬������һ�ֵ�ʱ�䣬��������̵ƱȽ�

	while (n--) {

		cin >> l >> t; //����Ǻ��̵ƣ�����������ǵ�ǰ���̵������С����ѧ��ʼ��ʱ��ʣ������

		if (l == 0) {
			sum += t;
		} else if (l == 1) {
			sum1 = sum % (r + y + g);

			if (sum1 < t)
				sum += t - sum1;
			else if (t <= sum1 && sum1 < t + g);
			else if (sum1 >= t + g && sum1 < t + g + y)
				sum += t + g + y + r - sum1;
			else if (sum1 >= t + g + y && sum1 < r + g + y)
				sum += r + g + y + t - sum1;

		} else if (l == 3) {
			sum1 = sum % (r + y + g);

			if (sum1 >= t && sum1 < t + y )
				sum += t + y - sum1 + r;
			else if (sum1 >= t + y && sum1 < t + y + r)
				sum += t + y + r - sum1;
			else if (sum1 >= t + y + r && sum1 < r + y + g)
				;
		} else if (l == 2) {
			sum1 = sum % (r + y + g);

			if (sum1 < t) {
				sum += t - sum1 + r;
			} else if (sum1 >= t && sum1 < t + r)
				sum += t + r - sum1;
			else if (sum1 >= t + r && sum1 < t + r + g);
			else if (sum1 >= t + r + g && sum1 < r + g + y)
				sum += t + r + g + y - sum1 + r;
		}
	}

	cout << sum;

	return 0;
}