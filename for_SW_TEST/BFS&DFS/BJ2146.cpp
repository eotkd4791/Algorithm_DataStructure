//BOJ2126 [�ٸ������]
/*board�迭�� ��ô����� �ϸ鼭 ���Ӱ� Ȯ���ϴ� �κ��� ������� �� ���� ��ȣ�� �ٿ��� �����Ѵ�.
check�迭�� �� ��ȣ �ű涧�� memoization�뵵�� ������,
memset�Լ��� �ʱ�ȭ�� �� ���Ŀ��� ��ô����� Ƚ���� ǥ���ϴ� �뵵�� ����.*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#define INF 999999
using namespace std;

int N, field[110][110], check[110][110], sub[110][110];
int num = 1, MIN = INF, ans;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
queue<pair<int, int> > Q;

void numbering_BFS(int x, int y) {
	queue<pair<int, int> > q = {};
	check[x][y] = 1;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		int xnow = q.front().first;
		int ynow = q.front().second;
		q.pop();
		sub[xnow][ynow] = num;
		for (int n = 0; n < 4; n++) {
			int nx = xnow + dx[n];
			int ny = ynow + dy[n];
			if (nx >= 0 && ny >= 0 && ny < N && nx < N &&check[nx][ny] == 0 && field[nx][ny] != 0) {
				check[nx][ny] = 1;
				q.push({ nx, ny });
			}
		}
	}
}

void BFSforFill() {//��ô��� / �̹� ť�� �� ���ֱ� ������ ���ڰ� �ʿ����
	int level = 0; //��ô��� Ƚ��
	int round = check[Q.front().first][Q.front().second]; // �����׷����� ���鼭 ++
	//check ť�� �� ���� �ε���(�ڸ���ȣ) //������ �����ϱ� ���ؼ�
	while (!Q.empty()) {
		int xnowfill = Q.front().first;
		int ynowfill = Q.front().second;

		if (check[xnowfill][ynowfill] > round) {
			level++; //��ô��� ���� ����� �Ѿ��
			round++; //���� ���� �׷� 
		}

		Q.pop();
		for (int n = 0; n < 4; n++) {
			int xnextfill = xnowfill + dx[n];
			int ynextfill = ynowfill + dy[n];

			if (sub[xnextfill][ynextfill] != 0 && check[xnextfill][ynextfill] != 0) {
				if (sub[xnowfill][ynowfill] != sub[xnextfill][ynextfill]) {
					ans = check[xnowfill][ynowfill] + check[xnextfill][ynextfill];
					MIN = min(MIN, ans);
				}
			}//�ּڰ� ���ϱ�

			if (xnextfill >= 0 && ynextfill >= 0 && xnextfill < N && ynextfill < N) {
				if (check[xnextfill][ynextfill] == 0 && sub[xnextfill][ynextfill] == 0) {
					check[xnextfill][ynextfill] = level + 1;//�̹� ���� ��ô���´ٴ� ��.
					sub[xnextfill][ynextfill] = sub[xnowfill][ynowfill];
					Q.push({ xnextfill, ynextfill });
				}
			}//���� ����
		}
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &field[i][j]);
		}
	}//�Է�

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (field[i][j] != 0 && check[i][j] == 0) {
				numbering_BFS(i, j);
				num++;
			}
		}
	}//�� ��ȣ�� ��ȣ �ű��
	memset(check, 0, sizeof(check));

	for (int i = 0; i < N; i++) {//3��for�� Ž���ϸ鼭 ������ �׵θ� �κе��� ť�� ó�� �ڴ� �ڵ�
		for (int j = 0; j < N; j++) {
			for (int n = 0; n < 4; n++) {
				int xnext = i + dx[n];
				int ynext = j + dy[n];
				if (sub[i][j] != 0 && sub[xnext][ynext] == 0) {//�ٴٰ� ���� �ִ��� Ȯ�� ��
					Q.push({ i, j });//�ٴٿ� ������ �׵θ��� ��ǥ�� ť�� ��� �ְ� ����.
					break;//�ΰ��� �ٴٿ� ������ ������ �ߺ����� ť�� �����ʱ� ���ؼ�
						  //�ѹ� ť�� ������ �ݺ����� ���������� �ϱ� ������ break�� �̿��Ͽ� for���ϳ��� ����ٰ� �ٽ� ����.
				}
			}
		}
	}//ť�� �� ������ �ѹ��� ����ִ� ���� - ���ÿ� ��ô�� �ؾ� ��Ȯ�� �Ÿ��� �� �� ����.

	BFSforFill();
	printf("%d\n", MIN);
	return 0;
}