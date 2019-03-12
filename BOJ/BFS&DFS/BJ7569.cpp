/*
============================================
               BOJ7569 �丶��2
============================================

++++++++++++++++++++++++++++++++++++++++++++
3���� �迭�� ���� �ذ��߰�, ť ���� ��
�� �ϳ� ���߷��� �Ǽ��ߴ�.
�׸��� BFS�� ������ growth�� 0�� ������
-1�� ��ȯ�϶�� �ߴµ� ground�� growth��
��� 0�� �� -1�� ��ȯ�ؾ� �ϴ� ������ Ʋ�ȴ�.
�������� �� �����ؼ� �Ǽ��� �ٿ��߰ڴ�.
++++++++++++++++++++++++++++++++++++++++++++
*/
#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int M, N, H;
int box[101][101][101]; //�Է¹޴� �迭
int growth[101][101][101];//�丶�� ��ǥ���� ��¥�� ��Ÿ���� �迭
queue<pair<pair<int, int>,int >> q;
int dx[6] = { 0,0,0,0,-1,1 };
int dy[6] = { -1,1,0,0,0,0 };
int dz[6] = { 0,0,-1,1,0,0 };//�� �� �� �� �� �� ��
int day;//�丶�� �ʹ� ��¥, ť�� �ѹ��� Ǫ���ϴ� �׷��� �ѹ���(BFS�� ����)

void BFS() {
	int lev = growth[q.front().first.first][q.front().first.second][q.front().second];
	while (!q.empty()) {
		int ox = q.front().first.first;
		int oy = q.front().first.second;
		int oz = q.front().second;
		q.pop();

		if (lev < growth[ox][oy][oz]) {
			day++;
			lev++;
		}


		for (int i = 0; i < 6; i++) {
			int nx = ox + dx[i];
			int ny = oy + dy[i];
			int nz = oz + dz[i];

			if (0 <= nx && nx < N && M > ny && ny >= 0 && 0 <= nz && nz < H && box[nx][ny][nz] == 0 && growth[nx][ny][nz] == 0) {
				box[nx][ny][nz] = box[ox][oy][oz];
				growth[nx][ny][nz] = day + 1;
				q.push(make_pair(make_pair(nx, ny), nz));
			}
		}
	}
}

int main() {
	scanf("%d%d%d", &M, &N, &H);
	for (int h = 0; h < H; h++) {
		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {
				scanf("%d", &box[n][m][h]);
				if (box[n][m][h] == 1) {
					q.push(make_pair(make_pair(n, m), h));//�ٸ������ó�� break�� �ʿ䰡 ����.
				}
			}
		}
	}

	BFS();
	for (int h = 0; h < H; h++) {
		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {
				if (growth[n][m][h] == 0 && box[n][m][h]==0) {
					day = -1;
				}//0 ��, BFS���Ŀ� �� ���� �丶�䰡 ������ -1 ����ϰ� ���α׷� ����
			}
		}
	}
	printf("%d\n", day);
	return 0;
}