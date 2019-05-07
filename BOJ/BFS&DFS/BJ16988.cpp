////////////////////////////////////////
/*
      BOJ16988 Baaaaaaaaaduk2 (Easy)

///////////////////////////////////////
����Ǿ� �ִ� ���� ���� �ѹ���,
�� ��ȣ���� �ϳ��� ��ǥ�� ��ǥ�� g���Ϳ�
Ǫ��.
��ĭ�� ��� ��ǥ�� v���Ϳ� �־ 
��͸� �̿��Ͽ� ������ ����.
g���Ϳ� ����� ��ǥ���� ����Ͽ� BFS�� ������,
������ ����(field[x][y]=2)�� l���Ϳ� Ǫ���Ѵ�.

0�� �����ٸ� l���Ϳ� q�� ���� �ݺ����� Ż���ϰ�,
������ g���Ϳ� ����Ǿ� �ִ� ��ǥ�� Ž���Ѵ�.

0�� ������ ������ l������ size�� cnt�� �������� ���Ѵ�.
(����5������ �ݷʰ� �߻��� �� �ֱ� ���� : �ٵϵ��� �� �κ��� ��ƴ ���� ��������,
�ٸ� �κп� ��ƴ�� �ִ� ��쿡 ��ƴ���� ���� �κ��� �� ���� ����ŭ�� cnt�� ���Խ�Ű�� ���ؼ�)
cnt�� MAX���� ũ�ٸ� ����, �ƴ϶�� ���ΰ� cnt =0���� �ʱ�ȭ
*/

#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m;
int cnt, MAX;
int field[20][20];
bool check[20][20];
const int dx[] = { 0,0,-1,1 };
const int dy[] = { 1,-1,0,0 };
vector<pair<int, int> > v;
vector<pair<int, int> > e;
vector<pair<int, int> > l;
vector<pair<int, int> > g;

bool OOB(int x, int y) {
	if (n > x && x >= 0 && 0 <= y && y < m)
		return true;
	return false;
}
void colouringBFS(int x, int y) {
	queue<pair<int, int> > q;
	q.push({ x,y });
	while (!q.empty()) {
		int ox = q.front().first;
		int oy = q.front().second;
		q.pop();
		for (int n = 0; n < 4; n++) {
			int nx = ox + dx[n];
			int ny = oy + dy[n];
			if (OOB(nx, ny) && field[ox][oy] == field[nx][ny] && !check[nx][ny]) {
				check[nx][ny] = 1;
				q.push({ nx,ny });
			}
		}
	}
}

void badukBFS() {
	queue<pair<int, int> > q;
	for (int i = 0; i < g.size(); i++) {
		q.push({ g[i].first,g[i].second });
		l.push_back({ g[i].first,g[i].second });
		check[g[i].first][g[i].second] = 1;
		while (!q.empty()) {
			int ox = q.front().first;
			int oy = q.front().second;
			q.pop();
			for (int n = 0; n < 4; n++) {
				int nx = ox + dx[n];
				int ny = oy + dy[n];
				if (OOB(nx, ny)) {
					if (field[nx][ny] == 2 && !check[nx][ny]) {
						check[nx][ny] = 1;
						q.push({ nx,ny });
						l.push_back({ nx,ny });
					}
					if (field[nx][ny] == 0) {
						while (!q.empty()) q.pop();
						l.clear();
						break;
					}
				}
			}
		}
		int sz = l.size();
		cnt += sz;
		l.clear();
	}
	MAX = max(MAX, cnt);
	cnt = 0;
}

void badukpick(int me) {
	if (me == 2) {
		badukBFS();
		memset(check, 0, sizeof(check));
		return;
	}
	for (int i = 0; i < v.size(); i++) {
		if (field[v[i].first][v[i].second] == 0) {
			field[v[i].first][v[i].second] = 1;
			badukpick(me + 1);
			field[v[i].first][v[i].second] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> field[i][j];
			if (field[i][j] == 0) v.push_back({ i,j });
			if (field[i][j] == 2) e.push_back({ i,j });
		}
	}
	for (int i = 0; i < e.size(); i++) {
		int ex = e[i].first;
		int ey = e[i].second;
		if (field[ex][ey] == 2 && !check[ex][ey]) {
			g.push_back({ ex,ey });
			colouringBFS(ex, ey);
		}
	}
	memset(check, 0, sizeof(check));
	badukpick(0);
	cout << MAX;
	return 0;
}