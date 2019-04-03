
/////////////////////////////////////
/*
         BOJ16235 ���� ����ũ
                                   */
/////////////////////////////////////
/*
�������ϴ� �ùķ��̼� ��������.
4���� �迭�� ����鼭 ���̸� �ε�����
�����س��µ�, k���� ���� for���� ���鼭
�������� �ٲ�� ���� �������� ���ߴ�.

���� �״� ����, ���� �Դ� ������ ���� 
tmp�迭�� �����ؼ� ���� �� �������ִ�
������ Ǯ����.

�� ���� ���� �ܿ��� ���ʴ�� ���� ������
ó�� �ڵ带 © ��, ������ ���� ������ 
���� ���� ���� ����� ���ǹ��ߴ�.

3���� �迭�� �̿��Ͽ� [x][y][����]=���� ����
�� Ǯ����.

�������� Ű�� �� �ִ� �������� ���� Ǯ����߰ڴ�.
*/
#include <iostream>
using namespace std;

int N, M, K;
int field[12][12][1020];
int A[12][12];
int tmp[12][12][1020];

bool OOB(int x, int y) {
	if (1 <= x && x <= N && N >= y && y >= 1) 
		return true;
	return false;
}

int main() {
	scanf("%d%d%d", &N, &M, &K);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &A[i][j]);
			field[i][j][0] = 5;
		}
	}
	int x, y, z = 0;
	for (int i = 1; i <= M; i++) {
		scanf("%d%d%d", &x, &y, &z);
		field[x][y][z]++;
	}
	while (K--) {
		//��
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				for (int k = 1; k < 1020; k++) {
					if (field[i][j][k] != 0) {
						while (field[i][j][k] > 0) {
							if (field[i][j][0] >= k) {
								field[i][j][0] -= k;
								tmp[i][j][k + 1]++;
								field[i][j][k]--;
							}
							else {
								tmp[i][j][0] += (field[i][j][k] * (k / 2));
								field[i][j][k] = 0;
							}
						}
					}
				}
			}
		}
		//����-������ ������ �� ��п� ���ϱ�
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				for (int k = 0; k < 1020; k++) {
					field[i][j][k] += tmp[i][j][k];
					tmp[i][j][k] = 0;
				}
			}
		}

		//����
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				int k = 5;
				while (k < 1020) {
					int dx[8] = { 0,0,1,-1,1,1,-1 ,-1 };
					int dy[8] = { 1,-1,0,0,1,-1,-1, 1 };
					if (field[i][j][k] != 0) {
						for (int n = 0; n < 8; n++) {
							int nx = i + dx[n];
							int ny = j + dy[n];
							if (OOB(nx, ny)) field[nx][ny][1] += field[i][j][k];
						}
					}
					k += 5;
				}
			}
		}




		//�ܿ�
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				field[i][j][0] += A[i][j];
			}
		}
	}

	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k < 1020; k++) {
				//if (field[i][j][k] != 0) ������ ������ �Ȱ���.
				cnt += field[i][j][k];
			}
		}
	}
	printf("%d\n", cnt);
	return 0;
}