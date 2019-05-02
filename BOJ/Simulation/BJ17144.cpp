//////////////////////////////////
/*
      BOJ17144 �̼����� �ȳ�!
                                
//////////////////////////////////
========================================
�̼������� Ȯ��Ǵ� �κ��� sub�迭��
���� ������ ���� ���߿� �ѹ��� �������
�ϴ� ����̾���. (��������ũ�� ���)

����û���Ⱑ ������ ��ġ�� ��ǥ���� �����ϴ�
a1,a2�� ��ǥ�� Ǫ���Ҷ� r,c�� ���� ��������
�Ǽ��Ͽ� ���� �ɸ� �����̴�.
ó������ �Ĳ��ϰ� �����ϴ� ������ �⸣��
�������� �Ǽ��� �κ��� ã�Ƴ����� 
�ð��� �����ɷȴ�.
========================================

*/
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <cstring>
using namespace std;

int r, c, t;
int a[55][55];
int sub[55][55];
bool check[55][55];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
queue<pair<int, int> > q;
vector<int> ac;
vector<pair<int, int> > a1;
vector<pair<int, int> > a2;

bool OOB(int x, int y) {
	if (r > x && x >= 0 && 0 <= y && y < c) 
		return true;
	return false;
}

void dust_spread() {
	int dcnt=0;
	while (!q.empty()) {
		int ox = q.front().first;
		int oy = q.front().second;
		int tmp = a[ox][oy];
		check[ox][oy] = 1;
		q.pop();
		for (int n = 0; n < 4; n++) {
			int nx = ox + dx[n];
			int ny = oy + dy[n];
			if (OOB(nx, ny) && a[nx][ny] != -1) {
				dcnt++;
				sub[nx][ny] += tmp/5;
			}
		}
		a[ox][oy] = tmp - ((tmp / 5) * dcnt);
		dcnt = 0;
	}
}
void summm() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			a[i][j] += sub[i][j];
			sub[i][j] = 0;
		}
	}
}

void l_to_q() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (a[i][j] > 0) q.push({ i,j });
		}
	}
}

void air_cleaning1(int x, int y,int dir) {
	if (a[x][y] == -1) return;
	if (OOB(x, y)) a1.push_back({ x,y });
	int tmp = dir;
	if (x+dx[tmp] < 0 || y + dy[tmp] >= c || x + dx[tmp] > ac[0] ) {
		if (tmp == 3) tmp = 0;
		else tmp += 1;
	}
	air_cleaning1(x + dx[tmp], y + dy[tmp], tmp);
}

void air_cleaning2(int x, int y, int dir) {
	if (a[x][y] == -1) return;
	if(OOB(x,y)) a2.push_back({ x,y });
	int tmp = dir;
	if (x + dx[tmp]>=r || y + dy[tmp]>=c || x + dx[tmp] < ac[1]) {
		if (tmp == 0) tmp = 3;
		else tmp -= 1;
	}
	air_cleaning2(x + dx[tmp], y + dy[tmp],tmp);
}

void air_fresh() {
	a[a1[0].first][a1[0].second] = 0;
	int sz1 = a1.size();
	for (int i = 1; i < sz1; i++) {
		a[a1[i - 1].first][a1[i - 1].second] = a[a1[i].first][a1[i].second];
		if (i == sz1 - 1) a[a1[i].first][a1[i].second] = 0;
	}
	
	a[a2[0].first][a2[0].second] = 0;
	int sz2 = a2.size();
	for (int i = 1; i < sz2; i++) {
		a[a2[i - 1].first][a2[i - 1].second] = a[a2[i].first][a2[i].second];
		if (i == sz2 - 1) a[a2[i].first][a2[i].second] = 0;
	}
	
}

int dust_sum() {
	int sum = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (a[i][j] > 0) sum += a[i][j];
		}
	}
	return sum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> r >> c >> t;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> a[i][j];
			if (a[i][j] == -1) ac.push_back(i);
		}
	}
	air_cleaning1(ac[0] - 1, 0, 0);
	air_cleaning2(ac[1] + 1, 0, 2);

	while (t--) {
		l_to_q();
		dust_spread();
		summm();
		air_fresh();
	}
	
	int ans = dust_sum();
	cout << ans;
	return 0;
}