//////////////////////////////////////
/*
		   BOJ17143 ���ÿ�

//////////////////////////////////////
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100
using namespace std;

int R, C, M;
int sum;
int dx[] = { 0,-1,1,0,0 };
int dy[] = { 0,0,0,1,-1 };

typedef struct {
	int X;//x
	int Y;//y
	int Sp;//�ӵ� 
	int D;//���� 
	int Sz;//ũ�� 
	int num;//��� ��ȣ 
	bool alive;//��Ҵ��� �׾����� 
}shark;
vector<shark> v;//����� ������ �����Ѵ�. 
vector<int> map[MAX][MAX];//��� ��ȣ�� �����Ѵ�. 

bool compare(int a, int b) {//ũ�Ⱑ ū �� ������ ���� ���� 
	if (v[a].Sz > v[b].Sz)
		return true;
	return false;
}
bool check() {//�ʿ� �� ���ٸ� false ��ȯ(�ݺ��� Ż�� ����) 
	for (int i = 0; i < v.size(); i++) {
        if (v[i].alive == true) return true;
    }
    return false;
}

void fishing(int yy) {//���ò��� �� ��� ũ�⸦ sum�� ���Ѵ�. 
	for(int xx=0; xx<R; xx++) {
		if(map[xx][yy].size()==1) {
			sum += v[map[xx][yy][0]].Sz;
			v[map[xx][yy][0]].alive=false;//�� ���̰� 
			map[xx][yy].clear();//��ǥ �ʱ�ȭ�� ���ش�. 
			break;//�ݺ��� Ż��  �Ѹ����� �����ϱ� 
		}
	}
}

void movingshark() {
	for (int i = 0; i < v.size(); i++) {
		if (!v[i].alive) continue;
		int ox = v[i].X;
		int oy = v[i].Y;
		map[ox][oy].clear();//�� �ʿ��� �� ����� 
	}
	for (int i = 0; i < v.size(); i++) {//�����ִ� ����� ��ǥ�� �����ͼ�  
		if (!v[i].alive) continue;
		int xx = v[i].X;
		int yy = v[i].Y;
		int dd = v[i].D;
		int ss = v[i].Sp;

		if (dd == 1 || dd == 2) {//���� �� �� 
			for (int j = 0; j < ss; j++) {
				int nx = xx + dx[dd];
				int ny = yy + dy[dd];
				if (nx < 0) {
					dd = 2;
					nx += 2;
				}
				if (nx >= R) {
					dd = 1;
					nx -= 2;
				}
				xx = nx;
				yy = ny;
			}
		}
		else if (dd == 3 || dd == 4) {//���� �� ��	 
			for (int j = 0; j < ss; j++) {
				int nx = xx + dx[dd];
				int ny = yy + dy[dd];
				if (ny < 0) {
					dd = 3;
					ny += 2;
				}
				if (ny >= C) {
					dd = 4;
					ny -= 2;
				}
				xx = nx;
				yy = ny;
			}
		}
		v[i].X = xx;
		v[i].Y = yy;
		v[i].D = dd;
		map[xx][yy].push_back(i);
	}
}

void killshark() {//�� ��ǥ�� �� ����������� ũ�Ⱑ ���� ū �� ������ �� �� �Ծ������. 
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j].size() > 1) {
				sort(map[i][j].begin(), map[i][j].end(), compare);//ũ�Ⱑ ���� ū �� MAP[X][Y][0]�� ��ġ�ϵ��� ���� 
				int ll = map[i][j][0];//
				for (int k = 1; k < map[i][j].size(); k++) {
					v[map[i][j][k]].alive = false;
					v[map[i][j][k]].X = -1;
					v[map[i][j][k]].Y = -1;
				}
				map[i][j].clear();
				map[i][j].push_back(v[ll].num);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> R >> C >> M;

	if (M == 0) {//��� ���� 0���� �϶� 0��� �� ����
		cout << '0';
		return 0;
	}
	int r, c, s, d, z;
	for (int m = 0; m < M; m++) {//�Է�
		shark aa;
		cin >> r >> c >> s >> d >> z;
		r -= 1;
		c -= 1;
		aa.X = r;
		aa.Y = c;
		aa.Sp = s;
		aa.D = d;
		aa.Sz = z;
		aa.num = m;
		aa.alive = true;
		v.push_back(aa);
		map[r][c].push_back(m);
	}
	for (int i = 0; i < C; i++) {//���ò� ��->�̵�
		if(!check()) break;
		fishing(i);
		movingshark();
		killshark();
	}
	cout << sum;
	return 0;
}
