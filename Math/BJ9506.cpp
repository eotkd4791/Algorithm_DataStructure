/*ó���� sort�Լ��� �̿��ؼ� �ذ��Ϸ��ߴٰ� �ٽ� ������.
�迭 �ʱ�ȭ, ���ѷ��� Ż�����ǿ��� �Ǽ��ؼ� �ð��� ���� �ɷȴ�.*/
#include <iostream>
using namespace std;

int main() {
	int n = 0;
	int div,sum = 0;
	int arr[100000] = {};
	
	while (1) {
		scanf("%d", &n);
		if (n == -1) break;
		for (int i = 1; i < n; i++) {
			if (n % i == 0) {
 				div = i;
				arr[i] = div;
				sum += div;
			}
			else continue;
		}
		if (sum == n) {
			printf("%d = ", n);
			for (int i = 1; i < n; i++) {
				if (arr[i] == 0) continue;
				if (arr[i]==n/2) {
					printf("%d\n", arr[i]);
					continue;
				}
				if (arr[i] != 0) {
					printf("%d + ", arr[i]);
				}
			}
			div = 0;
			sum = 0;
			for (int i = 0; i < 100000; i++)
				arr[i] = 0;
		}
		else printf("%d is NOT perfect.\n", n);
		div = 0;
		sum = 0;
		for (int i = 0; i < 100000; i++)
			arr[i] = 0;
	}
	return 0;
}
