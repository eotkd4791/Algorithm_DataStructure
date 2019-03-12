//-�ٸ�����-
//N<=M ����nCk���� n=M,k=N
//���հ����� nPk/k!���� ����������, �ð��ʰ��� ����.
//�׷��� ���װ�� ������ �̿��� DP�� �����Ͽ���.

#include <iostream>
#include <cstring>
using namespace std;
int T, N, M;
long long dp[30][30];

long long cmb(int n, int k) {
	long long &ret = dp[n][k];
	if (k == 1) return n;
	if (n == k) return 1;
	if (k == 0) return 1;
	if (ret > 0) return ret;
	ret = 0;
	ret = cmb(n - 1, k - 1) + cmb(n - 1, k);
	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		scanf("%d%d", &N, &M);
		printf("%lld\n", cmb(M,N));
	}
	return 0;
}