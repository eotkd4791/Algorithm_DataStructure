/*
=========================
      SW1952 ������
=========================

//////////////////////////////////////
1���̿�ǰ� 1���̿�� ��, �ּڰ��� �Ǵ�
����� dp�� ������ ��, �����̿�ǰ��� ������
���ϸ鼭 ���� �ּڰ��� dp�� ä��������.
���������� 1�� �̿�ǰ� dp[11]���� ���Ͽ�
�ּڰ��� �Ǵ� ���� ����Ͽ���.
//////////////////////////////////////
*/

#include <iostream>
#include <algorithm>
using namespace std;

int T, N;
int cost[4];
int month[12];
int mprice[12];
int dp[12];

int main() {
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		for (int i = 0; i < 4; i++) scanf("%d", &cost[i]);
		for (int i = 0; i < 12; i++) scanf("%d", &month[i]);
		for (int i = 0; i < 12; i++) {
			mprice[i] = min(cost[1], cost[0] * month[i]);
		}
		dp[0] = mprice[0];
		for (int i = 1; i < 12; i++) {
			if (i < 2) dp[i] = dp[i - 1] + mprice[i];
			else {
				dp[i] = min(mprice[i]+dp[i-1], cost[2] + dp[i - 3]);
			}
		}
		int MIN = min(dp[11], cost[3]);
		printf("#%d %d\n", t, MIN);
	}
}