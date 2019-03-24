/*
===================================
  BOJ2961 �����̰� ���� ���ִ� ����
===================================

////////////////////////////////////////////////////////////////////
1���� �̴� ����� ������ ~ N������ �̴� ����� ���� �����Լ��� ����߰�
�����Լ��� ��°��� ���� Ƚ���� ����� �ߴ�.
stn�� �̾ƾ��ϴ� ������.
cnt�� ���� ���ݱ��� ���� ����
/////////////////////////////////////////////////////////////////////
*/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

const int INF = 0xFFFFFFF;
int N;
int ech; //stn��ŭ �̾Ƽ� ����� Ƚ���� ���� ��, ������°��� �������� stn+1�ؼ� ������ +1�Ѵ�.
int s[11], b[11];
int MIN = INF;
bool pick[11];

int cb(int n, int k) {
	int dp[11][11] = {};
	int &ret = dp[n][k];
	if (k == 1) return n;
	if (n == k) return 1;
	if (k == 0) return 1;
	if (ret > 0) return ret;
	ret = 0;
	ret = cb(n - 1, k - 1) + cb(n - 1, k);
	return ret;
}//���� �Լ��� ���� ����� �� �̾Ƽ� �̾ƾ� �Ǵ� ���� ���� �ø��� 

void recur(int idx, int cnt, int stn) {//�ߺ����ϱ� ���� �ε��� ǥ��, �ߺ����� �̱����� �迭,���ݱ��� ���� ��
	long long ans = 0;

	if (cnt == stn) {
		long long res = 1, reb = 0;
		ech++;
		for (int i = 1; i <= N; i++) {
			if (pick[i]) {
				res *= s[i];
				reb += b[i];
			}
		}
		
		ans = abs(res - reb);
		if (MIN > ans) MIN = ans;


		int C = cb(N, stn);
		if (ech == C) {
			ech = 0;
			memset(pick, 0, sizeof(pick));
			recur(1, 0, stn + 1);
		}
		return;
	}

	for (int i = idx; i <= N; i++) {
		if (!pick[i]) {
			pick[i] = 1;
			recur(i + 1, cnt + 1, stn);
			pick[i] = 0;
		}
	}

}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d%d", &s[i], &b[i]);
	}
	recur(1, 0, 1);
	printf("%d\n", MIN);
	return 0;
}