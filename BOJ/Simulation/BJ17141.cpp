//////////////////////////////////
/*
		BOJ17141 ������2
	                       	    
//////////////////////////////////
�Է��� �����鼭 0�� ������ ����,
BFS�Լ� ������ while���� ���� Ƚ����
���� 0�� ������ ���ϴ� ����� �־���.

���̷����� �۶߸� ��, �� ���� ����(0)��
�ִٸ� �ٸ� ����� ���� �Ѿ��.
MIN���� ������ ���� �ʰ�, ���� �ÿ�
�ʱ�ȭ�س��� INF ���� ���ٸ�
-1�� ����ϰ� INF���� ���� �ʴٸ� 
MIN�� ����� ���� ����ϴ� ������
���α׷��� ®��.

�� �� �����ؼ� �˰����� �����ߴ���� 
���������� ����� ���� �� �ִ� ��������.
*/
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <utility>
#include <algorithm>
#define INF 987654321
using namespace std;

int n, m;
int field[55][55];
int sec[55][55];//�ð��� �����ϴ� �迭
int sub[55][55];//�ʵ�ī�� ����
bool check[55][55];//BFS���� ����.
bool ispicked[11];//���̷��� ������ �ߺ����� �� ǥ���س��� ť Ǫ���� �� ����.
const int dx[] = { 0,0,1,-1 };
const int dy[] = { 1,-1,0,0 };
typedef struct {
	int X;
	int Y;
}vrs;
queue<vrs> q;//���̷��� Ȯ��	
vector<pair<int, int> > v;//���̷��� ��ǥ����
vector<int> a; //������
int MIN = INF;


void mapcpy(int(*a)[55], int(*b)[55]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			b[i][j] = a[i][j];
		}
	}
}

bool OOB(int x, int y) {//������ �˻�
	if (0 <= x && x < n && n > y && y >= 0)
		return true;
	return false;
}

void virus_ready() {//���̷��� �۶߸� �غ��ϴ� �Լ�
	memset(sec, -1, sizeof(sec));
	memset(check, 0, sizeof(check));
	for (int i = 0; i < v.size(); i++) {
		if (ispicked[i]) {
			q.push({ v[i].first,v[i].second });
			check[v[i].first][v[i].second] = 1;
			sec[v[i].first][v[i].second] = 0;
		}
	}//���� ���̷����� ť�� Ǫ��, sec,check �ʱ�ȭ�ϱ�
}//���� ���̷����� �ִ� ���̸� ǥ���صα�.


bool virus_check() {//���̷��� �� ���� �� ��/�� Ȯ���ϴ� �Լ�
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (field[i][j] == 1) continue;
			if (field[i][j] == 0) {
				a.clear();
				return false;
			}
		}
	}
	return true;
}

void virus_spread() {//���̷��� �۶߸��� �Լ�
	int timee = 0;
	while (!q.empty()) {
		int ox = q.front().X;
		int oy = q.front().Y;
		field[ox][oy] = 2;
		timee = sec[ox][oy];
		q.pop();
		for (int n = 0; n < 4; n++) {
			int nx = ox + dx[n];
			int ny = oy + dy[n];
			if (OOB(nx, ny) && field[nx][ny] != 1 && !check[nx][ny]) {
				check[nx][ny] = 1;
				sec[nx][ny] = sec[ox][oy] + 1;
				q.push({ nx,ny });
				field[nx][ny] = 2;
			}
		}
	}
	if (virus_check()) {//���̷����� ���� ���� ���ٸ�
		MIN = min(MIN, timee);//MIN�� ����
	}
}

void whichvirus(int idx, int cnt) {//���̷��� �̴� �Լ�
	if (cnt == m) {
		virus_ready();
		virus_spread();
		mapcpy(sub, field);
		return;
	}
	for (int i = idx; i < v.size(); i++) {
		if (!ispicked[i]) {
			ispicked[i] = 1;
			whichvirus(i, cnt + 1);
			ispicked[i] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> field[i][j];
			if (field[i][j] == 2) v.push_back({ i,j });
		}
	}
	mapcpy(field, sub);
	whichvirus(0, 0);
	int ans = -1;//-1�� �ʱ�ȭ�Ͽ� �����Ѵ�.
	if (MIN != INF) ans = MIN;//MIN�� ���� ���ŵǾ��ٸ�(MIN�� INF�� �ٸ��ٸ�)
	cout << ans;//MIN���� ����Ѵ�. �ƴ϶�� �״�� -1�� ����Ѵ�.
	return 0;
}