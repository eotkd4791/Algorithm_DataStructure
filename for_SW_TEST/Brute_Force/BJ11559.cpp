//////////////////////////////////
/*
		BOJ11559 Puyo puyo
                               */
//////////////////////////////////
/*
queue�� �ϳ� �� ���� �������� ��带
push�س��� size()�Լ��� �̿��ؼ� 
������ ���� ������� Ǯ����.
*/

#include <iostream>
#include <queue>
#include <cstring>
#define H 12
#define W 6
using namespace std;

char field[14][8];
bool check[14][8];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

typedef struct {
	int x;
	int y;
	char colour;
}node;

queue<node> q;//����Ž�� ť
queue<node> ep;//������ ���(�ѿ�)�� �����ϴ� ť

bool OOB(int x, int y) {//���� �˻�
	if (H > x && x >= 0 && 0 <= y && y < W)
		return true;
	return false;
}


void BFS(node p) {
	q.push(p);
	while (!q.empty()) {
		int ox = q.front().x;
		int oy = q.front().y;
		char oc = q.front().colour;

		ep.push({ ox,oy,oc });//ť������ üũ�ϴ� ������ ����� �ѿ䰡 �پ��ִ��� Ȯ��.
		check[ox][oy] = 1;

		q.pop();

		for (int n = 0; n < 4; n++) {
			int nx = ox + dx[n];
			int ny = oy + dy[n];
			if (OOB(nx, ny) && field[nx][ny] == oc && !check[nx][ny]) {

				node point = { nx,ny,field[nx][ny] };
				q.push(point);
				check[nx][ny] = 1;
			}
		}
	}
}


void puyodrop() {//�ѿ� ����
	for (int j = 0; j < W; j++) {
		for (int i = 11; i >= 1; i--) {
			for (int k = i - 1; k >= 0; k--) {
				if (field[i][j] != '.') break;
				if (field[k][j] != '.') {
					field[i][j] = field[k][j];
					field[k][j] = '.';
					break;
				}
			}
		}
	}
}


int main() {

	
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> field[i][j];
		}
	}
	
	int chain = 0;//���� Ƚ��
	int checkbomb = 1;//���� Ƚ��

	while (checkbomb != 0) {
		checkbomb = 0;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (field[i][j] == '.') continue;
				else {
					if (!check[i][j]) {
						node point = { i, j, field[i][j] };
						BFS(point);

						if (ep.size() < 4) {//4������� ������ ť�� pop���Ѽ� ����.
							while (!ep.empty()) ep.pop();
						}

						else {//4������� ���ų� ������ '.'���� �ٲ���
							checkbomb++;
							while (!ep.empty()) {
								int xo = ep.front().x;
								int yo = ep.front().y;
								field[xo][yo] = '.';
								ep.pop();
							}
						}
					}
				}
			}
		}
		if (checkbomb > 0) chain++;
		puyodrop();
		memset(check, 0, sizeof(check));
	}
	cout << chain << '\n';
	return 0;
}