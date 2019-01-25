/*LIS(Longest Increasing Subsequence)���������κм�����
�������̰� ���� ���� ���������� N�� 1�϶��� ������ ����Ƽ�
��� Ʋ�ȴ�. �� ���� ��°�� �����ؾ߰ڴ�.*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, MAX = 0;
	int arr[1001] = {};
	int dp[1001] = {};

	dp[0] = 1;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	if (N == 1) {
		printf("1\n");
		return 0;
	}
	for (int i = 1; i < N; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
			}
		}
		MAX = max(MAX, dp[i]);
	}
	printf("%d\n", MAX);
	return 0;
}