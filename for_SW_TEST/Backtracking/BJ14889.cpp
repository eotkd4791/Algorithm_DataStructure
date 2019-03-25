/*
===============================
   BOJ14889 ��ŸƮ�� ��ũ
===============================
///////////////////////////////
BOJ �����̰� ���� ���ִ� ����
SW �丮��� ���� ��������.
result1,result2�� 0����
�ʱ�ȭ���� �ʾƼ� ��� Ʋ�ȴ�.
///////////////////////////////
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#define h N/2
using namespace std;

const int INF = 0xFFFFFFF;
int N;
int S[22][22];
bool check[22];
int MIN = INF;

void recur(int idx, int cnt) {
	if (cnt == h) {
		int result1 = 0;
		int result2 = 0;
	
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (i == j) continue;
				if (check[i] && check[j]) {
					result1 += S[i][j];
				}
				if (!check[i] && !check[j]) {
					result2 += S[i][j];
				}
				
			}
		}
		int ans = abs(result1 - result2);
		MIN = min(MIN, ans);
		return;
		
	}
	for (int i = idx; i <= N; i++) {
		if (!check[i]) {
			check[i] = 1;
			recur(i + 1, cnt + 1);
			check[i] = 0;
		}
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &S[i][j]);
		}
	}
	recur(1, 0);
	printf("%d\n", MIN);
	return 0;
}