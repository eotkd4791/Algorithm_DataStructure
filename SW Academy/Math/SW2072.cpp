#include <stdio.h>

int main() {
	int T;//�׽�Ʈ���̽��� ����
	int arr[10] = {};
	int sum = 0; //������ ����

	scanf("%d", &T);

	for (int i = 1; i <= T; i++) {
		for (int j = 0; j < 10; j++) {

			scanf("%d", &arr[j]);

			if (arr[j] % 2 == 1)
				sum = sum + arr[j];

		}


		printf("#%d %d\n", i, sum);
		sum = 0;
	}
	return 0;
}

