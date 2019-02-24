/*scanf�� �Է� ���� ��, ���⳪ �ٹٲ� ���� �Է��� �ޱ� ������
"%1d"���·� �Է��� �޾Ҵ�.
cnt�� �� ���� ��, ans�� �� �������� �������� ����.
ans�� result�迭�� �����Ͽ� ���� ����Ͽ���.
ans�� Ž���� �����ϸ鼭 ī��Ʈ�� �ؾ� �ùٸ� ���� ���´�. �׷���
1�� �ʱ�ȭ�� �ߴ�.
*/
#include <iostream>
#include <algorithm>
using namespace std;
int N, field[30][30], check[30][30], cnt, ans=1, result[9000];
int dr[4] = { 0,0,1,-1 };
int dc[4] = { -1,1,0,0 };

void DFS(int x, int y) {
	check[x][y] = 1;
	for (int n = 0; n < 4; n++) {
		int rx = x + dr[n];
		int cy = y + dc[n];
		if (rx >= 0 && cy >= 0 && rx < N && cy < N && check[rx][cy] == 0 && field[rx][cy] == 1) {
			check[rx][cy] = 1;
			DFS(rx, cy);
			ans++;
		}
	}

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
				DFS(i, j);
				result[cnt] = ans;
				cnt++;
				ans = 1;
				
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