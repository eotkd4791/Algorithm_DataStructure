///////////////////////////////////////
/*
		SWEA1861 ���簢�� ��

///////////////////////////////////////
1~n^2������ ���� �迭�� ����Ǵµ�
���� ��� 1���� 5���� ����Ǿ� �־
5���� Ž���� ������ 1~5������ ���ڴ� ���̻�
�� �ʿ䰡 ����.
(Ž���ص� �� ª�� ������ ����
������ ������...)
1������ �迭(arr)�� ���� �Է°�
���ÿ� arr�迭�� ä�� �ְ�,
���Ž������ ����Ǿ� �ִ� ���̸� ���ϰ�,
Ž���� ���� ������ ������ �ٽ� Ž���ϴ� �������
�����ߴ�.
����ȭ�� ���� ����غ� �������� ����־���.
*/
#include <iostream>
using namespace std;

int n;
int field[1001][1001];

typedef struct {
	int X;
	int Y;
}node;
node arr[10000010];
int st=1, M;
int tmp;
const int dx[] = { 0,0,1,-1 };
const int dy[] = { 1,-1,0,0 };

bool OOB(int x, int y) {
	if (0 <= x && x < n && n > y && y >= 0)
		return true;
	return false;
}

void recur(int x, int y, int stt, int len) {
	for (int n = 0; n < 4; n++) {
		int nx = x + dx[n];
		int ny = y + dy[n];
		if (OOB(nx, ny)) 
			if (field[x][y] + 1 == field[nx][ny]) {
				recur(nx, ny, stt, len + 1);
				break;
			}
		if (n == 3) {
			if (len > M) {
				M = len;
				st = stt;
			}
			if (len == M) {
				if (st > stt) st = stt;
			}
			tmp = stt + len;
		}
	}

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> field[i][j];
				node point = { i,j };
				arr[field[i][j]] = point;
			}
		}
		int last = 1;
		while (last < n*n) {
			recur(arr[last].X, arr[last].Y, last,1);
			last = tmp;
		}
		cout << '#' << t << ' ' << st << ' ' << M << '\n';
		st = 1;
		M = 0;
		
	}
	return 0;
}