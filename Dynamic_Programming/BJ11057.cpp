//11057 ��������
//��ȭ���� ã�� ������ �������.
//dp[i][j]���� i�� �ڸ��� ,j�� ���ڸ�
//���� ���, dp[3][8]���� _ _ 8������ ���������� ���� = _ 8 8 + _ _ 7 
// _ 8 8 ������ ������ _ 8������ ������ ����.(if �������� ����)
//�׷��� ���� ��ȭ���� dp[i][j]=dp[i-1][j]+dp[i][j-1];
#include <iostream>
using namespace std;
int N, result, dp[1001][10];

int main() {
	scanf("%d", &N);
	for (int i = 0; i < 10; i++) {
		dp[1][i] = 1;
	}
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) dp[i][j] = dp[i - 1][j];
			else {
				dp[i][j] = (dp[i - 1][j] % 10007 + dp[i][j - 1] % 10007) % 10007;
			}
		}
	}
	for (int j = 0; j < 10; j++) {
		result = (result % 10007 + dp[N][j] % 10007) % 10007;
	}
	printf("%d\n", result);
	return 0;
}
