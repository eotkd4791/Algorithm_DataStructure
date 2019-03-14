/*
===========================
     SW Expert Academy
     ������ 3 6 9 ����
===========================

+++++++++++++++++++++++++++
���������� ������, ��ŷ������
�ڵ带 �����ϴ�,
�ڸ��� �����ϰ� 3,6,9�� ������
cnt++�ϰ� while(cnt--)�ؼ�
�ڼ��� ����ϰ�
while�� ���������鼭 " "���
if (!cnt) cnt�� 0�϶���
�״�� ���� ����ϰ� �ϴ�
���̵� �־���.
�𸣴� �Լ� rep�� ���̴�.

===========================
*/

#include <iostream>
#include <cstring>
using namespace std;

int N,arr[5];

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		int tmp = i;
		int cnt = 0;
		memset(arr, 0, sizeof(arr));
		for (int j = 1; j <= 4; j++) {
			arr[j] = tmp % 10;
			tmp /= 10;
		}
		for (int j = 1; j <= 4; j++) {
			if (arr[j] == 3 || arr[j] == 6 || arr[j] == 9) printf("-");
		}
		for (int j = 1; j <= 4; j++) {
			if (arr[j] == 3 || arr[j] == 6 || arr[j] == 9) cnt++;
		}
		if (cnt > 0) {
			printf(" ");
			continue;
		}
		if (cnt == 0) {
			printf("%d ", i);
		}
	}
	return 0;
}