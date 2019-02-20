/*BOJ 1926 �׸�
BFS�� �̿��� Flood fill����
queue���� pop�� �� ������ sum�� ���ϰ� MAX���� �����ߴ�.
queue�ʱ�ȭ�� �Ű��µ� ��ǻ� while����
Ż���Ϸ��� queue�� ����־�� �ϴϱ�...
�� field���� 0�� �κ��� ���� �ʱ� ���ؼ� ������ ���� �߰��ߴ�.*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

int n, m, field[501][501], check[501][501], cnt, sum, MAX;
int dr[4] = { 0,0,1,-1 };
int dc[4] = { -1,1,0,0 };

void BFS(int x, int y) {
	queue<pair<int, int>> q = {};
	check[x][y] = 1;
	q.push({ x,y });
	while (q.empty() == 0) {
		int xnow = q.front().first;
		int ynow = q.front().second;
		q.pop();
		sum++;
		for (int k = 0; k < 4; k++) {
			int rx = xnow + dr[k];
			int cy = ynow + dc[k];
			if (rx >= 0 && cy >= 0 && rx < n && cy < m && check[rx][cy] == 0 && field[rx][cy] == 1) {
				check[rx][cy] = 1;
				q.push({ rx,cy });
			}
		}
	}
	MAX = max(MAX, sum);
	sum = 0;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &field[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (check[i][j] == 0 && field[i][j] == 1) {
				BFS(i, j);
				cnt++;
			}
		}
	}
	printf("%d\n%d", cnt, MAX);
	return 0;
}