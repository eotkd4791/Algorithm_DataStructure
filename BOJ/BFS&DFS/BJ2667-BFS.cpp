/*scanf�� �Է� ���� ��, ���⳪ �ٹٲ� ���� �Է��� �ޱ� ������
"%1d"���·� �Է��� �޾Ҵ�.
cnt�� �� ���� ��, ans�� �� �������� �������� ����.
ans�� result�迭�� �����Ͽ� ���� ����Ͽ���.
ans�� Ž���� �����ϸ鼭 ī��Ʈ�� �ؾ� �ùٸ� ���� ���´�. �׷���
1�� �ʱ�ȭ�� �ߴ�.
*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;
queue<pair<int, int>> q;
int N, field[30][30], check[30][30], cnt, ans=1, result[9000];
int dr[4] = { 0,0,1,-1 };
int dc[4] = { -1,1,0,0 };

void BFS(int x, int y) {
	check[x][y] = 1;
	q.push({ x,y });
	while (q.empty() == 0) {
		int xnow = q.front().first;
		int ynow = q.front().second;
		q.pop();
		for (int n = 0; n < 4; n++) {
			int rx = xnow + dr[n];
			int cy = ynow + dc[n];
			if (rx >= 0 && cy >= 0 && rx < N && cy < N && check[rx][cy] == 0 && field[rx][cy] == 1) {
				check[rx][cy] = 1;
				ans++;
				q.push({ rx,cy });
			}
		}
	}
	result[cnt] = ans;
	ans = 1;
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &field[i][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (check[i][j] == 0 && field[i][j] == 1) {
				BFS(i, j);
				cnt++;
			}
		}
	}
	printf("%d\n", cnt);
	sort(result, result + cnt);
	for (int k = 0; k < cnt; k++) {
		printf("%d\n", result[k]);
	}
	return 0;
}