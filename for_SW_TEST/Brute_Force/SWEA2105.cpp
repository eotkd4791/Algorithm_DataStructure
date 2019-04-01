//////////////////////////////////
/*
		SWEA2105 ����Ʈ ī��
								*/
//////////////////////////////////

/*
���� ������� BFS�� Ǯ������
check�迭�� ��� �ʱ�ȭ���� ����
��͸� �̿��� DFS������� Ǯ����.
ios::sync_with_stdio(0);
cin.tie(0);
�� �ڵ带 �� ���� ���� Ʋ���� ���Դ�.
*/

#include <iostream>
#include <cstring>
using namespace std;

int T, N;
int field[22][22];
//bool checkp[22][22];
bool checkd[101]; //������ ����Ʈ ī���ȣ ǥ��
int dx[4] = { 1,1,-1,-1 };//����, ����, �»�, ���
int dy[4] = { 1,-1,-1,1 };

//dir[0](1,1)���� [1](1,-1)����  [2](-1,-1)�»� [3](-1,1)��� �ð�������� �����س���.
//�ݽð質 �ð質 �Ȱ���
//����0 -> ����0,����1    ����1->����1,�»�2  �»�2->�»�2,���3   ���3->���3,����0
int sx, sy;
int dir;
int MAX;

bool OOB(int x, int y) {
	if (0 <= x && x < N && N > y && y >= 0)
		return true;
	return false;
}

void DFS(int x, int y, int dir, int cnt) {
	if (x == sx && y == sy && cnt>1) {
		if (MAX < cnt) MAX = cnt;
		return;
	}
	for (int n = 0; n < 2; n++) {
		int nx = x + dx[dir + n];//n�� 0�϶��� ���� �ִ� ����, 1�϶��� �ð�������� �ѹ� ������.
		int ny = y + dy[dir + n];
		if (OOB(nx, ny) && !checkd[field[nx][ny]]) {
			checkd[field[nx][ny]] = 1;
			DFS(nx, ny, dir + n, cnt + 1);
			checkd[field[nx][ny]] = 0;
		}//��͸� �̿��ϰ� �ٽ� ���ƿö� check������ �ʱ�ȭ���ش�.
		else if (nx == sx && ny == sy) DFS(nx, ny, dir + n, cnt + 1);
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> field[i][j];
			}
		}
		MAX = -1;
		memset(checkd, 0, sizeof(checkd));

		for (int i = 0; i < N - 1; i++) {
			for (int j = 1; j < N - 1; j++) {
				sx = i; sy = j;
				checkd[field[i][j]] = 1;
				DFS(i, j, 0, 0);
				checkd[field[i][j]] = 0;
			}
		}
		cout << '#' << t << ' ' << MAX << '\n';
	}
	return 0;
}