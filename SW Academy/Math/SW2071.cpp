/*SW2071 ��հ� ���ϱ� ����
�����Լ��� �̿��Ͽ� �ݿø��� �����ϰ�,
��½� �Ҽ��ڸ����� ����� ����Ͽ���.*/
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int T, arr[10]; double sum;
int main() {
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		for (int j = 0; j < 10; j++) {
			scanf("%d", &arr[j]);
			sum += arr[j];
		}
		printf("#%d %.0lf\n", i, floor((sum / 10) + 0.5));
		sum = 0;
		memset(arr, 0, sizeof(arr));
	}
	return 0;
}